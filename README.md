# GDAL with DDS for Ubuntu
## Compilation
1. Go into the folder containing the code (should see a debian folder in it):

  `cd gdal-ubuntu-xenial-1.11.3-dfsg-3build2dds`

2. Compile the code:

  `dpkg-buildpackage -rfakeroot -b`
    
  It should take 30 - 45 minutes for the code to compile.

  3.  (Optional) Install the .deb files from the parent directory of the code:
  
  ```
  cd ..
  sudo dpkg -i gdal-bin*.deb libgdal1i*.deb
  ```

## Upstream sources:
* GDAL:  https://salsa.debian.org/debian-gis-team/gdal/
* Crunch:  https://github.com/pdavidc/crunch/

