#!/bin/bash

# This script helps to update ngos.files file
# Author: Maxim Shvecov
# Usage: ./update_ngos_files.sh



###########################################################################################
#    PROCESSING
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"
    exit 1
fi



find -type f | \
    grep \
        -ve /.git/ \
        -ve /ngos.config$ \
        -ve /ngos.creator$ \
        -ve /ngos.creator.user$ \
        -ve /ngos.files$ \
        -ve /ngos.includes$ | \
    git check-ignore --verbose --non-matching --stdin | \
    grep -e "^::" | \
    cut -c 6- | \
    sort > ngos.files



exit 0
