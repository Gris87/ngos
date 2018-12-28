#!/bin/bash

# This script helps to install prerequisites
# Author: Maxim Shvecov
# Usage: sudo ./install.sh



###########################################################################################
#    PROCESSING
###########################################################################################



if [[ "`lsb_release -rs`" == "18.04" ]]; then
    ./ubuntu_18_04.sh
elif [[ "`lsb_release -rs`" == "16.04" ]]; then
    ./ubuntu_16_04.sh
else
    ./centos_7.sh
fi
