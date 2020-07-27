NGOS
====

0.2.8. Install prerequisites on CentOS 7.6
------------------------------------------

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
* Qt -> Qt 5.15.0 -> Desktop gcc 64 bit
* Qt -> Qt 5.15.0 -> Sources
