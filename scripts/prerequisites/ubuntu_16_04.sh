#!/bin/bash

# This script helps to install prerequisites on Ubuntu 16.04
# Author: Maxim Shvecov
# Usage: sudo ./ubuntu_16_04.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
BINUTILS_VERSION=2.31.1
GCC_VERSION=8.2.0
LIBVIRT_VERSION=4.10.0
QEMU_VERSION=3.1.0
VIRTUALBOX_VERSION=6.0



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


USER=`pwd | cut -d / -f 3`

if [ "${USER}" == "" ]; then
    echo "Failed to detect user name"

    exit 1
fi



###########################################################################################
#    PROCESSING
###########################################################################################

if [ -d sdfsd ]; then

echo ""
echo -e "\e[33m-------------------- Environment --------------------\e[0m"
echo ""



apt-get update
apt-get upgrade -y
apt-get install -y curl
apt-get install -y build-essential
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
echo -e "\e[33m-------------------- binutils-${BINUTILS_VERSION} --------------------\e[0m"
echo ""



mkdir /tmp/src
cd /tmp/src

if [ ! -d binutils-${BINUTILS_VERSION} ]; then
    curl -O http://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.xz
    tar xf binutils-${BINUTILS_VERSION}.tar.xz
fi

mkdir binutils-build
cd binutils-build
../binutils-${BINUTILS_VERSION}/configure --prefix=$PREFIX --target=$TARGET --disable-werror 2>&1 | tee configure.log || exit 1
make -j8 all 2>&1 | tee make.log || exit 1
make install || exit 1



echo ""
echo -e "\e[33m-------------------- gcc-${GCC_VERSION} --------------------\e[0m"
echo ""



mkdir /tmp/src
cd /tmp/src

if [ ! -d gcc-${GCC_VERSION} ]; then
    curl -O https://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/gcc-${GCC_VERSION}.tar.xz
    tar xf gcc-${GCC_VERSION}.tar.xz
fi

cd gcc-${GCC_VERSION}
contrib/download_prerequisites
cd ..
mkdir gcc-build
cd gcc-build
../gcc-${GCC_VERSION}/configure --prefix=$PREFIX --target=$TARGET --enable-languages=c,c++ | tee configure.log || exit 1
make -j8 all-gcc 2>&1 | tee make-gcc.log || exit 1
make install-gcc || exit 1
make -j8 all-target-libgcc 2>&1 | tee make-libgcc.log || exit 1
make install-target-libgcc || exit 1



echo ""
echo -e "\e[33m-------------------- libvirt-${LIBVIRT_VERSION} --------------------\e[0m"
echo ""



apt-get build-dep -y libvirt



mkdir /tmp/src
cd /tmp/src

if [ ! -d libvirt ]; then
    git clone git://libvirt.org/libvirt.git
fi

cd libvirt
git checkout master
git reset --hard
git clean -df
git pull
git checkout v${LIBVIRT_VERSION}
./autogen.sh --system
./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var
make -j8 all
make install

fi

echo ""
echo -e "\e[33m-------------------- qemu-${QEMU_VERSION} --------------------\e[0m"
echo ""



apt-get install -y libpixman-1-dev



mkdir /tmp/src
cd /tmp/src

if [ ! -d qemu ]; then
    git clone git://git.qemu-project.org/qemu.git
fi

cd qemu
git checkout master
git reset --hard
git clean -df
git pull
git checkout v${QEMU_VERSION}
cd ..

mkdir qemu-build
cd qemu-build
../qemu/configure --enable-debug
make -j8 all
make install



echo ""
echo -e "\e[33m-------------------- virtualbox-${VIRTUALBOX_VERSION} --------------------\e[0m"
echo ""



wget -q https://www.virtualbox.org/download/oracle_vbox_2016.asc -O- | apt-key add -
wget -q https://www.virtualbox.org/download/oracle_vbox.asc -O- | apt-key add -
apt-add-repository "deb http://download.virtualbox.org/virtualbox/debian $(lsb_release -sc) contrib"

apt-get update
apt-get install -y virtualbox-${VIRTUALBOX_VERSION}



echo ""
echo -e "\e[33m-------------------- .gdbinit --------------------\e[0m"
echo ""



cp ${CURRENT_PATH}/../../tools/gdb/.gdbinit /home/#{USER}/
chown ${USER}:${USER} /home/#{USER}/.gdbinit



echo ""
echo -e "\e[33m-------------------- .bashrc --------------------\e[0m"
echo ""



cat /home/${USER}/.bashrc | grep -v "/usr/local/x8664elfgcc/bin" | grep -v "~/Qt/" >> /home/${USER}/temp
mv /home/${USER}/temp /home/${USER}/.bashrc
echo "export PATH=/usr/local/x8664elfgcc/bin:\$PATH" >> /home/${USER}/.bashrc
echo "export PATH=~/Qt/5.11.1/gcc_64/bin:\$PATH"     >> /home/${USER}/.bashrc



echo ""
echo -e "\e[32m-------------------- Done --------------------\e[0m"
echo ""

