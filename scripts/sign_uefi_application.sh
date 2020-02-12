#!/bin/bash

# This script helps to sign UEFI applications with the keys for Secure Boot
# Author: Maxim Shvecov
# Usage: ./scripts/sign_uefi_application.sh APPLICATION_PATH



###########################################################################################
#    PARAMETERS
###########################################################################################



APPLICATION_PATH=$1



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"

    exit 1
fi



if [ "${APPLICATION_PATH}" == "" ]; then
    echo "Usage: ./scripts/sign_uefi_application.sh APPLICATION_PATH"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



if [ -f secure_boot/keys/ISK.key ]; then
    sbsign --key secure_boot/keys/ISK.key --cert secure_boot/keys/ISK.pem --output ${APPLICATION_PATH} ${APPLICATION_PATH}
else
    echo "Secure boot private key is unavailable. Please run ./scripts/extract_secure_boot_private_key.sh" 1>&2
fi



exit 0
