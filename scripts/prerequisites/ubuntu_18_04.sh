#!/bin/bash

# This script helps to install prerequisites on Ubuntu 18.04
# Author: Maxim Shvecov
# Usage: sudo ./ubuntu_18_04.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
BINUTILS_VERSION=2.31.1
GCC_VERSION=8.2.0
LIBVIRT_VERSION=4.10.0
LIBVIRT_GLIB_VERSION=2.0.0
QEMU_VERSION=3.1.0
VIRT_MANAGER_VERSION=2.0.0
VIRT_VIEWER_VERSION=7.0
VIRTUALBOX_VERSION=6.0
QT_VERSION=5.12.0



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ $EUID -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



if [[ "`lsb_release -rs`" != "18.04" ]]; then
    echo "This script should be called on Ubuntu 18.04"

    exit 1
fi



USER=`pwd | cut -d / -f 3`

if [ "${USER}" == "" ]; then
    echo "Failed to detect user name"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



echo ""
echo -e "\e[33m-------------------- Environment --------------------\e[0m"
echo ""
