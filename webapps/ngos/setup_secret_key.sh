#!/bin/bash

# This script helps to setup secret key for the Slave Server [Slave Server only]
# Author: Maxim Shvecov
# Usage: sudo ./setup_secret_key.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



SECRET_KEY=`cat /dev/urandom | tr -dc "a-zA-Z0-9" | fold -w 1000 | head -n 1`



SECRET_KEY_ID=`mysql -u root -D ngos -NB -e "SELECT id FROM properties WHERE name='secret_key';"`

if [ "${SECRET_KEY_ID}" == "" ]; then
    mysql -u root -D ngos -e "INSERT INTO properties (name, value) VALUES ('secret_key', '${SECRET_KEY}');"
else
    mysql -u root -D ngos -e "UPDATE properties SET value='${SECRET_KEY}' WHERE id=${SECRET_KEY_ID};"
fi



echo "Secret key:"
echo "${SECRET_KEY}"



exit 0
