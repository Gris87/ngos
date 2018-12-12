#!/bin/bash

# This script helps to fetch FreeType source codes from the web
# Author: Maxim Shvecov
# Usage: ./fetch_freetype.sh



###########################################################################################
#    PROCESSING
###########################################################################################



mkdir libs/
cd libs/

FREETYPE_ZIP=`curl "https://download.savannah.gnu.org/releases/freetype/?C=M&O=D" 2> /dev/null | grep freetype-[0-9] | grep tar.gz\" | head -n 1 | cut -d "\"" -f 4`
wget "https://download.savannah.gnu.org/releases/freetype/${FREETYPE_ZIP}"

tar -xf freetype*.tar.gz
rm freetype*.tar.gz
mv freetype-* freetype

cd ..
