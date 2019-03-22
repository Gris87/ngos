#!/bin/bash

# This script helps to install NGOS webapp
# Author: Maxim Shvecov
# Usage: sudo ./install.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ $EUID -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



APACHE_VERSION=`apache2 -v`

if [ "$APACHE_VERSION" == "" ]; then
    cd ../prerequisites/
    ./install.sh
    cd ${CURRENT_PATH}
fi



###########################################################################################
#    PROCESSING
###########################################################################################



mysql -u root < mariadb/create.sql

cp -r html/. /var/www/html



exit 0
