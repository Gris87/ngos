#!/bin/bash

# This script start kernel testing
# Author: Maxim Shvecov
# Usage: ./start.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
BUILD_LOG=/tmp/ngos_test.log
BUILD_CFG_BACKUP=/tmp/ngos_buildconfig.h



###########################################################################################
#    PROCESSING
###########################################################################################



cd ../

cp include/buildconfig.h ${BUILD_CFG_BACKUP}

make generate > ${BUILD_LOG} 2>&1

if [ $? -ne 0 ]; then
    cat ${BUILD_LOG} 2>&1

    cp ${BUILD_CFG_BACKUP} include/buildconfig.h
    cd ${CURRENT_PATH}/

    exit 1
fi

make test-debug > ${BUILD_LOG} 2>&1

if [ $? -ne 0 ]; then
    cat ${BUILD_LOG} 2>&1

    cp ${BUILD_CFG_BACKUP} include/buildconfig.h
    cd ${CURRENT_PATH}/

    exit 1
fi

cd ${CURRENT_PATH}/



echo -e "\e[94mTesting started\e[0m"

mkdir logs/ 2> /dev/null

for file in tests/*.sh;
do
    SHELL_SCRIPT=$(basename "${file}")
    TEST_NAME="${SHELL_SCRIPT%.*}"
    TEST_NAME_LENGTH=${#TEST_NAME}



    echo -n "${TEST_NAME}..."
    printf "%$((40 - TEST_NAME_LENGTH))s" ""

    cd tests/
    "./${SHELL_SCRIPT}" > "../logs/${SHELL_SCRIPT}.log" 2>&1
    EXIT_CODE=$?
    cd ${CURRENT_PATH}/



    if [ ${EXIT_CODE} -ne 0 ]; then
        echo -e "[\e[31mError\e[0m]"
        echo ""

        cat "logs/${SHELL_SCRIPT}.log"



        cp ${BUILD_CFG_BACKUP} ../include/buildconfig.h

        exit ${EXIT_CODE}
    fi

    echo -e "[\e[32mOK\e[0m]"
done



cp ${BUILD_CFG_BACKUP} ../include/buildconfig.h

exit 0
