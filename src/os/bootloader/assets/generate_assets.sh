#!/bin/bash

# This script allows to generate assets.S file that will be included in kernel image
# Author: Maxim Shvecov
# Usage: ./generate_assets.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



ASSETS_FILE=generated/assets.S



###########################################################################################
#    PROCESSING
###########################################################################################



mkdir generated/ > /dev/null 2>&1



echo ".section \".assets\", \"a\"                                                     # assets section (a - allocatable)"                                              >  ${ASSETS_FILE}
echo "                                                                                #"                                                                               >> ${ASSETS_FILE}
echo "# ============================================================================= # =============================================================================" >> ${ASSETS_FILE}



FILE_ID=0

for line in `find -type f | grep -ve .gitignore -ve generate_assets.sh -ve ${ASSETS_FILE} | cut -c 3-`
do
    FILE_ID=$((FILE_ID + 1))

    echo "                                                                               #"                               >> ${ASSETS_FILE}
    echo "                                                                               #"                               >> ${ASSETS_FILE}
    echo "                                                                               #"                               >> ${ASSETS_FILE}
    echo "    .ascii  \"${line}\"                                                        # File ${line}"                  >> ${ASSETS_FILE}
    echo "    .byte   0                                                                  # Terminate file name with zero" >> ${ASSETS_FILE}
    echo "    .quad   label_${FILE_ID}_end - label_${FILE_ID}_begin                      # File size"                     >> ${ASSETS_FILE}
    echo "                                                                               #"                               >> ${ASSETS_FILE}
    echo "label_${FILE_ID}_begin:                                                        # Begin of the file"             >> ${ASSETS_FILE}
    echo "    .incbin \"assets/${line}\"                                                 # Including bytes of the file"   >> ${ASSETS_FILE}
    echo "label_${FILE_ID}_end:                                                          # End of the file"               >> ${ASSETS_FILE}
done



exit 0
