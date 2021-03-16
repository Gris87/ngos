#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to fetch FreeType source codes from the web                                                                                                                                          # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./fetch_freetype.sh                                                                                                                                                                             # Colorize: green
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
FREETYPE_ZIP=`curl "https://download.savannah.gnu.org/releases/freetype/?C=M&O=D" 2> /dev/null | grep freetype-[0-9] | grep tar.xz\" | head -n 1 | cut -d \" -f 4`                                       # Colorize: green
wget "https://download.savannah.gnu.org/releases/freetype/${FREETYPE_ZIP}"                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
tar -xf freetype*.tar.xz                                                                                                                                                                                 # Colorize: green
rm freetype*.tar.xz                                                                                                                                                                                      # Colorize: green
mv freetype-* freetype                                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ..                                                                                                                                                                                                    # Colorize: green
