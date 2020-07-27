#!/bin/bash

# This script helps to install prerequisites on CentOS 8.2
# Author: Maxim Shvecov
# Usage: sudo ./centos_8_2.sh



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



yum install -y redhat-lsb



if [[ `lsb_release -rs` != 8.2.* ]]; then
    echo "This script should be called on CentOS 8.2"

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
mkdir epel/
cd epel/
wget https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
yum install -y epel-release-latest-8.noarch.rpm

yum update -y
yum group install -y "Development Tools"
yum --enablerepo=PowerTools install -y texinfo
yum install -y gdb
yum install -y socat
yum install -y mesa-libGL-devel
yum install -y libudev-devel
yum install -y poppler-utils
yum install -y npm

npm install sinon
npm install markdown-spellcheck -g

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="${PREFIX}/bin:${PATH}"



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



yum install -y qemu-kvm qemu-img libvirt libvirt-client virt-install virt-manager virt-viewer

systemctl enable libvirtd
systemctl restart libvirtd



echo ""
echo -e "\e[33m-------------------- virtualbox-${VIRTUALBOX_VERSION} --------------------\e[0m"
echo ""



cd /etc/yum.repos.d
wget http://download.virtualbox.org/virtualbox/rpm/rhel/virtualbox.repo

yum --enablerepo=epel install -y dkms

yum install -y kernel-devel

yum install -y VirtualBox-${VIRTUALBOX_VERSION}



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
