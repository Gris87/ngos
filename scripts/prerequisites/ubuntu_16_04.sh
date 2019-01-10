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



if [[ "`lsb_release -rs`" != "16.04" ]]; then
    echo "This script should be called on Ubuntu 16.04"

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
npm i sinon --save-dev || exit 1
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

systemctl enable libvirtd
systemctl restart libvirtd



echo ""
echo -e "\e[33m-------------------- libvirt-glib-${LIBVIRT_GLIB_VERSION} --------------------\e[0m"
echo ""



apt-get build-dep -y libvirt-glib
apt-get install -y gtk-doc-tools



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



apt-get install -y libpixman-1-dev



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



apt-get install -y intltool libgtk2.0-bin python3-pip libosinfo-1.0
pip3 install libvirt-python
pip3 install libxml2-python3



mkdir /tmp/src
cd /tmp/src

if [ ! -d virt-manager-${VIRT_MANAGER_VERSION} ]; then
    wget https://virt-manager.org/download/sources/virt-manager/virt-manager-${VIRT_MANAGER_VERSION}.tar.gz
    tar xf virt-manager-${VIRT_MANAGER_VERSION}.tar.gz
fi

cd virt-manager-${VIRT_MANAGER_VERSION}/
./setup.py install || exit 1



echo ""
echo -e "\e[33m-------------------- virt-viewer-${VIRT_VIEWER_VERSION} --------------------\e[0m"
echo ""



apt-get install -y libgtk-vnc-2.0-dev



mkdir /tmp/src
cd /tmp/src

if [ ! -d virt-viewer-${VIRT_VIEWER_VERSION} ]; then
    wget https://virt-manager.org/download/sources/virt-viewer/virt-viewer-${VIRT_VIEWER_VERSION}.tar.gz
    tar xf virt-viewer-${VIRT_VIEWER_VERSION}.tar.gz
fi

cd virt-viewer-${VIRT_VIEWER_VERSION}/
./configure || exit 1
make -j8 all || exit 1
make install || exit 1



rm /usr/lib/x86_64-linux-gnu/libvirt*
systemctl restart libvirtd



echo ""
echo -e "\e[33m-------------------- OVMF --------------------\e[0m"
echo ""



apt-get install -y alien



mkdir /tmp/src
cd /tmp/src
mkdir edk2_git
cd edk2_git
wget https://www.kraxel.org/repos/jenkins/edk2/`curl https://www.kraxel.org/repos/jenkins/edk2/ 2> /dev/nill | grep -o -e "edk2.git-ovmf-x64-.*.rpm\"" | rev | cut -c 2- | rev`
alien *.rpm
dpkg -i *.deb



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



cp ${CURRENT_PATH}/../../tools/gdb/.gdbinit /home/${USER}/
chown ${USER}:${USER} /home/${USER}/.gdbinit



echo ""
echo -e "\e[33m-------------------- .bashrc --------------------\e[0m"
echo ""



cat /home/${USER}/.bashrc | grep -v "/usr/local/x8664elfgcc/bin" | grep -v "~/Qt/" > /home/${USER}/temp
mv /home/${USER}/temp /home/${USER}/.bashrc
echo "export PATH=/usr/local/x8664elfgcc/bin:\$PATH" >> /home/${USER}/.bashrc
echo "export PATH=~/Qt/${QT_VERSION}/gcc_64/bin:\$PATH"     >> /home/${USER}/.bashrc
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
echo -e "\e[33m-------------------- AppArmor --------------------\e[0m"
echo ""



update-rc.d apparmor disable



echo ""
echo -e "\e[32m-------------------- Done --------------------\e[0m"
echo ""



echo "AppArmor disabled. Rebooting..."
sleep 5
reboot
