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

    curl -k -s -X POST -H "Content-Type: application/json" -d @- ${SERVER} || return 1

    return 0
}



function execute_sql_without_header
{
    SQL=$1

    mysql -u ngos -pngos -D ngos -NB -e "${SQL}" || return 1

    return 0
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

    echo "${REQUEST_DATA}" | send_post_request https://localhost/rest/deploy_file.php
    echo ""



    return 0
}



function deploy_app
{
    CODENAME=$1
    NAME=$2
    VERSION=$3

    echo "Deploying ${NAME} (${CODENAME})"



    SECRET_KEY=`execute_sql_without_header "SELECT secret_key FROM apps WHERE codename = '${CODENAME}';" | tr -dc "a-zA-Z0-9"`

    if [ "${SECRET_KEY}" == "" ]; then
        SECRET_KEY=`cat /dev/urandom | tr -dc "a-zA-Z0-9" | fold -w 1000 | head -n 1`
    elif [ ${#SECRET_KEY} -ne 1000 ]; then
        echo "Secret key is invalid. Please generate new secret key"

        return 1
    fi



    REQUEST_DATA=`cat << EOF
        {
            "vendor_id":   1,
            "codename":    "${CODENAME}",
            "owner_email": "admin@ngos.com",
            "name":        "${NAME}",
            "version":     ${VERSION},
            "secret_key":  "${SECRET_KEY}"
        }
EOF
    `

    DEPLOYMENT_RESPONSE=`echo "${REQUEST_DATA}" | send_post_request https://localhost/rest/deploy_app.php`



    if [ "`echo ${DEPLOYMENT_RESPONSE} | jq -r .status`" != "OK" ]; then
        echo "Failed to deploy ${NAME} (${CODENAME}) : ${DEPLOYMENT_RESPONSE}"

        return 1
    fi



    APP_ID=`echo ${DEPLOYMENT_RESPONSE} | jq -r .app_id`
    APP_VERSION_ID=`echo ${DEPLOYMENT_RESPONSE} | jq -r .app_version_id`



    APP_DIR=../../build/deployment/${CODENAME}/
    APP_DIR_LENGTH=${#APP_DIR}

    for file in `find ${APP_DIR} -type f`
    do
        echo ${file:${APP_DIR_LENGTH}}
    done



    return 0
}



function deploy_all
{
    echo ""
    echo -e "\e[33m-------------------- Deploying -------------------\e[0m"
    echo ""



    VERSION=`date +%Y%m%d%H%M%S`



    deploy_app "com.ngos.kernel"    "NGOS kernel"    "${VERSION}" || return 1
    deploy_app "com.ngos.installer" "NGOS installer" "${VERSION}" || return 1



    return 0
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
        cd ${CURRENT_PATH}/

        return 1
    fi



    cp ${BUILD_CFG_BACKUP} ${BUILD_CONFIG}
    cd ${CURRENT_PATH}/



    return 0
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
