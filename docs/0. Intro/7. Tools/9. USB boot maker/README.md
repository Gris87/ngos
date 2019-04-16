NGOS
====

0.7.9. USB boot maker
---------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/tools/qt/usb_boot_maker/Screenshot.png?raw=true" alt="Screenshot"/>
</p>

USB boot maker helps user to make bootable USB flash drive ready for NGOS installation.

### Build

In order to build this application with Qt you should also install OpenSSL.

Windows:

- Open [OpenSSL Installation Project page](https://slproweb.com/products/Win32OpenSSL.html)
- Download the latest "light" Win64 installation package, for example "Win64 OpenSSL v1.0.2r Light".
- Install it to any location. Select copying OpenSSL DLLs to "The OpenSSL binaries (\bin) directory".
- Copy libeay32.dll and ssleay32.dll from the \bin folder to the same place where your Qt5Network.dll or Qt5Networkd.dll is located (C:\Qt\5.11.2\msvc2017_64\bin).

### Usage

```sh
usb_boot_maker
```

### How to ...

TODO: Write document
