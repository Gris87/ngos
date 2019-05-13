NGOS
====

0.2.1. Install prerequisites on Ubuntu 18.10
--------------------------------------------

Please follow instructions below in order to obtain the required software

VNC
---

If you need to install VNC server please use the following instruction:

```sh
sudo su
apt-get update
apt-get upgrade -y
apt-get install -y xfce4 xfce4-goodies
apt-get install -y tigervnc-standalone-server tigervnc-xorg-extension tigervnc-viewer
```

After this run commands with your user account:

```sh
vncserver

echo '#!/bin/sh'                                                >  ~/.vnc/xstartup
echo ""                                                         >> ~/.vnc/xstartup
echo "# Uncomment the following two lines for normal desktop:"  >> ~/.vnc/xstartup
echo "# unset SESSION_MANAGER"                                  >> ~/.vnc/xstartup
echo "# exec /etc/X11/xinit/xinitrc"                            >> ~/.vnc/xstartup
echo ""                                                         >> ~/.vnc/xstartup
echo "[ -x /etc/vnc/xstartup ] && exec /etc/vnc/xstartup"       >> ~/.vnc/xstartup
echo "[ -r ${HOME}/.Xresources ] && xrdb ${HOME}/.Xresources"   >> ~/.vnc/xstartup
echo "startxfce4 &"                                             >> ~/.vnc/xstartup

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
