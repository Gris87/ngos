NGOS
====

0.6.1.4. Installer part
-----------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/src/os/installer/Image%20structure.png?raw=true" alt="Image structure"/>
</p>

Installer part is an ELF image that should be included in kernel image.

The main purpose of NGOS installer to format your hard disks in expected way and to place NGOS kernel on system partition of [GPT](https://en.wikipedia.org/wiki/GUID_Partition_Table).<br/>
NGOS kernel is responsible for installing applications.
