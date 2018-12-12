#!/bin/bash



###########################################################################################
#    PARAMETERS
###########################################################################################



WORKING_DIR=`pwd`



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m               Test: Symbols size\e[0m"
echo -e "\e[36m==================================================\e[0m"



cd ../../

for elf_file in `find -name \*.elf`
do
    EMPTY_SYMBOLS=`readelf -s ${elf_file} | grep -E -e " *[0-9]+: +[0-9a-f]+ +0 +[A-Z]+ +GLOBAL" | grep -v " _"`

    if [ "${EMPTY_SYMBOLS}" != "" ]; then
        echo "Symbols with zero size found in ELF file: ${elf_file}"
        echo "${EMPTY_SYMBOLS}"

        cd ${WORKING_DIR}/
        exit 1
    fi
done

cd ${WORKING_DIR}/

echo "OK"



exit 0
