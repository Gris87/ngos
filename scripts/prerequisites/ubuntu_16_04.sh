#!/bin/bash

# This script helps to install prerequisites on Ubuntu 16.04
# Author: Maxim Shvecov
# Usage: sudo ./ubuntu_16_04.sh



###########################################################################################
#    VERIFICATION
###########################################################################################



if [[ "`lsb_release -rs`" != "16.04" ]]; then
    echo "This script should be called on Ubuntu 16.04"

    exit 1
fi



if [ $EUID -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################



echo ""
echo -e "\e[33m-------------------- Environment --------------------\e[0m"
echo ""



apt-get update
apt-get upgrade -y
apt-get install -y curl
apt-get install -y build-essential
apt-get install -y build-dep
apt-get install -y libncurses-dev
apt-get install -y libelf-dev
apt-get install -y bison
apt-get install -y flex
apt-get install -y gdb
apt-get install -y libgl-dev
apt-get install -y socat
apt-get install -y imagemagick
apt-get install -y npm

ln -s /usr/bin/nodejs /usr/bin/node
npm i markdown-spellcheck -g || exit 1

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"



echo ""
echo -e "\e[33m-------------------- gcc-8 --------------------\e[0m"
echo ""



add-apt-repository -y ppa:jonathonf/gcc
apt-get update
apt-get install -y gcc-8 g++-8
update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 80 --slave /usr/bin/g++ g++ /usr/bin/g++-8



echo ""
echo -e "\e[33m-------------------- binutils-2.31.1 --------------------\e[0m"
echo ""



mkdir /tmp/src
cd /tmp/src
curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.31.1.tar.xz
tar xf binutils-2.31.1.tar.xz
mkdir binutils-build
cd binutils-build
../binutils-2.31.1/configure --prefix=$PREFIX --target=$TARGET --disable-werror 2>&1 | tee configure.log || exit 1
make -j8 all 2>&1 | tee make.log || exit 1
make install || exit 1



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
../gcc-8.2.0/configure --prefix=$PREFIX --target=$TARGET --enable-languages=c,c++ | tee configure.log || exit 1
make -j8 all-gcc 2>&1 | tee make-gcc.log || exit 1
make install-gcc || exit 1
make -j8 all-target-libgcc 2>&1 | tee make-libgcc.log || exit 1
make install-target-libgcc || exit 1



echo ""
echo -e "\e[33m-------------------- libvirt- --------------------\e[0m"
echo ""










echo ""
echo -e "\e[32m-------------------- Done --------------------\e[0m"
echo ""

