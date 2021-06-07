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
CURRENT_PATH=`pwd`                                                                                                                                                                                        # Colorize: green
BUILD_CONFIG=include/buildconfig.h                                                                                                                                                                       # Colorize: green
BUILD_LOG=/tmp/ngos_test_build.log                                                                                                                                                                       # Colorize: green
BUILD_CFG_BACKUP=/tmp/ngos_test_buildconfig.h                                                                                                                                                           # Colorize: green
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
echo -e "\e[36m               Test: Symbols size\e[0m"                                                                                                                                                   # Colorize: green
echo -e "\e[36m==================================================\e[0m"                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- Building --------------------\e[0m"                                                                                                                                  # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ../../                                                                                                                                                                                                # Colorize: green
cp ${BUILD_CONFIG} ${BUILD_CFG_BACKUP}                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
make tool-build_config_maker > ${BUILD_LOG} 2>&1                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ $? -ne 0 ]; then                                                                                                                                                                                    # Colorize: green
    cat ${BUILD_LOG}                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}                                                                                                                                                               # Colorize: green
    cd ${CURRENT_PATH}/                                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
tools/qt/build_config_maker/build/build_config_maker ${BUILD_CONFIG} --reset \
    NGOS_BUILD_RELEASE=OPTION_NO \
    NGOS_BUILD_TEST_MODE=OPTION_YES > ${BUILD_LOG} 2>&1                                                                                                         # Colorize: green
make test-debug >> ${BUILD_LOG} 2>&1                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
if [ $? -ne 0 ]; then                                                                                                                                                                                    # Colorize: green
    cat ${BUILD_LOG}                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}                                                                                                                                                               # Colorize: green
    cd ${CURRENT_PATH}/                                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    exit 1                                                                                                                                                                                               # Colorize: green
fi                                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}                                                                                                                                                                   # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
echo -e "\e[33m-------------------- Checking --------------------\e[0m"                                                                                                                                  # Colorize: green
echo ""                                                                                                                                                                                                  # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
for elf_file in `find -name \*.elf`                                                                                                                                                                      # Colorize: green
do                                                                                                                                                                                                       # Colorize: green
    EMPTY_SYMBOLS=`readelf -s ${elf_file} | grep -E -e " *[0-9]+: +[0-9a-f]+ +0 +[A-Z]+ +GLOBAL" | grep -v " _"`                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
    if [ "${EMPTY_SYMBOLS}" != "" ]; then                                                                                                                                                                # Colorize: green
        echo "Symbols with zero size found in ELF file: ${elf_file}"                                                                                                                                     # Colorize: green
        echo "${EMPTY_SYMBOLS}"                                                                                                                                                                          # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        cd ${CURRENT_PATH}/                                                                                                                                                                               # Colorize: green
                                                                                                                                                                                                         # Colorize: green
        exit 1                                                                                                                                                                                           # Colorize: green
    fi                                                                                                                                                                                                   # Colorize: green
done                                                                                                                                                                                                     # Colorize: green
                                                                                                                                                                                                         # Colorize: green
cd ${CURRENT_PATH}/                                                                                                                                                                                       # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
                                                                                                                                                                                                         # Colorize: green
echo "OK"                                                                                                                                                                                                # Colorize: green
                                                                                                                                                                                                         # Colorize: green
exit 0                                                                                                                                                                                                   # Colorize: green
