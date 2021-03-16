#!/bin/bash

# This script helps to find files that not fully marked by QtColorize plugin
# Author: Maxim Shvecov
# Usage: ./scripts/non_verified_files.sh



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



TOTAL_NUMBER_OF_LINES=0
TOTAL_NOT_VERIFIED_LINES=0

while read file
do
    IGNORE_FILE=`echo "${file}" | grep  \
                -ve "\.auth$"           \
                -ve "\.bin$"            \
                -ve "\.DAT$"            \
                -ve "\.dll$"            \
                -ve "\.efi$"            \
                -ve "\.exe$"            \
                -ve "\.gitignore$"      \
                -ve "\.gpg$"            \
                -ve "\.ico$"            \
                -ve "\.jpg$"            \
                -ve "\.LOG$"            \
                -ve "\.mui$"            \
                -ve "\.patch$"          \
                -ve "\.png$"            \
                -ve "\.qm$"             \
                -ve "\.stl$"            \
                -ve "\.ttf$"            \
                -ve "\.vbox$"           \
                -ve "/generated/"       \
                -ve "/BCD$"             \
                -ve "/\.config$"        \
                -ve "/\.gdbinit$"       \
                -ve "/\.htaccess$"      \
                -ve "/\.spelling$"      \
    `

    if [ "${IGNORE_FILE}" != "" ]; then
        FIRST_LINE=`        cat "${file}" | grep -m1 -n -v "Colorize: green" | cut -d : -f 1`
        NOT_VERIFIED_LINES=`cat "${file}" | grep        -v "Colorize: green" | wc -l`
        NUMBER_OF_LINES=`   cat "${file}" | wc -l`



        if [ "${FIRST_LINE}" != "" ]; then
            echo "${file}: ${NOT_VERIFIED_LINES} lines not verified. First line: ${FIRST_LINE}"

            TOTAL_NOT_VERIFIED_LINES=$((${TOTAL_NOT_VERIFIED_LINES} + ${NOT_VERIFIED_LINES}))
        fi

        TOTAL_NUMBER_OF_LINES=$((${TOTAL_NUMBER_OF_LINES} + ${NUMBER_OF_LINES}))
    fi
done < ngos.files

echo "${TOTAL_NOT_VERIFIED_LINES} of ${TOTAL_NUMBER_OF_LINES} lines not verified"



exit 0
