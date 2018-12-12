NGOS
====

0.7.1. Image builder
--------------------

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/tools/qt/image_builder/Screenshot.png?raw=true" alt="Screenshot"/>
</p>

The kernel image consist of 3 major parts:
* [Boot](../../../../src/os/boot/) part
* [Configure](../../../../src/os/configure/) part
* [Kernel](../../../../src/os/kernel/) or [Installer](../../../../src/os/installer/) part

Boot part is actually a PE header that let UEFI to run the image.<br/>
We can put some attributes in PE header during the build procedure, but the remaining attributes should be filled at the end.<br/>
Please check for comments "To be filled by image_builder" in [src/os/boot/asm/arch/x86_64/main.S](../../../../src/os/boot/asm/arch/x86_64/main.S) file

Image builder tool is a special tool that allow user to build kernel image from the parts and can fill PE header with the correct values.

### Usage

```sh
image_builder -b PATH_TO_BOOT_ELF -c PATH_TO_CONFIGURE_ELF (-k PATH_TO_KERNEL_ELF | -i PATH_TO_INSTALLER_ELF) -o PATH_TO_RESULT_IMAGE
    * -b PATH_TO_BOOT_ELF      - specify path to boot.elf file
    * -c PATH_TO_CONFIGURE_ELF - specify path to configure.elf file
    * -k PATH_TO_KERNEL_ELF    - specify path to kernel.elf file
    * -i PATH_TO_INSTALLER_ELF - specify path to installer.elf file
    * -o PATH_TO_RESULT_IMAGE  - specify path to result kernel image
```

### How to ...

In order to obtain kernel image you should run image_builder tool with the attributes provided above.<br/>
Image builder will check the specified ELF files and will create kernel image in PATH_TO_RESULT_IMAGE.

Image builder will also modify PE header attributes of the result file according to the provided input.<br/>
We are expecting that the result file consist of 3 sections.
* .reloc section
* .config section
* .kernel section

.reloc section is required for UEFI in order to run this image. It is located at 0x200 offset right after the Boot part and contains 0x20 bytes.

Since UEFI binaries are executed in physical mode, UEFI cannot guarantee that a given binary can be loaded at its preferred address. UEFI does _try_ to load a binary at it's preferred address, but if it can't do so, it will load it at another address and then relocate the binary using the contents of the .reloc section.

.config section is located at 0x220 (0x200 + 0x20) offset, next to .reloc section. This section contains the code from configure.elf file. It is a entry point for NGOS kernel.

.kernel section is located after the .config section and contains raw or compressed kernel.elf file or installer.elf file. This section starts with [KernelDescriptor](../../../../src/os/configure/src/bits64/other/kerneldescriptor.h) that indicates the size of included image.

The structure of kernel image can be displayed on figure below:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/0.%20Intro/7.%20Tools/1.%20Image%20builder/Image%20structure.png?raw=true" alt="Image structure"/>
</p>
