#!/bin/bash

# This script helps to deploy latest binaries to web servers
# Author: Maxim Shvecov
# Usage: ./deploy.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
BUILD_CONFIG=include/buildconfig.h
BUILD_LOG=/tmp/ngos_deploy.log
BUILD_CFG_BACKUP=/tmp/ngos_deploy_buildconfig.h



###########################################################################################
#    FUNCTIONS
###########################################################################################



function deploy_app
{
    CODENAME=$1
    NAME=$2
    VERSION=$3
    FILEPATH=$4

    echo -n "Deploying ${NAME} (${CODENAME})    "

    CONTENT=`base64 -w 0 ${FILEPATH}`


    REQUEST_DATA=`cat << EOF
        {
            "codename": "${CODENAME}",
            "name":     "${NAME}",
            "version":  "${VERSION}",
            "content":  "${CONTENT}"
        }
EOF
    `

    echo "${REQUEST_DATA}" | curl -k -X POST -H "Content-Type: application/json" -d @- https://localhost/rest/deploy.php
    echo ""
}



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m                    Deployment\e[0m"
echo -e "\e[36m==================================================\e[0m"



echo ""
echo -e "\e[33m-------------------- Building --------------------\e[0m"
echo ""



cd ../../
cp ${BUILD_CONFIG} ${BUILD_CFG_BACKUP}



make generate > ${BUILD_LOG} 2>&1

if [ $? -ne 0 ]; then
    cat ${BUILD_LOG} 2>&1

    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
    cd ${CURRENT_PATH}/

    exit 1
fi



make release > ${BUILD_LOG} 2>&1

if [ $? -ne 0 ]; then
    cat ${BUILD_LOG} 2>&1

    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
    cd ${CURRENT_PATH}/

    exit 1
fi



tools/qt/build_config_maker/build/build_config_maker ${BUILD_CONFIG} --reset > ${BUILD_LOG} 2>&1
make all >> ${BUILD_LOG} 2>&1

if [ $? -ne 0 ]; then
    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}

    cat ${BUILD_LOG} 2>&1
    exit 1
fi



cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
cd ${CURRENT_PATH}/



echo ""
echo -e "\e[33m-------------------- Deploying -------------------\e[0m"
echo ""



VERSION=`date +%Y%m%d%H%M%S`



deploy_app "com.ngos.installer" "NGOS installer" "${VERSION}" ../../build/NGOS_installer.bin



exit 0
