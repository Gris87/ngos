#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to fetch FreeType source codes from the web                                                                                                                                          # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./fetch_freetype.sh                                                                                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PARAMETERS                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
CURRENT_PATH=`pwd`                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PROCESSING                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
mkdir libs/                                                                                                                                                                                              # Colorize: green
cd libs/                                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
FREETYPE_ZIP=`curl "https://download.savannah.gnu.org/releases/freetype/?C=M&O=D" 2> /dev/null | grep freetype-[0-9] | grep tar.xz\" | head -n 1 | sed -r "s/.*href=\"(freetype-[0-9.]+.tar.xz)\".*/\1/g"` # Colorize: green
wget "https://download.savannah.gnu.org/releases/freetype/${FREETYPE_ZIP}"                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
tar -xf ${FREETYPE_ZIP}                                                                                                                                                                                 # Colorize: green
rm ${FREETYPE_ZIP}                                                                                                                                                                                      # Colorize: green
mv freetype-* freetype                                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ${CURRENT_PATH}                                                                                                                                                                                                    # Colorize: green
