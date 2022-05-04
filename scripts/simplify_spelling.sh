#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
# This script helps to simplify docs/.spelling file                                                                                                                                                      # Colorize: green
# Author: Maxim Shvetsov                                                                                                                                                                                  # Colorize: green
# Usage: ./scripts/simplify_spelling.sh                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PARAMETERS                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
SPELLING_FILE=docs/.spelling                                                                                                                                                                             # Colorize: green
SPELLING_TEMP=`mktemp -t ngos_spelling_XXXX`                                                                                                                                                             # Colorize: green
BUILD_LOG=`mktemp -t ngos_build_XXXX.log`                                                                                                                                                                # Colorize: green
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
echo "Start spelling simplifier"                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
make verify-docs > ${BUILD_LOG} 2>&1                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ $? -ne 0 ]; then                                                                                                                                                                                    # Colorize: green
    echo "It is required to fix all documentation issues first:"                                                                                                                                         # Colorize: green
    cat ${BUILD_LOG}                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
rm ${SPELLING_TEMP} > /dev/null 2>&1                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
LINES=(`cat ${SPELLING_FILE} | sort | uniq`)                                                                                                                                                             # Colorize: green
LINE_COUNT=${#LINES[@]}                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
for ((i = 0; i < ${LINE_COUNT}; i++))                                                                                                                                                                    # Colorize: green
do                                                                                                                                                                                                       # Colorize: green
    LINE=${LINES[$i]}                                                                                                                                                                                    # Colorize: green
    LINE_LENGTH=${#LINE}                                                                                                                                                                                 # Colorize: green
    PERCENT=$((i * 100 / LINE_COUNT))                                                                                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    printf "Processing spelling \"%s\"...%$((45 - LINE_LENGTH))s %s %%    " "${LINE}" "" "${PERCENT}"                                                                                                    # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    rm ${SPELLING_FILE} > /dev/null 2>&1                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    for ((j = 0; j < ${LINE_COUNT}; j++))                                                                                                                                                                # Colorize: green
    do                                                                                                                                                                                                   # Colorize: green
        if [ $i -ne $j ]; then                                                                                                                                                                           # Colorize: green
            echo "${LINES[$j]}" >> ${SPELLING_FILE}                                                                                                                                                      # Colorize: green
        fi                                                                                                                                                                                               # Colorize: green
    done                                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    tools/qt/docs_verifier/build/docs_verifier . > /dev/null 2>&1                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    if [ $? -ne 0 ]; then                                                                                                                                                                                # Colorize: green
        echo -e "[\e[32mOK\e[0m]"                                                                                                                                                                        # Colorize: green
        echo "${LINE}" >> ${SPELLING_TEMP}                                                                                                                                                               # Colorize: green
    else                                                                                                                                                                                                 # Colorize: green
        echo -e "[\e[33mSkipped\e[0m]"                                                                                                                                                                   # Colorize: green
    fi                                                                                                                                                                                                   # Colorize: green
done                                                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
mv ${SPELLING_TEMP} ${SPELLING_FILE}                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
