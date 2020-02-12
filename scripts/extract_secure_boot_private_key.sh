#!/bin/bash

# This script helps to extract generated private key for Secure Boot
# Author: Maxim Shvecov
# Usage: ./scripts/extract_secure_boot_private_key.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



if [ ! -f secure_boot/keys/ISK.key ]; then
    gpg -d -o secure_boot/keys/ISK.key secure_boot/keys/ISK.key.gpg
else
    echo "Secure boot private key already extracted"
fi



exit 0
