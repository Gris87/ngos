#!/bin/bash

# This script helps to install prerequisites on Ubuntu 18.04
# Author: Maxim Shvecov
# Usage: ./ubuntu_18_04.sh



###########################################################################################
#    PROCESSING
###########################################################################################



if [[ "`lsb_release -rs`" != "18.04" ]]; then
    echo "This script should be called on Ubuntu 18.04"

    exit 1
fi
