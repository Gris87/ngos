#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to find files that not fully marked by QtColorize plugin                                                                                                                             # Colorize: green
# Author: Maxim Shvecov                                                                                                                                                                                  # Colorize: green
# Usage: ./scripts/non_verified_files.sh                                                                                                                                                                 # Colorize: green
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
TOTAL_NUMBER_OF_LINES=0                                                                                                                                                                                  # Colorize: green
TOTAL_NOT_VERIFIED_LINES=0                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
while read file                                                                                                                                                                                          # Colorize: green
do                                                                                                                                                                                                       # Colorize: green
    IGNORE_FILE=`echo "${file}" | grep      \
                -ve "\.auth$"               \
                -ve "\.bin$"                \
                -ve "\.DAT$"                \
                -ve "\.dll$"                \
                -ve "\.efi$"                \
                -ve "\.exe$"                \
                -ve "\.gitignore$"          \
                -ve "\.gpg$"                \
                -ve "\.hex$"                \
                -ve "\.ico$"                \
                -ve "\.jpg$"                \
                -ve "\.LOG$"                \
                -ve "\.mui$"                \
                -ve "\.patch$"              \
                -ve "\.pem$"                \
                -ve "\.png$"                \
                -ve "\.qm$"                 \
                -ve "\.rc$"                 \
                -ve "\.stl$"                \
                -ve "\.ts$"                 \
                -ve "\.ttf$"                \
                -ve "\.ui$"                 \
                -ve "\.vbox$"               \
                -ve "^ngos.creator.shared$" \
                -ve "Makefile$"             \
                -ve "/generated/"           \
                -ve "/BCD$"                 \
                -ve "/\.config$"            \
                -ve "/\.gdbinit$"           \
                -ve "/\.htaccess$"          \
                -ve "/\.spelling$"          \
    `                                                                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    if [ "${IGNORE_FILE}" != "" ]; then                                                                                                                                                                  # Colorize: green
        FIRST_LINE=`        cat "${file}" | grep -m1 -n -ve "Colorize: green" -ve "^#!/bin/bash$" | cut -d : -f 1`                                                                                       # Colorize: green
        NOT_VERIFIED_LINES=`cat "${file}" | grep        -ve "Colorize: green" | wc -l`                                                                                                                   # Colorize: green
        NUMBER_OF_LINES=`   cat "${file}" | wc -l`                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        if [ "${FIRST_LINE}" != "" ]; then                                                                                                                                                               # Colorize: green
            SHELL_FILE=`echo "${file}" | grep -e "\.sh$"`                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            if [ "${SHELL_FILE}" != "" ]; then                                                                                                                                                           # Colorize: green
                IGNORED_LINES=$(cat "${file}" | grep -e "^#!/bin/bash$" -e " \\\\$" | wc -l)                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                NOT_VERIFIED_LINES=$((${NOT_VERIFIED_LINES} - ${IGNORED_LINES}))                                                                                                                         # Colorize: green
            fi                                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            CPP_FILE=`echo "${file}" | grep -e "\.cpp$" -e "\.h$"`                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            if [ "${CPP_FILE}" != "" ]; then                                                                                                                                                             # Colorize: green
                IGNORED_LINES=$(cat "${file}" | grep -e " \\\\$" | wc -l)                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                NOT_VERIFIED_LINES=$((${NOT_VERIFIED_LINES} - ${IGNORED_LINES}))                                                                                                                         # Colorize: green
            fi                                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            if [ ${NOT_VERIFIED_LINES} -ne 0 ]; then                                                                                                                                                     # Colorize: green
                echo "${file}: ${NOT_VERIFIED_LINES} lines not verified. First line: ${FIRST_LINE}"                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                TOTAL_NOT_VERIFIED_LINES=$((${TOTAL_NOT_VERIFIED_LINES} + ${NOT_VERIFIED_LINES}))                                                                                                        # Colorize: green
            fi                                                                                                                                                                                           # Colorize: green
        fi                                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        TOTAL_NUMBER_OF_LINES=$((${TOTAL_NUMBER_OF_LINES} + ${NUMBER_OF_LINES}))                                                                                                                         # Colorize: green
    fi                                                                                                                                                                                                   # Colorize: green
done < ngos.files                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "${TOTAL_NOT_VERIFIED_LINES} of ${TOTAL_NUMBER_OF_LINES} lines not verified"                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
