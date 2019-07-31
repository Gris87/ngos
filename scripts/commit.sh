#!/bin/bash

# This script helps to simplify Git usage
# Author: Maxim Shvecov
# Usage: ./scripts/commit.sh MESSAGE



###########################################################################################
#    PARAMETERS
###########################################################################################



MESSAGE=$1



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"

    exit 1
fi



if [ "${MESSAGE}" == "" ]; then
    echo "Usage: ./scripts/commit.sh MESSAGE"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



git add .
git commit -a -m "${MESSAGE}"
./scripts/push.sh



exit 0
