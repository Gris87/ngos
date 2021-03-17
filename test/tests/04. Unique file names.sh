#!/bin/bash
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PARAMETERS                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
WORKING_DIR=`pwd`                                                                                                                                                                                        # Colorize: green
PROJECT_INCLUDES=ngos.includes                                                                                                                                                                           # Colorize: green
ALL_INCLUDES=/tmp/ngos_list_of_includes.txt                                                                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
#    PROCESSING                                                                                                                                                                                          # Colorize: green
###########################################################################################                                                                                                              # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo -e "\e[36m==================================================\e[0m"                                                                                                                                  # Colorize: green
echo -e "\e[36m             Test: Unique file names\e[0m"                                                                                                                                                # Colorize: green
echo -e "\e[36m==================================================\e[0m"                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
rm ${ALL_INCLUDES} > /dev/null 2>&1                                                                                                                                                                      # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ../../                                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
for line in `cat ${PROJECT_INCLUDES} | grep -ve "^~/Qt/" -ve "^3rd_party/"`                                                                                                                              # Colorize: green
do                                                                                                                                                                                                       # Colorize: green
    echo "${line}:"                                     >> ${ALL_INCLUDES}                                                                                                                               # Colorize: green
    bash -c "cd \"${line}\" && find -type f -name \*.h" >> ${ALL_INCLUDES}                                                                                                                               # Colorize: green
done                                                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ${WORKING_DIR}/                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
DUPLICATES=` \                                                                                                                                                                                           # Colorize: green
    cat ${ALL_INCLUDES} | sort | uniq -d | \                                                                                                                                                             # Colorize: green
    grep \                                                                                                                                                                                               # Colorize: green
        -ve "./build/gen/moc_predefs.h" \                                                                                                                                                                # Colorize: green
        -ve "./build/gen/ui_aboutdialog.h" \                                                                                                                                                             # Colorize: green
        -ve "./build/gen/ui_mainwindow.h" \                                                                                                                                                              # Colorize: green
        -ve "./moc_predefs.h" \                                                                                                                                                                          # Colorize: green
        -ve "./src/main/aboutdialog.h" \                                                                                                                                                                 # Colorize: green
        -ve "./src/main/mainwindow.h" \                                                                                                                                                                  # Colorize: green
        -ve "./src/other/global.h" \                                                                                                                                                                     # Colorize: green
        -ve "./ui_aboutdialog.h" \                                                                                                                                                                       # Colorize: green
        -ve "./ui_mainwindow.h" \                                                                                                                                                                        # Colorize: green
`                                                                                                                                                                                                        # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ "${DUPLICATES}" != "" ]; then                                                                                                                                                                       # Colorize: green
    echo "Duplicate file names:"                                                                                                                                                                         # Colorize: green
    echo "${DUPLICATES}"                                                                                                                                                                                 # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "OK"                                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
