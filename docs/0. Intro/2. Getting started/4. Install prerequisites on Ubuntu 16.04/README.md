NGOS
====

0.2.4. Install prerequisites on Ubuntu 16.04
--------------------------------------------

Please follow instructions below in order to obtain the required software

VNC
---

If you need to install VNC server please use the following instruction:

```sh
sudo su
apt-get update
apt-get upgrade -y
apt-get install -y --no-install-recommends ubuntu-desktop gnome-panel gnome-settings-daemon metacity nautilus gnome-terminal libtasn1-3-bin xfce4 xfce4-goodies

mkdir /tmp/src
cd /tmp/src
mkdir tigervnc
cd tigervnc
wget https://bintray.com/tigervnc/stable/download_file?file_path=ubuntu-16.04LTS%2Famd64%2Ftigervncserver_1.8.0-1ubuntu1_amd64.deb
dpkg -i *.deb
rm -rf /tmp/src
```

After this run commands with your user account:

```sh
vncserver

echo '#!/bin/sh'                                                                            >  ~/.vnc/xstartup
echo ""                                                                                     >> ~/.vnc/xstartup
echo "# Uncomment the following two lines for normal desktop:"                              >> ~/.vnc/xstartup
echo "# unset SESSION_MANAGER"                                                              >> ~/.vnc/xstartup
echo "# exec /etc/X11/xinit/xinitrc"                                                        >> ~/.vnc/xstartup
echo ""                                                                                     >> ~/.vnc/xstartup
echo "[ -x /etc/vnc/xstartup ] && exec /etc/vnc/xstartup"                                   >> ~/.vnc/xstartup
echo "[ -r ${HOME}/.Xresources ] && xrdb ${HOME}/.Xresources"                               >> ~/.vnc/xstartup
echo "xsetroot -solid grey"                                                                 >> ~/.vnc/xstartup
echo "vncconfig -iconic &"                                                                  >> ~/.vnc/xstartup
echo "x-terminal-emulator -geometry 80x24+10+10 -ls -title \"\${VNCDESKTOP} Desktop\" &"    >> ~/.vnc/xstartup
echo "x-window-manager &"                                                                   >> ~/.vnc/xstartup
echo ""                                                                                     >> ~/.vnc/xstartup
echo "gnome-panel &"                                                                        >> ~/.vnc/xstartup
echo "gnome-settings-daemon &"                                                              >> ~/.vnc/xstartup
echo "metacity &"                                                                           >> ~/.vnc/xstartup
echo "nautilus &"                                                                           >> ~/.vnc/xstartup

vncserver -kill :1
vncserver
```

Installation
------------

Please call these commands to install prerequisites

```sh
cd scripts/prerequisites
sudo ./install.sh
```

Qt + Qt Creator
---------------

Execute commands below in the X11 terminal with your user account

```sh
cd ~/
./qt-unified-linux-x64-online.run
rm qt-unified-linux-x64-online.run
```

Please choose following items during Qt installation:
* Qt -> Qt 5.12.3 -> Desktop gcc 64 bit
* Qt -> Qt 5.12.3 -> Sources