#!/bin/bash

# This script helps to install prerequisites on Ubuntu 16.04
# Author: Maxim Shvecov
# Usage: ./ubuntu_16_04.sh



###########################################################################################
#    PROCESSING
###########################################################################################



if [[ "`lsb_release -rs`" != "16.04" ]]; then
    echo "This script should be called on Ubuntu 16.04"

    exit 1
fi



sudo apt-get update
sudo apt-get upgrade -y
sudo apt-get install -y curl
sudo apt-get install -y build-essential
sudo apt-get install -y libncurses-dev
sudo apt-get install -y libelf-dev
sudo apt-get install -y bison
sudo apt-get install -y flex
sudo apt-get install -y gdb
sudo apt-get install -y libgl-dev
sudo apt-get install -y socat
sudo apt-get install -y imagemagick
sudo apt-get install -y npm

