#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to calculate amount of code lines for the whole project except generated files                                                                                                       # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./scripts/amount_of_code_lines.sh                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    VERIFICATION                                                                                                                                                                                        # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ ! -f ngos.files ]; then                                                                                                                                                                             # Colorize: green
    echo "Please run this script from the root folder"                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PROCESSING                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
OLD_IFS=${IFS}                                                                                                                                                                                           # Colorize: green
IFS=$'\n'                                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo -n "Amount of code lines without generated: "                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
wc -l ` \
        cat ngos.files | \
            grep \
                -ve /generated/ \
                -ve tools/tracers/assets/ \
                -ve \.bin$ \
                -ve \.dll$ \
                -ve \.exe$ \
                -ve \.gpg$ \
                -ve \.pem$ \
                -ve \.auth$ \
                -ve \.ttf$ \
                -ve \.ico$ \
                -ve \.png$ \
                -ve \.jpg$ \
                -ve \.gif$ \
                -ve \.svg$ \
    ` | \
    tail -n 1 | \
    sed -s -E "s/ *([0-9]+) .*/\1/"                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo -n "Amount of code lines with generated:    "                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    wc -l ` \
            cat ngos.files | \
                grep \
                    -ve tools/tracers/assets/ \
                    -ve \.bin$ \
                    -ve \.dll$ \
                    -ve \.exe$ \
                    -ve \.gpg$ \
                    -ve \.pem$ \
                    -ve \.auth$ \
                    -ve \.ttf$ \
                    -ve \.ico$ \
                    -ve \.png$ \
                    -ve \.jpg$ \
                    -ve \.gif$ \
                    -ve \.svg$ \
        ` | \
        tail -n 1 | \
        sed -s -E "s/ *([0-9]+) .*/\1/"                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
IFS=${OLD_IFS}                                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
