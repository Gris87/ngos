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



echo ""
echo -e "\e[33m-------------------- Environment --------------------\e[0m"
echo ""



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

sudo ln -s /usr/bin/nodejs /usr/bin/node
sudo npm i markdown-spellcheck -g

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"



echo ""
echo -e "\e[33m-------------------- binutils-2.31.1 --------------------\e[0m"
echo ""



mkdir /tmp/src
cd /tmp/src
curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.31.1.tar.xz
tar xf binutils-2.31.1.tar.xz
mkdir binutils-build
cd binutils-build
../binutils-2.31.1/configure --prefix=$PREFIX --target=$TARGET --disable-werror 2>&1 | tee configure.log
make -j8 all 2>&1 | tee make.log
make install



echo ""
echo -e "\e[33m-------------------- gcc-8.2.0 --------------------\e[0m"
echo ""



mkdir /tmp/src
cd /tmp/src
curl -O https://ftp.gnu.org/gnu/gcc/gcc-8.2.0/gcc-8.2.0.tar.xz
tar xf gcc-8.2.0.tar.xz
cd gcc-8.2.0
contrib/download_prerequisites
cd ..
mkdir gcc-build
cd gcc-build
../gcc-8.2.0/configure --prefix=$PREFIX --target=$TARGET --enable-languages=c,c++ | tee configure.log
make -j8 all-gcc 2>&1 | tee make-gcc.log
make install-gcc
make -j8 all-target-libgcc 2>&1 | tee make-libgcc.log
make install-target-libgcc



echo ""
echo -e "\e[33m-------------------- libvirt- --------------------\e[0m"
echo ""











