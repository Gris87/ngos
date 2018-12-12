#!/bin/bash

# This script helps to start VM with a specified VIRTUAL_MANAGER
# Author: Maxim Shvecov
# Usage: ./start_vm.sh VIRTUAL_MANAGER [DISPLAY_TYPE] [OS_TYPE]



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
VIRTUAL_MANAGER=$1
DISPLAY_TYPE=$2
OS_TYPE=$3



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ "${VIRTUAL_MANAGER}" == "" ]; then
    echo "Please specify virtual manager."
    echo "    Usage: ./start_vm.sh VIRTUAL_MANAGER [DISPLAY_TYPE] [OS_TYPE]"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



cd ${VIRTUAL_MANAGER}/
./start.sh 1024 ${DISPLAY_TYPE} ${OS_TYPE}
cd ${CURRENT_PATH}/



exit 0
