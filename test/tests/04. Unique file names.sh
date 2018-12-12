#!/bin/bash



###########################################################################################
#    PARAMETERS
###########################################################################################



WORKING_DIR=`pwd`
PROJECT_INCLUDES=ngos.includes
ALL_INCLUDES=/tmp/ngos_list_of_includes.txt



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m             Test: Unique file names\e[0m"
echo -e "\e[36m==================================================\e[0m"



rm ${ALL_INCLUDES} > /dev/null 2>&1



cd ../../

for line in `cat ${PROJECT_INCLUDES} | grep -ve "^~/Qt/" -ve "^3rd_party/"`
do
    echo "${line}:"                                     >> ${ALL_INCLUDES}
    sh -c "cd \"${line}\" && find -type f -name \*.h"   >> ${ALL_INCLUDES}
done

cd ${WORKING_DIR}/



DUPLICATES=` \
    cat ${ALL_INCLUDES} | sort | uniq -d | \
    grep \
        -ve "./build/gen/moc_predefs.h" \
        -ve "./build/gen/ui_aboutdialog.h" \
        -ve "./build/gen/ui_mainwindow.h" \
        -ve "./moc_predefs.h" \
        -ve "./src/main/aboutdialog.h" \
        -ve "./src/main/mainwindow.h" \
        -ve "./src/other/global.h" \
        -ve "./ui_aboutdialog.h" \
        -ve "./ui_mainwindow.h" \
`



if [ "${DUPLICATES}" != "" ]; then
    echo "Duplicate file names:"
    echo "${DUPLICATES}"

    exit 1
fi

echo "OK"



exit 0
