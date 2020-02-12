#!/bin/bash

# This script helps to calculate amount of code lines for the whole project except generated files
# Author: Maxim Shvecov
# Usage: ./scripts/amount_of_code_lines.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



OLD_IFS=${IFS}
IFS=$'\n'

wc -l ` \
        cat ngos.files | \
            grep \
                -ve tools/tracers/assets/ \
                -ve \.bin$ \
                -ve \.dll$ \
                -ve \.exe$ \
                -ve \.ttf$ \
                -ve \.ico$ \
                -ve \.png$ \
                -ve \.jpg$ \
                -ve \.gif$ \
                -ve \.svg$ \
    ` | \
    tail -n 1 | \
    cut -d " " -f 2

IFS=${OLD_IFS}



exit 0
