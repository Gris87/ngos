#!/bin/bash

# This script helps to fetch EDK2 source codes from the web
# Author: Maxim Shvecov
# Usage: ./fetch_edk2.sh



###########################################################################################
#    PROCESSING
###########################################################################################



mkdir libs/
cd libs/

EDK_ZIP=`curl "https://github.com/tianocore/edk2/tags" 2> /dev/null | grep edk2-stable[0-9] | grep tar.gz\" | head -n 1 | cut -d \" -f 4`
wget "https://github.com/${EDK_ZIP}"

tar -xf edk2*.tar.gz
rm edk2*.tar.gz
mv edk2-* edk2

cd ..
