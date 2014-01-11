#!/usr/bin/perl -w
#
# Automate symbols file updates using packages from snapshot.debian.org.
#
# Required dependencies:
#
# libfile-slurp-perl libwww-perl liburi-perl
# libjson-perl libdpkg-perl libterm-prompt-perl
# devscripts dpkg dpkg-dev binutils
# diffutils patch coreutils
#
# Copyright (C) 2013-2014, Bas Couwenberg <sebastic@xs4all.nl>
# 
# This library is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself, either Perl version 5.8.5 or,
# at your option, any later version of Perl 5 you may have available.
#

use strict;
use File::Basename;
use File::Copy;
use File::Slurp;
use Getopt::Long qw(:config bundling no_ignore_case);
use HTTP::Request::Common;
use LWP::UserAgent;
use URI::Escape;
use JSON;
use Dpkg::Version;
use Term::Prompt;

$|=1;

my $package = 'libgdal1h';
my $pkgdir  = 'binary-'.$package.'/';

our $ua = LWP::UserAgent->new(agent => basename($0));

my %cfg = (
	    package    => $package,
	    version    => 'latest',
	    debsnap    => '/usr/bin/debsnap',
	    dpkgdeb    => '/usr/bin/dpkg-deb',
	    gensymbols => '/usr/bin/dpkg-gensymbols',
	    cppfilt    => '/usr/bin/c++filt',
	    objdump    => '/usr/bin/objdump',
	    diff       => '/usr/bin/diff',
	    patch      => '/usr/bin/patch',
	    sha512sum  => '/usr/bin/sha512sum',
	    pkgdir     => $pkgdir,
	    debian     => 'debian/',
	    force      => 0,
	    no_diff    => 0,
	    no_prompt  => 0,
	    yes        => 0,
	    verbose    => 0,
	    help       => 0,
	  );

my $result = GetOptions(
			 'p|package=s'    => \$cfg{package},
			 'V|version=s'    => \$cfg{version},
			 'S|debsnap=s'    => \$cfg{debsnap},
			 'E|dpkgdeb=s'    => \$cfg{dpkgdeb},
			 'G|gensymbols=s' => \$cfg{gensymbols},
			 'C|cppfilt=s'    => \$cfg{cppfilt},
			 'I|diff=s'       => \$cfg{diff},
			 'P|patch=s'      => \$cfg{patch},
			 'H|sha512sum=s'  => \$cfg{sha512sum},
			 'D|pkgdir=s'     => \$cfg{pkgdir},
			 'd|debian=s'     => \$cfg{debian},
			 'f|force'        => \$cfg{force},
			 'no-diff'        => \$cfg{no_diff},
			 'no-prompt'      => \$cfg{no_prompt},
			 'y|yes'          => \$cfg{yes},
			 'v|verbose'      => \$cfg{verbose},
			 'h|help'         => \$cfg{help},
		       );

if(!$result || $cfg{help} || !$cfg{package} || !$cfg{debian}) {
	print STDERR "\n" if(!$result);

	print "Usage: ". basename($0). " [OPTIONS]\n\n";
	print "Options:\n";
	print "-p, --package <NAME>      Library binary package name    ($cfg{package})\n";
	print "-V, --version <STRING>    Library binary package version ($cfg{version})\n";
	print "-S, --debsnap <PATH>      Path to debsnap                ($cfg{debsnap})\n";
	print "-E, --dpkgdeb <PATH>      Path to dpkg-deb               ($cfg{dpkgdeb})\n";
	print "-G, --gensymbols <PATH>   Path to dpkg-gensymbols        ($cfg{gensymbols})\n";
	print "-O, --objdump <PATH>      Path to objdump                ($cfg{objdump})\n";
	print "-C, --cppfilt <PATH>      Path to c++filt                ($cfg{cppfilt})\n";
	print "-I, --diff <PATH>         Path to diff                   ($cfg{diff})\n";
	print "-P, --patch <PATH>        Path to patch                  ($cfg{patch})\n";
	print "-H, --sha512sum <PATH>    Path to sha512sum              ($cfg{sha512sum})\n";
	print "-D, --pkgdir <PATH>       Path to downloaded packages    ($cfg{pkgdir})\n";
	print "-d, --debian <PATH>       Path to debian/ directory      ($cfg{debian})\n";
	print "    --no-diff             Don't display diff for new symbols files\n";
	print "    --no-prompt           Don't prompt to select symbols, update manually\n";
	print "-y, --yes                 Default to yes on prompts\n";
	print "-f, --force               Force writing into existing package directory\n";
	print "-v, --verbose             Enable verbose output\n";
	print "-h, --help                Display this usage information\n";

	exit 1;
}

if(!-x $cfg{debsnap}) {
	print "Error: Cannot execute debsnap: $cfg{debsnap}\n";
	print "Use --debsnap to override the path and/or install the devscripts package.\n";
	exit 1;
}
if(!-x $cfg{dpkgdeb}) {
	print "Error: Cannot execute dpkg-deb: $cfg{dpkgdeb}\n";
	print "Use --dpkg-deb to override the path and/or install the dpkg package.\n";
	exit 1;
}
if(!-x $cfg{gensymbols}) {
	print "Error: Cannot execute dpkg-gensymbols: $cfg{gensymbols}\n";
	print "Use --gensymbols to override the path and/or install the dpkg-dev package.\n";
	exit 1;
}
if(!-x $cfg{objdump}) {
	print "Error: Cannot execute objdump: $cfg{objdump}\n";
	print "Use --objdump to override the path and/or install the binutils package.\n";
	exit 1;
}
if(!-x $cfg{cppfilt}) {
	print "Error: Cannot execute c++filt: $cfg{cppfilt}\n";
	print "Use --cppfilt to override the path and/or install the binutils package.\n";
	exit 1;
}
if(!-x $cfg{diff}) {
	print "Error: Cannot execute diff: $cfg{diff}\n";
	print "Use --diff to override the path and/or install the diffutils package.\n";
	exit 1;
}
if(!-x $cfg{patch}) {
	print "Error: Cannot execute patch: $cfg{patch}\n";
	print "Use --patch to override the path and/or install the patch package.\n";
	exit 1;
}
if(!-x $cfg{sha512sum}) {
	print "Error: Cannot execute sha512sum: $cfg{sha512sum}\n";
	print "Use --sha512sum to override the path and/or install the coreutils package.\n";
	exit 1;
}

if(!-r $cfg{debian} || !-w $cfg{debian}) {
	print "Error: Cannot read/write directory: $cfg{debian}\n";
	exit 1;
}
if(-e $cfg{pkgdir} && !$cfg{force}) {
	print "Error: Directory already exists: $cfg{pkgdir} (use --force to override)\n";
	exit 1;
}

$cfg{debian} .= '/' if(substr($cfg{debian}, -1, 1) ne '/');
$cfg{pkgdir} .= '/' if(substr($cfg{pkgdir}, -1, 1) ne '/');

if(!$cfg{version} || $cfg{version} eq 'latest') {
	$cfg{version} = latest_snapshot();
	if(!$cfg{version}) {
		print "Error: Failed to determine latest version for: $cfg{package}\n";
		exit 1;
	}
}

my %symbols = ();

download_packages();
unpack_packages();
create_new_symbols();
create_patch_files();
patch_files();
split_files();
compare_symbols();
#create_complete_symbols();

################################################################################
# Subroutines

sub latest_snapshot {
	my $url = 'http://snapshot.debian.org/mr/binary/'.uri_escape($cfg{package}).'/';
	my $req = HTTP::Request->new(GET => $url);

	print "Retrieving URL: $url ... " if($cfg{verbose});
	my $res = $ua->request($req);
	if($res->is_success) {
		print "Success\n" if($cfg{verbose});

		my $json = $res->content;
		my $data = decode_json($json);

		my @versions = ();

		if($data->{result} && @{$data->{result}}) {
			print "Checking versions...\n" if($cfg{verbose});

			foreach my $v (sort { version_compare($a->{binary_version}, $b->{binary_version}) } @{$data->{result}}) {
				push @versions, $v->{binary_version};
			}

			print "Latest version: $versions[-1]\n" if($cfg{verbose});
		}

		print "\n" if($cfg{verbose});

		return $versions[-1];
	}
	else {
		print "Failed!\n" if($cfg{verbose});
		print "Error: Failed to retrieve URL! ($url)\n";
		print "HTTP Status: ".$res->code." ".$res->message."\n";

		return;
	}
}

sub download_packages {
	my $dir = $cfg{pkgdir};

	if(!-e $cfg{pkgdir} || $cfg{force}) {
		print "Downloading binary packages for: $cfg{package}, version: $cfg{version}, into: $cfg{pkgdir}\n";

		my @cmd = ();

		push @cmd, $cfg{debsnap};
		push @cmd, ('--destdir', $cfg{pkgdir});
		push @cmd, '--force'     if($cfg{force});
		push @cmd, '--verbose'   if($cfg{verbose});
		push @cmd, '--binary';
		push @cmd, $cfg{package};
		push @cmd, $cfg{version};

		print "Exec: @cmd\n" if($cfg{verbose});	

		my $exit = system(@cmd) >> 8;
		if($exit != 0) {
			print "Error: Command failed: @cmd ($exit)\n";
			exit $exit;
		}

		print "\n" if($cfg{verbose});
	}
	else {
		print "Error: Directory already exists: $dir (use --force to override)\n";
		return;
	}
}

sub unpack_packages {
	my $dir = $cfg{pkgdir};

	if(-r $dir && -w $dir) {
		print "Extracting downloaded packages...\n" if($cfg{verbose});

		opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir DIR) {
			# libgdal1h_1.10.1+dfsg-1_amd64.deb
			if(/^($cfg{package})_(\S+)_(\S+)\.deb$/) {
				my $pkg     = $1;
				my $version = $2;
				my $arch    = $3;
				my $file    = $dir.$_;
				my $pkgdir  = $dir.$pkg.'_'.$version.'_'.$arch.'/';

				next if($arch eq 'common');
				next if($version ne $cfg{version} && $cfg{version} ne 'all');
				next if(-r $pkgdir);

				# dpkg-deb -R libgdal1h_1.10.1+dfsg-1_amd64.deb libgdal1h_1.10.1+dfsg-1_amd64

				my @cmd = (
					    $cfg{dpkgdeb},
					    '--raw-extract',
					    $file,
					    $pkgdir,
					  );

				print "Exec: @cmd\n" if($cfg{verbose});

				my $exit = system(@cmd) >> 8;
				if($exit != 0) {
					print "Error: Command failed: @cmd ($exit)\n";
					exit $exit;
				}
			}	
		}
		closedir DIR;

		print "\n" if($cfg{verbose});
	}
	else {
		print "Error: Cannot read/write directory: $dir\n";
		return;
	}
}

sub create_complete_symbols {
	my $dir = $cfg{debian};

	if(-r $dir && -w $dir) {
		my $file = $dir.$cfg{package}.'.symbols.common';
		if(!-r $file) {
			print "Error: Cannot read common symbols file: $file\n";
			return;
		}

		print "Reading common symbols file: $file\n" if($cfg{verbose});

		my $common = read_file($file);

		opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir DIR) {
			# libgdal1h.symbols.amd64
			if(/^$cfg{package}.symbols.(\S+)$/) {
				my $arch = $1;

				next if($arch eq 'common');
				next if($arch =~ /\.(new|diff|filt|patch|c\+\+|common|complete)$/);
					
				my $file = $dir.$_;

				print "Reading $arch symbols file: $file\n" if($cfg{verbose});

				my $data = '';
				foreach(read_file($file)) {
					# #include "libgdal1h.symbols.common"
					if(/^#include "$cfg{package}.symbols.common"\s*$/) {
						print "Including common symbols\n" if($cfg{verbose});

						$data .= $common;
					}
					else {
						$data .= $_;
					}
				}

				$file .= '.complete';

				print "Saving complete symbols file: $file\n" if($cfg{verbose});

				write_file($file, $data);

				print "\n" if($cfg{verbose});
			}
		}
		closedir DIR;
	}
	else {
		print "Error: Cannot read/write directory: $dir\n";
		return;
	}
}

sub create_new_symbols {
	my $dir = $cfg{debian};

	if(-r $dir && -w $dir) {
		opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir DIR) {
			# libgdal1h.symbols.amd64
			if(/^($cfg{package}).symbols.(\S+)$/) {
				my $pkg  = $1;
				my $arch = $2;
				my $file = $dir.$_;

				next if($arch eq 'common');
				next if($arch =~ /\.(new|diff|filt|patch|c\+\+|common|complete)$/);

				my $version = '';
				my $library = '';

				my $pkg_dir = $cfg{pkgdir};
				if(-r $pkg_dir) {
					print "Looking for $arch under: $pkg_dir\n" if($cfg{verbose});

					opendir(PKGDIR, $pkg_dir) || die "Error: Cannot open package directory: $pkg_dir ($!)";
					while(readdir PKGDIR) {
						# libgdal1h_1.10.1+dfsg-1_armel
						if(/^${pkg}_(\S+?)_${arch}$/) {
							print "Package directory: $_\n" if($cfg{verbose});

							$version = $1;
							
							next if($version ne $cfg{version});

							$version =~ s/(\+dfsg)?-\d+$//;

							$library = find_library($pkg_dir.$_.'/usr/lib/');

							last;
						}
					}
					closedir PKGDIR;
				}
				else {
					print "Error: Cannot read package directory: $pkg_dir\n";
					print "\n" if($cfg{verbose});
					return;
				}

				if(!$version) {
					print "Error: Cannot determine package version!\n";
					print "\n" if($cfg{verbose});
					next;
				}

				if(!$library) {
					print "Error: Cannot find library!\n";
					print "\n" if($cfg{verbose});
					return;
				}

				my $output = $file.'.new';
				my $diff   = $file.'.diff';

				# dpkg-gensymbols -plibgdal1h -aarmel -v1.10.1 -Idebian/libgdal1h.symbols.armel -Odebian/libgdal1h.symbols.armel.new -ebinary-libgdal1h/libgdal1h_1.10.1+dfsg-1_armel/usr/lib/libgdal.so.1.17.1

				my @cmd = (
					    $cfg{gensymbols},
					    '-p'.$pkg,
					    '-a'.$arch,
					    '-v'.$version,
					    '-I'.$file,
					    '-O'.$output,
					    '-e'.$library,
					  );

				print "Exec: @cmd > $diff 2>&1\n" if($cfg{verbose});

				`@cmd > $diff 2>&1`;


				# cat debian/libgdal1h.symbols.armel.new | c++filt > debian/libgdal1h.symbols.armel.new.filt

				my $filt = $output.'.filt';

				print "Exec: cat $output | $cfg{cppfilt} > $filt 2>&1\n" if($cfg{verbose});

				`cat $output | $cfg{cppfilt} > $filt 2>&1`;

				# libgdal.so.1 libgdal1h #MINVER# 
				# #include "libgdal1h.symbols.common"

				my $data = '';

				my $i = 0;
				foreach(read_file($filt)) {
					if($i == 0) {
						$_ .= "#include \"${package}.symbols.common\"\n";
					}
					$data .= $_;
					$i++;
				}

				write_file($filt, $data);

				print "\n" if($cfg{verbose});
			}	
		}
		closedir DIR;
	}
	else {
		print "Error: Cannot read/write directory: $dir\n";
		print "\n" if($cfg{verbose});
		return;
	}
}

sub find_library {
	my $dir   = shift;
	my $depth = shift;
	   $depth = 0 if(!$depth);

	my $max_depth = 5;

	if($depth == $max_depth) {
		print "Not looking further, maximum depth reached: $depth\n";
		return;
	}

	my $library = '';

	if(-r $dir) {
		print "Reading directory: $dir\n" if($cfg{verbose});

		opendir(my $dh, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir $dh) {
			next if(/^\.{1,2}$/);

			my $entry = $dir.$_;

			if(-d $entry) {
				$library = find_library($entry.'/', $depth+1);
			}
			elsif(-f $entry && $entry =~ /\.so\.\d+\.\d+/) {
				$library = $entry;
				last;
			}
		}
		closedir $dh;

		print "Library: $library\n" if($cfg{verbose});
	}
	else {
		print "Error: Cannot read directory: $dir\n";
		return;
	}

	return $library;
}

sub create_patch_files {
	# Create c++filt symbols files

	my $dir = $cfg{debian};

	if(-r $dir && -w $dir) {
		opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir DIR) {
			# libgdal1h.symbols.amd64
			if(/^($cfg{package}).symbols.(\S+)$/) {
				my $pkg  = $1;
				my $arch = $2;
				my $file = $dir.$_;

				next if($arch eq 'common');
				next if($arch =~ /\.(new|diff|filt|patch|c\+\+|common|complete)$/);

				my $diff_file  = $file.'.diff';
				my $new_file   = $file.'.new';
				my $filt_file  = $file.'.new.filt';
				my $patch_file = $file.'.new.patch';

				if(-r $diff_file && -r $new_file && -r $filt_file) {
					# Mark C++ symbols

					my @cmd = (
						    $cfg{diff},
						    '-u',
						    $new_file,
						    $filt_file,
						  );

					my $data = '';
					my $old  = '';
					my $new  = '';
					my $tmp  = '';

					foreach(`@cmd`) {
						# --- debian/libgdal1h.symbols.amd64.new  2013-12-14 00:18:32.000000000 +0100
						if(/^\-\-\- (\S+\s+\d{4}.*?\S)\s*$/) {
							$old = $1;

							$_ = '';
						}
						# +++ debian/libgdal1h.symbols.amd64.new.filt     2013-12-14 01:44:01.000000000 +0100
						elsif(/^\+\+\+ (\S+\s+\d{4}.*?\S)\s*$/) {
							$new = $1;

							$_ = '--- '. $new."\n"
							   . '+++ '. $old."\n"
							   ;
						}
						# + VRTSourcedRasterBand::ComputeRasterMinMax(int, double*)@GDAL_1.8 1.10.1
						elsif(/^\+ (.*?) (\d+\.\d+\.\d+\S*)\s*$/) {
							# ignore
							$_ = '+ (c++)"'.$1.'" '.$2."\n";
						}

						$data .= $_;
					}

					print "Saving rewritten patch: $patch_file\n" if($cfg{verbose});

					write_file($patch_file, $data);
				}
				else {
					print "Error: Cannot read all files: $diff_file, $new_file, $filt_file\n";
					print `ls -l $diff_file $new_file $filt_file`;
					next;
				}
			}
		}
		closedir DIR;
	}
	else {
		print "Error: Cannot read/write directory: $dir\n";
		return;
	}
}

sub patch_files {
	# Apply c++filt symbols patches

	my $dir = $cfg{debian};

	if(-r $dir && -w $dir) {
		opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir DIR) {
			# libgdal1h.symbols.amd64
			if(/^($cfg{package}).symbols.(\S+)$/) {
				my $pkg  = $1;
				my $arch = $2;
				my $file = $dir.$_;

				next if($arch eq 'common');
				next if($arch =~ /\.(new|diff|filt|patch|c\+\+|common|complete)$/);

				my $diff_file  = $file.'.diff';
				my $new_file   = $file.'.new';
				my $filt_file  = $file.'.new.filt';
				my $patch_file = $file.'.new.patch';

				if(-r $diff_file && -r $new_file && -r $filt_file && -r $patch_file) {
					# Mark C++ symbols

					my @cmd = (
						    $cfg{patch},
						    '-p1',
						    '-i'.$patch_file,
						    $new_file,
						  );

					print "Exec: @cmd\n" if($cfg{verbose});

					my $exit = system(@cmd) >> 8;
					if($exit != 0) {
						print "Error: Command failed: @cmd ($exit)\n";
						exit $exit;
					}

					@cmd = ('rm', $patch_file);

					print "Exec: @cmd\n" if($cfg{verbose});

					$exit = system(@cmd) >> 8;
					if($exit != 0) {
						print "Error: Command failed: @cmd ($exit)\n";
						exit $exit;
					}

					print "\n" if($cfg{verbose});
				}
				else {
					print "Error: Cannot read all files: $diff_file, $new_file, $filt_file, $patch_file\n";
					print "\n" if($cfg{verbose});
					next;
				}
			}
		}
		closedir DIR;
	}
	else {
		print "Error: Cannot read/write directory: $dir\n";
		print "\n" if($cfg{verbose});
		return;
	}
}

sub split_files {
	# Split common and C++ symbols into seperate files.

	my $dir = $cfg{debian};

	if(-r $dir && -w $dir) {
		opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir DIR) {
			# libgdal1h.symbols.amd64
			if(/^($cfg{package}).symbols.(\S+)$/) {
				my $pkg  = $1;
				my $arch = $2;
				my $file = $dir.$_;

				next if($arch eq 'common');
				next if($arch =~ /\.(new|diff|filt|patch|c\+\+|common|complete)$/);

				my $diff_file  = $file.'.diff';
				my $new_file   = $file.'.new';
				my $filt_file  = $file.'.new.filt';
				my $patch_file = $file.'.new.patch';

				if(-r $diff_file && -r $new_file && -r $filt_file && !-r $patch_file) {
					print "Splitting files for: $file\n" if($cfg{verbose});

					my $common = '';
					my $cplus  = '';

					foreach(read_file($new_file)) {
						if(/\(c\+\+\)/ || !/^ /) {
							$cplus  .= $_;
						}
						else {
							$common .= $_;
						}
					}

					my $common_file = $new_file.'.common';
					my $cplus_file  = $new_file.'.c++';

					write_file($common_file, $common);
					write_file($cplus_file,  $cplus);
				}
				else {
					print "Error: Cannot read all files: $diff_file, $new_file, $filt_file, $patch_file\n";
					next;
				}
			}
		}
		closedir DIR;

		print "\n" if($cfg{verbose});
	}
	else {
		print "Error: Cannot read/write directory: $dir\n";
		return;
	}
}

sub compare_symbols {
	my $dir = $cfg{debian};

	if(-r $dir && -w $dir) {
		my %checksum = ();

		my $arch = 'common';
		my $file = $dir.$cfg{package}.'.symbols.'.$arch;

		print "Comparing symbols for: $file\n" if($cfg{verbose});

		if(-r $file) {
			my @items = ();
			my @files = ();

			chomp(my $sha512sum = `$cfg{sha512sum} "$file" | cut -d' ' -f1`);

			print "$sha512sum  $file\n" if($cfg{verbose});

			$checksum{$arch} = $sha512sum;

			push @items, "$sha512sum  $file";
			push @files, $file;

			my $identical = 1;
			my @different = ();

			opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
			while(readdir DIR) {
				# libgdal1h.symbols.amd64.new.common
				if(/^($cfg{package}).symbols.(\S+).new.common$/) {
					my $pkg2  = $1;
					my $arch2 = $2;
					my $file2 = $dir.$_;

					chomp(my $sha512sum = `$cfg{sha512sum} "$file2" | cut -d' ' -f1`);

					print "$sha512sum  $file2\n" if($cfg{verbose});

					$checksum{$arch2} = $sha512sum;

					push @items, "$sha512sum  $file2";
					push @files, $file2;

					if($checksum{common} ne $sha512sum) {
						$identical = 0;

						push @different, $file2;

						$items[-1] .= " *";
					}
				}
			}
			closedir DIR;

			if(@different) {
				print "\n" if($cfg{verbose});

				if(!$cfg{no_diff}) {
					foreach my $file2 (@different) {
						my $old = $file;
						my $new = $file2;
	
						my @cmd = (
							    $cfg{diff},
							    '-u',
							    $old,
							    $new,
							  );
	
						print "Exec: @cmd\n" if($cfg{verbose});
	
						my $exit = system(@cmd) >> 8;
	
						print "Exit: $exit\n" if($cfg{verbose});
					}
				}
			}

			if($identical) {
				print "Current $arch symbols are identical to the new symbols, no update required.\n" if($cfg{verbose});
			}
			else {
				print "New $arch symbols different from the current symbols, update required!\n" if($cfg{verbose});

				if(!$cfg{no_prompt}) {
					my $result = prompt(
							     'm',
							     {
							       prompt => "Select new symbols file to update current symbols file with:",
							       title  => "Update symbols file $file",
							       items  => \@items,
							       order  => 'down',
							       cols   => 1,
							     },
							     "[0]",
							     0,
							   );

					if($result) {
						print "New common symbols file selected: $items[$result]\n" if($cfg{verbose});

						my $file1 = $files[$result];
						my $file2 = $file;

						if(-r $file1 && -w $file2) {
							print "Copy: $file1 -> $file2\n" if($cfg{verbose});

							copy($file1, $file2) || die "Error: Failed to copy $file1 to $file2 ($!)\n";
						}
						else {
							print "Error: Cannot read $file1 and/or write $file2\n";
							return;
						}
					}
					else {
						print "Current common symbols file selected, skipping update.\n" if($cfg{verbose});
					}
				}
			}

			print "\n" if($cfg{verbose});
		}

		opendir(DIR, $dir) || die "Error: Cannot open directory: $dir ($!)";
		while(readdir DIR) {
			# libgdal1h.symbols.amd64
			if(/^($cfg{package}).symbols.(\S+)$/) {
				my $pkg  = $1;
				my $arch = $2;
				my $file = $dir.$_;

				next if($arch eq 'common');
				next if($arch =~ /\.(new|diff|filt|patch|c\+\+|common|complete)$/);

				print "Comparing symbols for: $file\n" if($cfg{verbose});

				my $old = $file;
				my $new = $file.'.new.c++';

				if(!-r $new) {
					print "Missing new $arch symbols, likely needs update later.\n" if($cfg{verbose});
				}
				else {
					chomp(my $old_sha512sum = `$cfg{sha512sum} "$old" 2> /dev/null | cut -d' ' -f1`);
					chomp(my $new_sha512sum = `$cfg{sha512sum} "$new" 2> /dev/null | cut -d' ' -f1`);

					print "$old_sha512sum  $old\n" if($cfg{verbose});
					print "$new_sha512sum  $new\n" if($cfg{verbose});

					if($old_sha512sum eq $new_sha512sum) {
						print "Current symbols are identical to the new $arch symbols, no update required.\n" if($cfg{verbose});
					}
					else {
						if(!$cfg{no_diff}) {
							my @cmd = (
							    $cfg{diff},
									    '-u',
								    $old,
								    $new,
								  );
			
							print "Exec: @cmd\n" if($cfg{verbose});
			
							my $exit = system(@cmd) >> 8;
							
							print "Exit: $exit\n" if($cfg{verbose});
	
							print `@cmd | diffstat`;
						}
	
						print "New $arch symbols different from the current symbols, update required!\n" if($cfg{verbose});

						if(!$cfg{no_prompt}) {
							my $help    = $cfg{yes} ? "Y/n" : "y/N";
							my $default = $cfg{yes} ? "Y"   : "N";

							my $result = prompt(
									     'y',
									     "Update symbols file for $arch?",
									     $help,
									     $default,
									   );
		
							if($result) {
								my $file1 = $new;
								my $file2 = $old;
		
								if(-r $file1 && -w $file2) {
									print "Copy: $file1 -> $file2\n" if($cfg{verbose});

									copy($file1, $file2) || die "Error: Failed to copy $file1 to $file2 ($!)\n";
								}
								else {
									print "Error: Cannot read $file1 and/or write $file2\n";
									return;
								}
							}
							else {
								print "Skipping update.\n" if($cfg{verbose});
							}
						}
					}
				}
		
				print "\n" if($cfg{verbose});
			}
		}
		closedir DIR;

		print "\n" if($cfg{verbose});
	}
	else {
		print "Error: Cannot read/write directory: $dir\n";
		print "\n" if($cfg{verbose});
		return;
	}
}

