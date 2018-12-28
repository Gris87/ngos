#!/bin/bash

# This script helps to install prerequisites on CentOS 7
# Author: Maxim Shvecov
# Usage: ./centos_7.sh



###########################################################################################
#    PROCESSING
###########################################################################################



if [[ "`lsb_release -rs`" != "7" ]]; then
    echo "This script should be called on CentOS 7"

    exit 1
fi
