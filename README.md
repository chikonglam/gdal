# GDAL with DDS for Ubuntu
## Compilation
1. Go into the folder containing the code (should see a debian folder in it):

  `cd gdal-ubuntu-bionic-2.2.3-dfsg-2dds`

2. Compile the code:

  `dpkg-buildpackage -rfakeroot -b`
  
  It should take 45 - 60 minutes for the code to compile.

3.  (Optional) Install the .deb files from the parent directory of the code:

  ```
  cd ..
  sudo dpkg -i gdal-bin*.deb gdal-data*.deb libgdal20*.deb
  ```

## Upstream sources:
* GDAL:  https://salsa.debian.org/debian-gis-team/gdal/
* Crunch:  https://github.com/pdavidc/crunch/

