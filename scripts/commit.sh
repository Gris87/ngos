#!/bin/bash

# This script helps to simplify Git usage
# Author: Maxim Shvecov
# Usage: ./commit.sh MESSAGE



###########################################################################################
#    PROCESSING
###########################################################################################



if [ ! -f ngos.files ]; then
    echo "Please run this script from the root folder"
    exit 1
fi



if [ -z "$1" ]; then
    echo "Usage: ./commit.sh MESSAGE"
    exit 2
else
    git add .
    git commit -a -m "$1"
    ./scripts/push.sh
fi



exit 0
