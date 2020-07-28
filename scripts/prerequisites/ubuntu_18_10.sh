#!/bin/bash

# This script helps to install prerequisites on Ubuntu 18.10
# Author: Maxim Shvecov
# Usage: sudo ./ubuntu_18_10.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
BINUTILS_VERSION=2.34
GCC_VERSION=10.1.0
VIRTUALBOX_VERSION=6.1
QT_VERSION=5.15.0



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



if [[ `lsb_release -rs` != 18.10 ]]; then
    echo "This script should be called on Ubuntu 18.10"

    exit 1
fi



if [[ ${CURRENT_PATH} != /home/* ]]; then
    echo "Please run this script under your home directory"

    exit 1
fi



USER=`echo "${CURRENT_PATH}" | cut -d / -f 3`

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

apt-get update
apt-get upgrade -y
apt-get install -y build-essential
apt-get install -y texinfo
apt-get install -y gdb
apt-get install -y socat
apt-get install -y curl
apt-get install -y libgl-dev
apt-get install -y libudev-dev
apt-get install -y poppler-utils
apt-get install -y npm

ln -s /usr/bin/nodejs /usr/bin/node
npm install sinon
npm install markdown-spellcheck -g

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="${PREFIX}/bin:${PATH}"



echo ""
echo -e "\e[33m-------------------- gcc-9 --------------------\e[0m"
echo ""



add-apt-repository -y ppa:jonathonf/gcc
apt-get update
apt-get install -y gcc-9 g++-9
update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9



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
../binutils-${BINUTILS_VERSION}/configure --prefix=${PREFIX} --target=${TARGET} --disable-werror || exit 1
make -j`nproc` all                                                                               || exit 1
make install                                                                                     || exit 1



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
../gcc-${GCC_VERSION}/configure --prefix=${PREFIX} --target=${TARGET} --enable-languages=c,c++ || exit 1
make -j`nproc` all-gcc                                                                         || exit 1
make install-gcc                                                                               || exit 1
make -j`nproc` all-target-libgcc                                                               || exit 1
make install-target-libgcc                                                                     || exit 1



echo ""
echo -e "\e[33m-------------------- libvirt --------------------\e[0m"
echo ""



apt-get install -y qemu qemu-kvm libvirt-daemon bridge-utils virt-manager virtinst

systemctl enable libvirtd
systemctl restart libvirtd



echo ""
echo -e "\e[33m-------------------- virtualbox-${VIRTUALBOX_VERSION} --------------------\e[0m"
echo ""



wget -q https://www.virtualbox.org/download/oracle_vbox_2016.asc -O- | apt-key add -
wget -q https://www.virtualbox.org/download/oracle_vbox.asc      -O- | apt-key add -
apt-add-repository "deb http://download.virtualbox.org/virtualbox/debian $(lsb_release -sc) contrib"

apt-get update
apt-get install -y virtualbox-${VIRTUALBOX_VERSION}



echo ""
echo -e "\e[33m-------------------- .gdbinit --------------------\e[0m"
echo ""



cp ${CURRENT_PATH}/../../tools/gdb/.gdbinit /home/${USER}/
chown ${USER}:${USER} /home/${USER}/.gdbinit



echo ""
echo -e "\e[33m-------------------- .bashrc --------------------\e[0m"
echo ""



cat /home/${USER}/.bashrc | grep -v "/usr/local/x8664elfgcc/bin" | grep -v "~/Qt/" > /home/${USER}/temp
mv /home/${USER}/temp /home/${USER}/.bashrc
echo "export PATH=/usr/local/x8664elfgcc/bin:\${PATH}"    >> /home/${USER}/.bashrc
echo "export PATH=~/Qt/${QT_VERSION}/gcc_64/bin:\${PATH}" >> /home/${USER}/.bashrc
chown ${USER}:${USER} /home/${USER}/.bashrc



echo ""
echo -e "\e[33m-------------------- Qt --------------------\e[0m"
echo ""



cd /home/${USER}/
wget http://download.qt.io/official_releases/online_installers/qt-unified-linux-x64-online.run
chmod 755 qt-unified-linux-x64-online.run
chown ${USER}:${USER} qt-unified-linux-x64-online.run

echo -e "\e[31mPlease install Qt in your X-Window Manager\e[0m"
echo -e "\e[31m~/qt-unified-linux-x64-online.run\e[0m"
echo ""
echo -e "\e[31mPlease choose following items during Qt installation:\e[0m"
echo -e "\e[31m* Qt -> Qt ${QT_VERSION} -> Desktop gcc 64 bit\e[0m"
echo -e "\e[31m* Qt -> Qt ${QT_VERSION} -> Sources\e[0m"



echo ""
echo -e "\e[32m-------------------- Done --------------------\e[0m"
echo ""



echo "Rebooting..."
sleep 5
reboot
