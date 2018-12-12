NGOS
====

1.2. First steps in the kernel
------------------------------

As we already know from the previous [chapter](../1.%20PC%20turning%20on/README.md#uefi) NGOS perform booting via UEFI.

The structure of kernel image can be displayed on figure below:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/1.%20Booting/1.%20PC%20turning%20on/Image%20structure.png?raw=true" alt="Image structure"/>
</p>

As you can see addressOfEntryPoint field of PE Optional Header is pointing to 0x220 offset, right after .reloc section, at the first byte of .config section.<br/>
But what is the place of that first instruction?

If you check [src/os/configure/linker.ld](../../../src/os/configure/linker.ld) file you will see the following:

```
OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    . = 0;

    .configure_code : { *(.configure_code) }
    .asm_code       : { *(.asm_code) }
    .text           : { *(.text*) }
    .rodata         : { *(.rodata*) }
    .data           : { *(.data*) }

    .gdt            : { *(.gdt) }

    .assets         : {
        _assets_begin = .;
        *(.assets)
        _assets_end = .;
    }

    .noinit         : {
        *(.noinit)
        *(.bss)
    }

    _end = .;



    . = ASSERT(_start == 0, "Invalid entry point!");
}
```

We have the list of sections below:
* .configure_code - located at zero offset. This section contains the first kernel instructions.
* .asm_code - section for code written in Assembler.
* .text - section for C++ code.
* .rodata - section with string constants.
* .data - another data if exists.
* .assets - section with content of files located in [src/os/configure/assets](../../../src/os/configure/assets) folder.
* .noinit - zero filled section that used instead of .bss section.

Please note that there is no .bss section. We are using .noinit section instead.

The reason for doing this is the following. Usually .bss section located at the end of the image, but not even really present in file.<br/>
It just allocating the required amount of bytes on loading. Since we have included Kernel part or Installer part right after Configure part it may cause overlapping between .bss and included image.

The initial kernel code is located in .configure_code section.

If you search for .configure_code section you will find that it is only declared at [src/os/configure/asm/arch/x86_64/main.S](../../../src/os/configure/asm/arch/x86_64/main.S) file.<br/>
Let's check this [file](../../../src/os/configure/asm/arch/x86_64/main.S).

### Jumping to C++ code

```
# ============================================================================= # =============================================================================
# Entry point                                                                   #
#                                                                               #
# RDX - address of systemTable                                                  #
# RCX - address of imageHandle                                                  #
# ============================================================================= # =============================================================================
                                                                                #
    movq    %rcx, %rdi                                                          # Put address of imageHandle to RDI
    movq    %rdx, %rsi                                                          # Put address of systemTable to RSI
    leaq    _start(%rip), %rdx                                                  # Put address of entry point to RDX
                                                                                #
    call    uefiMain                                                            # Call uefiMain function
                                                                                #
    cmpq    $0, %rax                                                            # IF result == 0
    je      fail                                                                #   THEN jump to fail
```

UEFI providing address of System Table and address of Image Handle to us in RDX and RCX registers.<br/>
We will put them into RDI and RSI registers and also store the address of .config section in RDX.

After that we calls uefiMain() function located in [src/os/configure/src/main.cpp](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/main.cpp#L106) file.

Here is the uefiMain declaration:

```
CPP_EXTERN_C
BootParams* uefiMain(EfiHandle imageHandle, EfiSystemTable *systemTable, u64 kernelLocation)
```

As a result we should get the pointer to [BootParams](../../../src/os/include/bootparams/bootparams.h) structure.<br/>
In case when result is null that means that we have some problem and we will jump to fail label.

```
fail:                                                                           # Label for failure
    hlt                                                                         # Wait for interrupt
    jmp    fail                                                                 # Loop in fail forever
```

In case of issue we came to fail label and hold PC into a forever loop.
