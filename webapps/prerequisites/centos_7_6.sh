#!/bin/bash

# This script helps to install webapps prerequisites on CentOS 7.6
# Author: Maxim Shvecov
# Usage: sudo ./centos_7_6.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



yum install -y redhat-lsb



if [[ "`lsb_release -rs`" != "7.6.1810" ]]; then
    echo "This script should be called on CentOS 7.6"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



echo ""
echo -e "\e[31m-------------------- TBD --------------------\e[0m"
echo ""
