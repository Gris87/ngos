#!/bin/bash

# This script helps to sign UEFI applications with the keys for Secure Boot
# Author: Maxim Shvecov
# Usage: ./scripts/sign_uefi_application.sh PATH_TO_UNSIGNED PATH_TO_SIGNED



###########################################################################################
#    PARAMETERS
###########################################################################################



PATH_TO_UNSIGNED=$1
PATH_TO_SIGNED=$2



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"

    exit 1
fi



if [ "${PATH_TO_UNSIGNED}" == "" ]; then
    echo "Usage: ./scripts/sign_uefi_application.sh PATH_TO_UNSIGNED PATH_TO_SIGNED"

    exit 1
fi



if [ "${PATH_TO_SIGNED}" == "" ]; then
    echo "Usage: ./scripts/sign_uefi_application.sh PATH_TO_UNSIGNED PATH_TO_SIGNED"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



if [ -f secure_boot/keys/ISK.key ]; then
    sbsign --key secure_boot/keys/ISK.key --cert secure_boot/keys/ISK.pem --output ${PATH_TO_SIGNED} ${PATH_TO_UNSIGNED}

    rm ${PATH_TO_UNSIGNED}
else
    echo -e "\e[31mSecure boot private key is unavailable. Please run ./scripts/extract_secure_boot_private_key.sh\e[0m"

    mv ${PATH_TO_UNSIGNED} ${PATH_TO_SIGNED}
fi



exit 0
