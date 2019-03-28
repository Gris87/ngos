#!/bin/bash

# This script helps to install NGOS webapp
# Author: Maxim Shvecov
# Usage: sudo ./install.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
FIRST_SERVER_ADDRESS=cps-etl-srv.northeurope.cloudapp.azure.com



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



mysql -u root -D ngos -e "INSERT IGNORE INTO regions (id, name) VALUES ('1', 'Ireland');"



FIRST_SERVER=`mysql -u root -D ngos -NB -e "SELECT id FROM servers WHERE address='${FIRST_SERVER_ADDRESS}';"`

if [ "${FIRST_SERVER}" == "" ]; then
    curl -k https://${FIRST_SERVER_ADDRESS}/rest/ping.php

    mysql -u root -D ngos -e "INSERT INTO servers (region_id, address, delay) VALUES ('1', '${FIRST_SERVER_ADDRESS}', '0');"
fi



cp -r html/. /var/www/html



exit 0
