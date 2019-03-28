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



cp -r html/. /var/www/html



mysql -u root < mariadb/create.sql



mysql -u root -D ngos -e "INSERT IGNORE INTO regions (id, name) VALUES ('1', 'Ireland');"



FIRST_SERVER=`mysql -u root -D ngos -NB -e "SELECT id FROM servers WHERE address='${FIRST_SERVER_ADDRESS}';"`

if [ "${FIRST_SERVER}" == "" ]; then
    PING_TOTAL=0

    for ((i = 0; i < 10; i++))
    do
        PING_RESPONSE=`curl -k -s -w "%{time_total}" https://${FIRST_SERVER_ADDRESS}/rest/ping.php`

        if [ "${PING_RESPONSE:0:15}" != "{\"status\":\"OK\"}" ]; then
            echo "Failed to ping server: ${FIRST_SERVER_ADDRESS}"

            exit 1
        fi

        PING_TOTAL=`echo "${PING_TOTAL} + ${PING_RESPONSE:15}" | bc`
    done

    DELAY=`echo "${PING_TOTAL} * 100000 / 1" | bc`

    mysql -u root -D ngos -e "INSERT INTO servers (region_id, address, delay) VALUES ('1', '${FIRST_SERVER_ADDRESS}', '${DELAY}');"
fi



exit 0
