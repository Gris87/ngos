NGOS
====

1. Booting
----------

This chapter describes the NGOS kernel boot process.<br/>
Here we gonna explain what happens with your PC starting from pressing Power On button to booting NGOS kernel image.

* [PC turning on](1.%20PC%20turning%20on/README.md) - describes the steps from turning on the PC to running the first kernel instruction.
* [First steps in the kernel](2.%20First%20steps%20in%20the%20kernel/README.md) - describes where is NGOS entry point located and what would we do first.
* [Logging principles](3.%20Logging%20principles/README.md) - additional chapter for explaining how logging is working in NGOS source code.
* [UEFI initialization](4.%20UEFI%20initialization/README.md) - describes what kernel setup is performing on start up until calling UEFI::exitBootServices() and jumping to relocated kernel.
* [First steps in the relocated kernel](5.%20First%20steps%20in%20the%20relocated%20kernel/README.md) - describes preparation steps in relocated kernel in order to perform kernel decompression in random place.
* [Kernel decompression](6.%20Kernel%20decompression/README.md) - describes steps for NGOS kernel decompression until jumping to it.
* [Kernel address space layout randomization](7.%20Kernel%20address%20space%20layout%20randomization/README.md) - describes mechanism of choosing random location for kernel binary image.
