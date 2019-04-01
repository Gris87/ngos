#!/bin/bash

# This script helps to deploy latest binaries to web servers
# Author: Maxim Shvecov
# Usage: ./deploy.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
BUILD_CONFIG=include/buildconfig.h
BUILD_CFG_BACKUP=/tmp/ngos_deploy_buildconfig.h



###########################################################################################
#    FUNCTIONS
###########################################################################################



function send_post_request
{
    SERVER=$1

    curl -k -s -X POST -H "Content-Type: application/json" -d @- ${SERVER}
}



function deploy_app_file
{
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

    echo "${REQUEST_DATA}" | send_post_request https://localhost/rest/deploy.php
    echo ""
}



function deploy_app
{
    CODENAME=$1
    NAME=$2
    VERSION=$3

    echo "Deploying ${NAME} (${CODENAME})"



    REQUEST_DATA=`cat << EOF
        {
            "codename": "${CODENAME}",
            "name":     "${NAME}",
            "version":  "${VERSION}"
        }
EOF
    `

    echo "${REQUEST_DATA}" | send_post_request https://localhost/rest/deploy.php
    echo ""



    APP_DIR=../../build/deployment/${CODENAME}/
    APP_DIR_LENGTH=${#APP_DIR}

    for file in `find ${APP_DIR} -type f`
    do
        echo ${file:${APP_DIR_LENGTH}}
    done
}



function deploy_all
{
    echo ""
    echo -e "\e[33m-------------------- Deploying -------------------\e[0m"
    echo ""



    VERSION=`date +%Y%m%d%H%M%S`



    deploy_app "com.ngos.kernel"    "NGOS kernel"    "${VERSION}"
    deploy_app "com.ngos.installer" "NGOS installer" "${VERSION}"
}



function prepare_for_deployment
{
    echo ""
    echo -e "\e[33m-------------------- Building --------------------\e[0m"
    echo ""



    cd ../../
    cp ${BUILD_CONFIG} ${BUILD_CFG_BACKUP}



    make generate

    if [ $? -ne 0 ]; then
        cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
        cd ${CURRENT_PATH}/

        return 1
    fi



    make release

    if [ $? -ne 0 ]; then
        cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
        cd ${CURRENT_PATH}/

        return 1
    fi



    tools/qt/build_config_maker/build/build_config_maker ${BUILD_CONFIG} --reset
    make all

    if [ $? -ne 0 ]; then
        cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}

        return 1
    fi



    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
    cd ${CURRENT_PATH}/
}



###########################################################################################
#    PROCESSING
###########################################################################################



echo -e "\e[36m==================================================\e[0m"
echo -e "\e[36m                    Deployment\e[0m"
echo -e "\e[36m==================================================\e[0m"



prepare_for_deployment || exit 1
deploy_all             || exit 1



echo ""
echo -e "\e[32m-------------------- Done --------------------\e[0m"
echo ""



exit 0
