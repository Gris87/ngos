#!/bin/bash

# This script helps to fetch prebuilt UEFI Shell from the web
# Author: Maxim Shvecov
# Usage: ./fetch_shellbinpkg.sh



###########################################################################################
#    PROCESSING
###########################################################################################



mkdir libs/
cd libs/

EDK_ZIP=`curl "https://github.com/tianocore/edk2/releases" 2> /dev/null | grep edk2-stable[0-9]*/ShellBinPkg.zip | head -n 1 | cut -d \" -f 2`
wget "https://github.com/${EDK_ZIP}"

unzip ShellBinPkg.zip
rm ShellBinPkg.zip

cd ..
