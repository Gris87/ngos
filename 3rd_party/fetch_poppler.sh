#!/bin/bash

# This script helps to fetch Poppler source codes from the web
# Author: Maxim Shvecov
# Usage: ./fetch_poppler.sh



###########################################################################################
#    PROCESSING
###########################################################################################



mkdir libs/
cd libs/

POPPLER_ZIP=`curl "https://poppler.freedesktop.org" 2> /dev/null | grep poppler-[0-9] | grep tar.xz\" | head -n 1 | cut -d \" -f 2`
wget "https://poppler.freedesktop.org/${POPPLER_ZIP}"

tar -xf poppler*.tar.xz
rm poppler*.tar.xz
mv poppler-* poppler

cd ..
