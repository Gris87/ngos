#!/bin/bash

# This script helps to install NGOS webapp
# Author: Maxim Shvecov
# Usage: sudo ./install.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
FIRST_SERVER_ADDRESS=10.83.230.9



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



APACHE_VERSION=`apache2 -v`

if [ "${APACHE_VERSION}" == "" ]; then
    cd ../prerequisites/
    ./install.sh
    cd ${CURRENT_PATH}
fi



###########################################################################################
#    PROCESSING
###########################################################################################



mysql -u root < mariadb/create.sql

FIRST_SERVER=`mysql -u root -D ngos -NB -e "SELECT id FROM servers WHERE address=\"${FIRST_SERVER_ADDRESS}\";"`

if [ "${FIRST_SERVER}" == "" ]; then
    mysql -u root -D ngos -e "INSERT INTO servers (address) VALUES (\"${FIRST_SERVER_ADDRESS}\");"
fi



cp -r html/. /var/www/html



exit 0
