NGOS
====

0.2.1. Install prerequisites on CentOS 7
----------------------------------------

You need the following software to be able to build NGOS.
* CentOS 7
* binutils-2.31
* gcc-8.2.0
* qemu
* ovmf
* VirtualBox
* Qt
* Qt Creator

Please follow instructions below in order to obtain the required software

VNC
---

If you need to install VNC server please use the following instruction:

```sh
sudo su
yum update -y
yum groupinstall -y "Server with GUI"
yum install -y tigervnc-server

firewall-cmd --permanent --zone=public --add-service vnc-server
firewall-cmd --reload
```

After this run command with your user account:

```sh
vncserver
```

Environment
-----------

Please call these commands before installing binutils and gcc

```sh
sudo su
mkdir /tmp/src/
cd /tmp/src/
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

npm i markdown-spellcheck -g
```

binutils
--------

Please prepare environment before calling these commands

```sh
sudo su

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"

mkdir /tmp/src
cd /tmp/src
curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.31.tar.xz
tar xf binutils-2.31.tar.xz
mkdir binutils-build
cd binutils-build
../binutils-2.31/configure --prefix=$PREFIX --target=$TARGET --disable-werror 2>&1 | tee configure.log
make -j8 all 2>&1 | tee make.log
make install
```

gcc
---

Please prepare environment before calling these commands

```sh
sudo su

export PREFIX="/usr/local/x8664elfgcc"
export TARGET=x86_64-elf
export PATH="$PREFIX/bin:$PATH"

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
```

QEMU + OVMF
-----------

```sh
sudo su
yum install -y intltool
yum install -y libosinfo libvirt-python libvirt-glib openssh-askpass python-ipaddr spice-gtk-python spice-gtk3
yum install -y kvm qemu-kvm qemu-img virt-manager libvirt libvirt-client libguestfs-tools virt-install virt-viewer bridge-utils
yum install -y OVMF

systemctl start libvirtd
systemctl enable libvirtd

setfacl -m u:qemu:rx /home/*/



cd /etc/yum.repos.d/ && wget http://www.kraxel.org/repos/firmware.repo
yum install -y edk2.git-ovmf-x64



mkdir /tmp/src
cd /tmp/src
wget https://virt-manager.org/download/sources/virt-manager/virt-manager-1.5.1.tar.gz
tar xf virt-manager-1.5.1.tar.gz
cd virt-manager-1.5.1/
python setup.py install
```

VirtualBox
----------

```sh
sudo su
cd /etc/yum.repos.d
wget http://download.virtualbox.org/virtualbox/rpm/rhel/virtualbox.repo

yum --enablerepo=epel install -y dkms

yum groupinstall -y "Development Tools"
yum install -y kernel-devel

yum install -y VirtualBox-5.2
```

Qt + Qt Creator
---------------

Execute commands below in the X11 terminal with your user account

```sh
cd ~/
wget http://download.qt.io/official_releases/online_installers/qt-unified-linux-x64-online.run
chmod 755 qt-unified-linux-x64-online.run
./qt-unified-linux-x64-online.run
rm qt-unified-linux-x64-online.run
```

Please choose following items during Qt installation:
* Qt -> Qt 5.11.1 -> Desktop gcc 64 bit
* Qt -> Qt 5.11.1 -> Sources

Post processing
---------------

Execute these commands with your user account

```sh
cat ~/.bashrc | grep -v "/usr/local/x8664elfgcc/bin" | grep -v "~/Qt/" >> ~/temp
mv ~/temp ~/.bashrc
echo "export PATH=/usr/local/x8664elfgcc/bin:\$PATH" >> ~/.bashrc
echo "export PATH=~/Qt/5.11.1/gcc_64/bin:\$PATH"     >> ~/.bashrc
source ~/.bashrc

cd ~/workspace/ngos/tools/gdb
./install.sh
```
