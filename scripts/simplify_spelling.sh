#!/bin/bash

# This script helps to simplify docs/.spelling file
# Author: Maxim Shvecov
# Usage: ./scripts/simplify_spelling.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



SPELLING_FILE=docs/.spelling
SPELLING_TEMP=/tmp/ngos_spelling



###########################################################################################
#    PROCESSING
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"
    exit 1
fi



echo "Start spelling simplifier"
echo ""

bash -c "cd tools/qt/docs_verifier/ && lupdate -noobsolete docs_verifier.pro && lrelease docs_verifier.pro && qmake docs_verifier.pro && make -j`nproc`"
VERIFIER_OUTPUT=`tools/qt/docs_verifier/build/docs_verifier .`

echo ""

if [ $? -ne 0 ]; then
    echo "It is required to fix all documentation issues first:"
    echo "${VERIFIER_OUTPUT}"

    exit 1
fi



rm ${SPELLING_TEMP} > /dev/null 2>&1



LINES=(`cat ${SPELLING_FILE} | sort | uniq`)
LINE_COUNT=${#LINES[@]}

for ((i = 0; i < ${LINE_COUNT}; i++))
do
    LINE=${LINES[$i]}
    LINE_LENGTH=${#LINE}
    PERCENT=$((i * 100 / LINE_COUNT))

    printf "Processing spelling \"%s\"...%$((45 - LINE_LENGTH))s %s %%    " "${LINE}" "" "${PERCENT}"



    rm ${SPELLING_FILE} > /dev/null 2>&1

    for ((j = 0; j < ${LINE_COUNT}; j++))
    do
        if [ $i -ne $j ]; then
            echo "${LINES[$j]}" >> ${SPELLING_FILE}
        fi
    done



    tools/qt/docs_verifier/build/docs_verifier . > /dev/null 2>&1

    if [ $? -ne 0 ]; then
        echo -e "[\e[32mOK\e[0m]"
        echo "${LINE}" >> ${SPELLING_TEMP}
    else
        echo -e "[\e[33mSkipped\e[0m]"
    fi
done



mv ${SPELLING_TEMP} ${SPELLING_FILE}



exit 0
