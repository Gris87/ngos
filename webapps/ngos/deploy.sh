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
#    PROCESSING
###########################################################################################



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



exit 0
