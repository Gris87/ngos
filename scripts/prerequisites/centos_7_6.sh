#!/bin/bash

# This script helps to install prerequisites on CentOS 7.6
# Author: Maxim Shvecov
# Usage: sudo ./centos_7_6.sh



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



yum install -y redhat-lsb



if [[ "`lsb_release -rs`" != "7.6.1810" ]]; then
    echo "This script should be called on CentOS 7.6"

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



mkdir /tmp/src/
cd /tmp/src/
mkdir epel/
cd epel/
wget https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
yum install -y epel-release-latest-7.noarch.rpm

yum update -y
yum install -y curl
yum install -y gcc
yum install -y gcc-c++
yum install -y ncurses-devel
yum install -y libelf-devel
yum install -y bison
yum install -y flex
yum install -y gdb
yum install -y mesa-libGL-devel
yum install -y socat
yum install -y ImageMagick
yum install -y nodejs

npm i sinon --save-dev || exit 1
npm i markdown-spellcheck -g || exit 1

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"



echo ""
echo -e "\e[33m-------------------- gcc-8 --------------------\e[0m"
echo ""



mkdir /tmp/src/
cd /tmp/src/
mkdir devtoolset/
cd devtoolset/

rm *

for RPM in `curl https://cbs.centos.org/repos/sclo7-devtoolset-8-rh-release/x86_64/os/Packages/ | grep -o -E -e "href=\".*.rpm\"" | cut -d \" -f 2`
do
    wget https://cbs.centos.org/repos/sclo7-devtoolset-8-rh-release/x86_64/os/Packages/${RPM}
done

yum install -y *.rpm
source /opt/rh/devtoolset-8/enable



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



yum-builddep -y libvirt



mkdir /tmp/src
cd /tmp/src

if [ ! -d libvirt ]; then
    git clone https://github.com/libvirt/libvirt.git
fi

cd libvirt
git checkout master
git reset --hard
git clean -df
git pull
git checkout v${LIBVIRT_VERSION}
./autogen.sh || exit 1
./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var || exit 1
make -j8 all || exit 1
make install || exit 1

service libvirtd restart



echo ""
echo -e "\e[33m-------------------- libvirt-glib-${LIBVIRT_GLIB_VERSION} --------------------\e[0m"
echo ""



yum-builddep -y libvirt-glib
yum install -y gtk-doc



mkdir /tmp/src
cd /tmp/src

if [ ! -d libvirt-glib ]; then
    git clone https://github.com/libvirt/libvirt-glib.git
fi

cd libvirt-glib
git checkout master
git reset --hard
git clean -df
git pull
git checkout v${LIBVIRT_GLIB_VERSION}
./autogen.sh || exit 1
./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var || exit 1
make -j8 all || exit 1
make install || exit 1



echo ""
echo -e "\e[33m-------------------- qemu-${QEMU_VERSION} --------------------\e[0m"
echo ""



mkdir /tmp/src
cd /tmp/src

if [ ! -d qemu ]; then
    git clone https://github.com/qemu/qemu.git
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
../qemu/configure --enable-debug || exit 1
make -j8 all || exit 1
make install || exit 1



echo ""
echo -e "\e[33m-------------------- virt-manager-${VIRT_MANAGER_VERSION} --------------------\e[0m"
echo ""
