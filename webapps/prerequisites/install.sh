#!/bin/bash

# This script helps to install webapps prerequisites
# Author: Maxim Shvecov
# Usage: sudo ./install.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



yum install -y redhat-lsb 2> /dev/null



###########################################################################################
#    PROCESSING
###########################################################################################



if [[ "`lsb_release -rs`" == "18.10" ]]; then
    ./ubuntu_18_10.sh
elif [[ "`lsb_release -rs`" == "18.04" ]]; then
    ./ubuntu_18_04.sh
elif [[ "`lsb_release -rs`" == "16.04" ]]; then
    ./ubuntu_16_04.sh
elif [[ "`lsb_release -rs`" == "7.6.1810" ]]; then
    ./centos_7_6.sh
else
    echo "Unknown OS"

    exit 1
fi



exit 0