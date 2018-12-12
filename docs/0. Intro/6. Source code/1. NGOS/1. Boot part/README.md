NGOS
====

0.6.1.1. Boot part
------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/src/os/boot/Image%20structure.png?raw=true" alt="Image structure"/>
</p>

Boot part of kernel image is the first block of image with the size in 0x200 (512) bytes.

It is actually a PE header that let kernel image to be runnable via UEFI.

Since it is a PE header, it should be started with the 'MZ' signature and should contain address of PE header at 0x3C offset.

Boot part also ends with the 0xAA55 signature to make it bootable for BIOS bootloader. But in case of BIOS bootloader it just prints the message that the kernel should be loaded via UEFI.

You can check the [src/os/boot/asm/arch/x86_64/main.S](../../../../../src/os/boot/asm/arch/x86_64/main.S) file and [src/os/boot/linker.ld](../../../../../src/os/boot/linker.ld) file for getting more details.
