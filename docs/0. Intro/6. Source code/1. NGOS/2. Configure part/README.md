NGOS
====

0.6.1.2. Configure part
-----------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/src/os/configure/Image%20structure.png?raw=true" alt="Image structure"/>
</p>

Configure part is the entry point for our kernel. The goal of this part is to perform early initialization and provide control to Kernel part or Installer part.

It is actually doing the following:
* Allocate space for the boot parameters (set of attributes that can be shared between kernel parts).
* Get attributes for the graphics module, such as screen resolution and color depth.
* Get the list of PCI devices.
* Relocate kernel to low address space.
* Decompress Kernel part or Installer part
* Initialize page table
* Choose random location for kernel
* Jump to the kernel

Entry point is located at 0x220 (0x200 + 0x20) offset right after the Boot part and .reloc section.

You can check it with the source code in [src/os/configure/asm/arch/x86_64/main.S](../../../../../src/os/configure/asm/arch/x86_64/main.S) file.
