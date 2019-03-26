#!/bin/bash

# This script helps to register new server [Master Server only]
# Author: Maxim Shvecov
# Usage: sudo ./register.sh SERVER_ADDRESS SECRET_KEY



###########################################################################################
#    PARAMETERS
###########################################################################################



SERVER_ADDRESS=$1
SECRET_KEY=$2



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



if [ "${SERVER_ADDRESS}" == "" ]; then
    echo "Please specify server address."
    echo "    Usage: sudo ./register.sh SERVER_ADDRESS SECRET_KEY"

    exit 1
fi



if [ "${SECRET_KEY}" == "" ]; then
    echo "Please specify secret key."
    echo "    Usage: sudo ./register.sh SERVER_ADDRESS SECRET_KEY"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



SERVER_ID=`mysql -u root -D ngos -NB -e "SELECT id FROM servers WHERE address='${SERVER_ADDRESS}';"`

if [ "${SERVER_ID}" == "" ]; then
    mysql -u root -D ngos -e "INSERT INTO servers (address, secret_key) VALUES ('${SERVER_ADDRESS}', '${SECRET_KEY}');"
else
    mysql -u root -D ngos -e "UPDATE servers SET secret_key='${SECRET_KEY}' WHERE id=${SERVER_ID};"
fi



echo "Server \"${SERVER_ADDRESS}\" registered"



exit 0
