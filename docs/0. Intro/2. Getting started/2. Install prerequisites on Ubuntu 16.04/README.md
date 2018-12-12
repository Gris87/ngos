NGOS
====

0.2.2. Install prerequisites on Ubuntu 16.04
--------------------------------------------

You need the following software to be able to build NGOS.
* Ubuntu 16.04
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
apt-get update
apt-get upgrade -y
apt-get install -y --no-install-recommends ubuntu-desktop gnome-panel gnome-settings-daemon metacity nautilus gnome-terminal
apt-get install -y libtasn1-3-bin
apt-get install -y xfce4 xfce4-goodies

mkdir /tmp/src
cd /tmp/src
mkdir tigervnc
cd tigervnc
wget https://bintray.com/tigervnc/stable/download_file?file_path=ubuntu-16.04LTS%2Famd64%2Ftigervncserver_1.8.0-1ubuntu1_amd64.deb
dpkg -i *.deb
```

After this run commands with your user account:

```sh
vncserver

echo '#!/bin/sh'                                                                       >  ~/.vnc/xstartup
echo ""                                                                                >> ~/.vnc/xstartup
echo "# Uncomment the following two lines for normal desktop:"                         >> ~/.vnc/xstartup
echo "# unset SESSION_MANAGER"                                                         >> ~/.vnc/xstartup
echo "# exec /etc/X11/xinit/xinitrc"                                                   >> ~/.vnc/xstartup
echo ""                                                                                >> ~/.vnc/xstartup
echo "[ -x /etc/vnc/xstartup ] && exec /etc/vnc/xstartup"                              >> ~/.vnc/xstartup
echo "[ -r $HOME/.Xresources ] && xrdb $HOME/.Xresources"                              >> ~/.vnc/xstartup
echo "xsetroot -solid grey"                                                            >> ~/.vnc/xstartup
echo "vncconfig -iconic &"                                                             >> ~/.vnc/xstartup
echo "x-terminal-emulator -geometry 80x24+10+10 -ls -title \"\$VNCDESKTOP Desktop\" &" >> ~/.vnc/xstartup
echo "x-window-manager &"                                                              >> ~/.vnc/xstartup
echo ""                                                                                >> ~/.vnc/xstartup
echo "gnome-panel &"                                                                   >> ~/.vnc/xstartup
echo "gnome-settings-daemon &"                                                         >> ~/.vnc/xstartup
echo "metacity &"                                                                      >> ~/.vnc/xstartup
echo "nautilus &"                                                                      >> ~/.vnc/xstartup

vncserver -kill :1
vncserver
```

Environment
-----------

Please call these commands before installing binutils and gcc

```sh
sudo su
apt-get update
apt-get upgrade -y
apt-get install -y curl
apt-get install -y build-essential
apt-get install -y libncurses-dev
apt-get install -y bison
apt-get install -y flex
apt-get install -y gdb
apt-get install -y libgl-dev
apt-get install -y socat
apt-get install -y imagemagick
apt-get install -y npm

ln -s /usr/bin/nodejs /usr/bin/node
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
apt-get build-dep -y virt-manager
apt-get install -y intltool
apt-get install -y qemu-kvm libvirt-bin ubuntu-vm-builder bridge-utils python-libvirt libgtk-3-dev libvirt-glib-1.0 gir1.2-gtk-vnc-2.0 gir1.2-spice-client-gtk-3.0 libosinfo-1.0 python-ipaddr gir1.2-vte-2.91 python-libxml2 python-requests libvirt-glib-1.0-dev libgtk2.0-bin python-gi
apt-get install -y virt-viewer
apt-get install -y ovmf
apt-get install -y alien



mkdir /tmp/src
cd /tmp/src
mkdir edk2_git
cd edk2_git
wget https://www.kraxel.org/repos/jenkins/edk2/`curl https://www.kraxel.org/repos/jenkins/edk2/ 2> /dev/nill | grep -o -e "edk2.git-ovmf-x64-.*.rpm\"" | rev | cut -c 2- | rev`
alien *.rpm
dpkg -i *.deb



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
wget -q https://www.virtualbox.org/download/oracle_vbox_2016.asc -O- | apt-key add -
wget -q https://www.virtualbox.org/download/oracle_vbox.asc -O- | apt-key add -
apt-add-repository "deb http://download.virtualbox.org/virtualbox/debian $(lsb_release -sc) contrib"

apt-get update
apt-get install -y virtualbox-5.2
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

You probably have to disable AppArmor

```sh
sudo su
update-rc.d apparmor disable
reboot
```
