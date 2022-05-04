#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to calculate amount of code lines for the whole project except generated files                                                                                                       # Colorize: green
# Author: Maxim Shvetsov                                                                                                                                                                                  # Colorize: green
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
                -ve "/generated/"           \
                -ve "tools/tracers/assets/" \
                -ve "\.auth$"               \
                -ve "\.bin$"                \
                -ve "\.dll$"                \
                -ve "\.exe$"                \
                -ve "\.gif$"                \
                -ve "\.gpg$"                \
                -ve "\.ico$"                \
                -ve "\.jpg$"                \
                -ve "\.pem$"                \
                -ve "\.png$"                \
                -ve "\.qm$"                 \
                -ve "\.svg$"                \
                -ve "\.ttf$"                \
    ` | \
    tail -n 1 | \
    sed -r "s/ *([0-9]+).*/\1/g"                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo -n "Amount of code lines with generated:    "                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
wc -l ` \
        cat ngos.files | \
            grep \
                -ve "tools/tracers/assets/" \
                -ve "\.auth$"               \
                -ve "\.bin$"                \
                -ve "\.dll$"                \
                -ve "\.exe$"                \
                -ve "\.gif$"                \
                -ve "\.gpg$"                \
                -ve "\.ico$"                \
                -ve "\.jpg$"                \
                -ve "\.pem$"                \
                -ve "\.png$"                \
                -ve "\.qm$"                 \
                -ve "\.svg$"                \
                -ve "\.ttf$"                \
    ` | \
    tail -n 1 | \
    sed -r "s/ *([0-9]+).*/\1/g"                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
IFS=${OLD_IFS}                                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
