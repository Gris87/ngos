#!/bin/bash

# This script helps to install webapps
# Author: Maxim Shvecov
# Usage: sudo ./install.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



APACHE_VERSION=`apache2 -v`

if [ "${APACHE_VERSION}" == "" ]; then
    cd prerequisites/
    ./install.sh
    cd ${CURRENT_PATH}
fi



###########################################################################################
#    PROCESSING
###########################################################################################



cd ngos/
./install.sh
cd ${CURRENT_PATH}



exit 0
