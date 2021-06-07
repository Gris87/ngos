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
TOTAL_NUMBER_OF_FILES=0                                                                                                                                                                                  # Colorize: green
TOTAL_NUMBER_OF_LINES=0                                                                                                                                                                                  # Colorize: green
TOTAL_NOT_VERIFIED_LINES=0                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
while read file                                                                                                                                                                                          # Colorize: green
do                                                                                                                                                                                                       # Colorize: green
    IGNORE_FILE=`echo "${file}" | \
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
                        -ve "^ngos.creator.shared$" \
                        -ve "Makefile$"             \
                        -ve "\.gdbinit$"            \
                        -ve "\.gitignore$"          \
                        -ve "\.hex$"                \
                        -ve "\.htaccess$"           \
                        -ve "\.rc$"                 \
                        -ve "\.spelling$"           \
                        -ve "\.ts$"                 \
                        -ve "\.ui$"                 \
                        -ve "\.vbox$"               \
    `                                                                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    if [ "${IGNORE_FILE}" != "" ]; then                                                                                                                                                                  # Colorize: green
        FIRST_LINE=`        cat "${file}" | grep -m1 -n -ve "Colorize: green" -ve "^#!/bin/bash$" -ve " \\\\$" | sed -r "s/^([0-9]+):.*/\1/g"`                                                                        # Colorize: green
        NOT_VERIFIED_LINES=`cat "${file}" | grep        -ve "Colorize: green" | wc -l`                                                                                                                   # Colorize: green
        NUMBER_OF_LINES=`   cat "${file}" | wc -l`                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        if [ ${NOT_VERIFIED_LINES} -ne 0 ]; then                                                                                                                                                               # Colorize: green
            SHELL_FILE=`echo "${file}" | grep -e "\.sh$"`                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            if [ "${SHELL_FILE}" != "" ]; then                                                                                                                                                           # Colorize: green
                IGNORED_LINES=`cat "${file}" | grep -e "^#!/bin/bash$" -e " \\\\$" | wc -l`                                                                                                             # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                NOT_VERIFIED_LINES=$((${NOT_VERIFIED_LINES} - ${IGNORED_LINES}))                                                                                                                         # Colorize: green
            fi                                                                                                                                                                                           # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            CPP_FILE=`echo "${file}" | grep -e "\.cpp$" -e "\.h$"`                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
            if [ "${CPP_FILE}" != "" ]; then                                                                                                                                                             # Colorize: green
                IGNORED_LINES=`cat "${file}" | grep -e " \\\\$" | wc -l`                                                                                                                                # Colorize: green
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
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        TOTAL_NUMBER_OF_LINES=$((${TOTAL_NUMBER_OF_LINES} + ${NUMBER_OF_LINES}))                                                                                                                         # Colorize: green
        TOTAL_NUMBER_OF_FILES=$((${TOTAL_NUMBER_OF_FILES} + 1))                                                                                                                                          # Colorize: green
    fi                                                                                                                                                                                                   # Colorize: green
done < ngos.files                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "${TOTAL_NOT_VERIFIED_LINES} of ${TOTAL_NUMBER_OF_LINES} lines not verified in ${TOTAL_NUMBER_OF_FILES} files"                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
