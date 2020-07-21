#!/bin/bash

# This script helps to install prerequisites on Ubuntu 19.10
# Author: Maxim Shvecov
# Usage: sudo ./ubuntu_19_10.sh



###########################################################################################
#    PARAMETERS
###########################################################################################



CURRENT_PATH=`pwd`
BINUTILS_VERSION=2.34
GCC_VERSION=10.1.0
LIBVIRT_VERSION=6.5.0
LIBVIRT_GLIB_VERSION=3.0.0
QEMU_VERSION=5.0.0
VIRT_MANAGER_VERSION=2.2.1
VIRT_VIEWER_VERSION=9.0
OVMF_VERSION=edk2-stable202005
VIRTUALBOX_VERSION=6.0
QT_VERSION=5.15.0



###########################################################################################
#    VERIFICATION
###########################################################################################



if [ ${EUID} -ne 0 ]; then
    echo "Please run as root"

    exit 1
fi



if [[ "`lsb_release -rs`" != "19.10" ]]; then
    echo "This script should be called on Ubuntu 19.10"

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

sed -i "s/^# deb-src /deb-src /" /etc/apt/sources.list
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
apt-get install -y efitools
apt-get install -y sbsigntool
apt-get install -y cmake
apt-get install -y texinfo

ln -s /usr/bin/nodejs /usr/bin/node
npm i sinon --save-dev       || exit 1
npm i markdown-spellcheck -g || exit 1

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="${PREFIX}/bin:${PATH}"



echo ""
echo -e "\e[33m-------------------- gcc-9.3 --------------------\e[0m"
echo ""



add-apt-repository -y ppa:jonathonf/gcc-9.3
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
../binutils-${BINUTILS_VERSION}/configure --prefix=${PREFIX} --target=${TARGET} --disable-werror 2>&1 | tee configure.log || exit 1
make -j`nproc` all 2>&1 | tee make.log || exit 1
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
../gcc-${GCC_VERSION}/configure --prefix=${PREFIX} --target=${TARGET} --enable-languages=c,c++ | tee configure.log || exit 1
make -j`nproc` all-gcc 2>&1 | tee make-gcc.log || exit 1
make install-gcc || exit 1
make -j`nproc` all-target-libgcc 2>&1 | tee make-libgcc.log || exit 1
make install-target-libgcc || exit 1



echo ""
echo -e "\e[33m-------------------- libvirt-${LIBVIRT_VERSION} --------------------\e[0m"
echo ""



apt-get build-dep -y libvirt
apt install -y python-pip
pip install rst2html5



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
git reset --hard v${LIBVIRT_VERSION}
cd ..

mkdir libvirt-build
cd libvirt-build
../libvirt/autogen.sh || exit 1
../libvirt/configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var || exit 1
make -j`nproc` all || exit 1
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
git reset --hard v${LIBVIRT_GLIB_VERSION}
cd ..

mkdir libvirt-glib-build
cd libvirt-glib-build
../libvirt-glib/autogen.sh || exit 1
../libvirt-glib/configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var || exit 1
make -j`nproc` all || exit 1
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
git reset --hard v${QEMU_VERSION}
cd ..

mkdir qemu-build
cd qemu-build
../qemu/configure --enable-debug || exit 1
make -j`nproc` all || exit 1
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
make -j`nproc` all || exit 1
make install || exit 1



rm /usr/lib/x86_64-linux-gnu/libvirt*
systemctl restart libvirtd



echo ""
echo -e "\e[33m-------------------- OVMF-${OVMF_VERSION} --------------------\e[0m"
echo ""



apt-get install -y nasm iasl



cd /usr/local/

if [ ! -d edk2 ]; then
    git clone https://github.com/tianocore/edk2.git
    cd edk2
    git submodule update --init
    cd ..
fi

cd edk2
git checkout master
git reset --hard
git clean -df
git pull
git reset --hard ${OVMF_VERSION}
git submodule update

source edksetup.sh BaseTools || exit 1
make -C BaseTools/ || exit 1
build -a X64 -t GCC5 -b DEBUG -n `nproc` -p OvmfPkg/OvmfPkgX64.dsc || exit 1



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
echo -e "\e[33m-------------------- AppArmor --------------------\e[0m"
echo ""



update-rc.d apparmor disable



echo ""
echo -e "\e[32m-------------------- Done --------------------\e[0m"
echo ""



echo "AppArmor disabled. Rebooting..."
sleep 5
reboot