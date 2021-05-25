#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to update ngos.files file                                                                                                                                                            # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./scripts/update_ngos_files.sh                                                                                                                                                                  # Colorize: green
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
find -type f | \
    grep \
        -ve "/.git/"              \
        -ve "/ngos.cflags$"       \
        -ve "/ngos.config$"       \
        -ve "/ngos.creator$"      \
        -ve "/ngos.creator.user$" \
        -ve "/ngos.cxxflags$"     \
        -ve "/ngos.files$"        \
        -ve "/ngos.includes$" |   \
    git check-ignore --verbose --non-matching --stdin | \
    grep -e "^::" | \
    sed -r "s/^::\t\.\///g" | \
    sort > ngos.files                                                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
