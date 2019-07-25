NGOS
====

1.5. First steps in the relocated kernel
----------------------------------------

We have known from the previous [chapter](../4.%20UEFI%20initialization/README.md) how NGOS perform initialization during UEFI booting like:
* Serial port initialization for debugging
* Early CPU initialization
* Assets loading
* Base functionality testing
* Space allocation for boot parameters
* Obtaining graphics parameters
* Early console initialization
* Fetching ROM images for PCI devices
* Kernel image relocation
* Global descriptor table initialization
* Storing memory map information

In the previous chapter we have finished at the relocated_address label in relocated address space.<br/>
Let's continue from this point.

```
relocated_address:                                                              # Label for relocated address
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clear EFLAGS                                                                  #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   $0                                                                  # Push 0 to the stack
    popfq                                                                       # Restore EFLAGS from the stack
```

Here we are resetting EFLAGS register.

### Setup Global Descriptor Table

The Global Descriptor Table (GDT) is a data structure used by Intel x86-family processors starting with the 80286 in order to define the characteristics of the various memory areas used during program execution, including the base address, the size, and access privileges like executability and writability. These memory areas are called segments in Intel terminology.<br/>
The GDT is still present in 64 bit mode; a GDT must be defined, but is generally never changed or used for segmentation.<br/>
We need to setup GDT in order to be able to perform jump to 32 bit mode.

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup GDT                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    leaq    gdt(%rip), %rax                                                     # Put address of gdt variable to RAX
    movq    %rax, early_gdt_register + 0x02(%rip)                               # Store address of gdt variable in early_gdt_register
                                                                                #
    lgdt    early_gdt_register(%rip)                                            # Setup GDT
```

The GDT is loaded using the `lgdt` instruction. It expects the location points to following structure:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/1.%20Booting/5.%20First%20steps%20in%20the%20relocated%20kernel/GDT%20register.png?raw=true" alt="GDT register"/>
</p>

The offset is the linear address of the table itself, which means that paging applies. The size is the size of the table subtracted by 1. This is because the maximum value of size is 65535, while the GDT can be up to 65536 bytes (a maximum of 8192 entries). Further no GDT can have a size of 0.

```
ENTRY(early_gdt_register)                                                       # Declaration for early_gdt_register variable
    .word   GDT_ENTRIES * 8 - 1                                                 # Put size of gdt variable. The size subtracted by 1 because the maximum value of size is 65535, while the GDT can be up to 65536 bytes (a maximum of 8192 entries). Further no GDT can have a size of 0.
    .quad   gdt                                                                 # Put address of gdt variable
END_ENTRY(early_gdt_register)                                                   # End of declaration for early_gdt_register variable
```

Here is declaration of early_gdt_register variable that we provide to `lgdt` instruction.<br/>
The table contains of GDT_ENTRIES amount of entries.<br/>
GDT_ENTRIES defined in [src/os/include/gdt/segments.h](../../../src/os/include/gdt/segments.h) as following:

```
#define GDT_ENTRIES                 16
```

We also provide GDT location as address of gdt variable.

The table contains 8-byte entries. Each entry has the following structure:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/1.%20Booting/5.%20First%20steps%20in%20the%20relocated%20kernel/GDT%20entry.png?raw=true" alt="GDT entry"/>
</p>

What "Limit 0:15" means is that the field contains bits 0-15 of the limit value. The base is a 32 bit value containing the linear address where the segment begins. The limit, a 20 bit value, tells the maximum addressable unit (either in 1 byte units, or in pages). Hence, if you choose page granularity (4 KB) and set the limit value to 0x000FFFFF the segment will span the full 4 GiB address space. Here is the structure of the access byte and flags:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/1.%20Booting/5.%20First%20steps%20in%20the%20relocated%20kernel/GDT%20flags.png?raw=true" alt="GDT flags"/>
</p>

The bit fields are:

* Pr: Present bit. This must be 1 for all valid selectors.
* Privl: Privilege, 2 bits. Contains the ring level, 0 = highest (kernel), 3 = lowest (user applications).
* Ex: Executable bit. If 1 code in this segment can be executed, ie. a code selector. If 0 it is a data selector.
* DC: Direction bit/Conforming bit.
    * Direction bit for data selectors: Tells the direction. 0 the segment grows up. 1 the segment grows down, ie. the offset has to be greater than the limit.
    * Conforming bit for code selectors:
        * If 1 code in this segment can be executed from an equal or lower privilege level. For example, code in ring 3 can far-jump to conforming code in a ring 2 segment. The privl-bits represent the highest privilege level that is allowed to execute the segment. For example, code in ring 0 cannot far-jump to a conforming code segment with privl==0x02, while code in ring 2 and 3 can. Note that the privilege level remains the same, ie. a far-jump form ring 3 to a privl==2-segment remains in ring 3 after the jump.
        * If 0 code in this segment can only be executed from the ring set in privl.
* RW: Readable bit/Writable bit.
    * Readable bit for code selectors: Whether read access for this segment is allowed. Write access is never allowed for code segments.
    * Writable bit for data selectors: Whether write access for this segment is allowed. Read access is always allowed for data segments.
* Ac: Accessed bit. Just set to 0. The CPU sets this to 1 when the segment is accessed.
* Gr: Granularity bit. If 0 the limit is in 1 B blocks (byte granularity), if 1 the limit is in 4 KB blocks (page granularity).
* Sz: Size bit. If 0 the selector defines 16 bit protected mode. If 1 it defines 32 bit protected mode. You can have both 16 bit and 32 bit selectors at once.

```
ENTRY(gdt)                                                                      # Declaration for gdt variable
    .quad   0x0000000000000000                                                  # First GDT entry ignored
    .quad   0x00CF9A000000FFFF                                                  # GDT_ENTRY_KERNEL32_CS
    .quad   0x00AF9A000000FFFF                                                  # GDT_ENTRY_KERNEL_CS
    .quad   0x00CF92000000FFFF                                                  # GDT_ENTRY_KERNEL_DS
    .quad   0x0000000000000000                                                  # GDT_ENTRY_DEFAULT_USER32_CS
    .quad   0x0000000000000000                                                  # GDT_ENTRY_DEFAULT_USER_DS
    .quad   0x0000000000000000                                                  # GDT_ENTRY_DEFAULT_USER_CS
    .quad   0x0000000000000000                                                  # Ignored
    .quad   0x0080890000000000                                                  # GDT_ENTRY_TSS
    .quad   0x0000000000000000                                                  # Ignored
    .quad   0x0000000000000000                                                  # GDT_ENTRY_LDT
    .quad   0x0000000000000000                                                  # Ignored
    .quad   0x0000000000000000                                                  # GDT_ENTRY_TLS_MIN
    .quad   0x0000000000000000                                                  # Ignored
    .quad   0x0000000000000000                                                  # GDT_ENTRY_TLS_MAX
    .quad   0x0000000000000000                                                  # GDT_ENTRY_PER_CPU
END_ENTRY(gdt)                                                                  # End of declaration for gdt variable
```

gdt variable consist of GDT_ENTRIES (16) predefined entries above.

### Segments initialization

We are resetting segments after updating Global Descriptor Table:

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clear segment registers                                                       #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    xorq    %rax, %rax                                                          # Indirectly assign (via RAX)
    movq    %rax, %ds                                                           # DS to 0
    movq    %rax, %es                                                           # ES to 0
    movq    %rax, %ss                                                           # SS to 0
    movq    %rax, %fs                                                           # FS to 0
    movq    %rax, %gs                                                           # GS to 0
```

### Jumping to C++ code

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Extract the Kernel                                                            #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    leaq    _start(%rip), %rdx                                                  # Put address of relocated kernel to RDX
    movq    ASM_OFFSET_BOOT_PARAM_KERNEL_SIZE(%rsi), %rax                       # Put size of the kernel to RAX
                                                                                #
# Align RAX by PAGE_SIZE in order to make address of page table to be aligned   #
    movq    $(PAGE_SIZE), %rcx                                                  # Put PAGE_SIZE to RCX
    decq    %rcx                                                                # Since RCX is power of 2, then it will give us a mask
    addq    %rcx, %rax                                                          # Add RCX to RAX. If RAX unaligned it will make it aligned on the next steps
    notq    %rcx                                                                # Inverting RCX to get the mask
    andq    %rcx, %rax                                                          # Align RAX with inverted RCX
                                                                                #
    addq    %rax, %rdx                                                          # Calculate end position of kernel image in RDX
    movq    %rdx, %rcx                                                          # Store address of page table to RCX
    addq    $(BOOT_PAGE_TABLE_SIZE + BOOT_STACK_SIZE), %rdx                     # Calculate start position of stack in RDX
    movq    %rdx, %rsp                                                          # Initialize the stack
    leaq    _end(%rip), %rdi                                                    # Put address of attached kernel image to RDI
                                                                                #
#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_NONE
    leaq    ASM_OFFSET_KERNEL_DESCRIPTOR_CONTENT(%rdi), %rdx                    # Put address of attached decompressed kernel image to RDX
#endif
```

It is better to explain this code block with a picture below:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/1.%20Booting/5.%20First%20steps%20in%20the%20relocated%20kernel/Image%20structure.png?raw=true" alt="Image structure"/>
</p>

As you know from the previous [chapter](../4.%20UEFI%20initialization/README.md) we are allocating space for kernel image, page table, stack and for decompressed kernel if the kernel was compressed.<br/>
Page table should be properly aligned to page size. Therefore we are adding few bytes to imageSize variable to make it aligned.<br/>
It is expected that the location of relocated kernel will be also aligned to page size.

We are putting address of relocated kernel to RDX with the first instruction.

```
    leaq    _start(%rip), %rdx                                                  # Put address of relocated kernel to RDX
```

Next block of instructions calculates value of imageSize aligned to page size and appends to RDX.

```
    movq    ASM_OFFSET_BOOT_PARAM_KERNEL_SIZE(%rsi), %rax                       # Put size of the kernel to RAX
                                                                                #
# Align RAX by PAGE_SIZE in order to make address of page table to be aligned   #
    movq    $(PAGE_SIZE), %rcx                                                  # Put PAGE_SIZE to RCX
    decq    %rcx                                                                # Since RCX is power of 2, then it will give us a mask
    addq    %rcx, %rax                                                          # Add RCX to RAX. If RAX unaligned it will make it aligned on the next steps
    notq    %rcx                                                                # Inverting RCX to get the mask
    andq    %rcx, %rax                                                          # Align RAX with inverted RCX
                                                                                #
    addq    %rax, %rdx                                                          # Calculate end position of kernel image in RDX
```

RDX register is pointing to address of page table now. We will store its value to RCX:

```
    movq    %rdx, %rcx                                                          # Store address of page table to RCX
```

After this we will calculate and setup address of the stack:

```
    addq    $(BOOT_PAGE_TABLE_SIZE + BOOT_STACK_SIZE), %rdx                     # Calculate start position of stack in RDX
    movq    %rdx, %rsp                                                          # Initialize the stack
```

And the last instruction needed to get the address of [KernelDescriptor](../../../src/os/configure/src/bits64/other/kerneldescriptor.h) structure located at the beginning of .kernel section:

```
    leaq    _end(%rip), %rdi                                                    # Put address of attached kernel image to RDI
```

In case when included kernel image doesn't compressed RDX should point to location of that image right after [KernelDescriptor](../../../src/os/configure/src/bits64/other/kerneldescriptor.h) structure.

```
#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_NONE
    leaq    ASM_OFFSET_KERNEL_DESCRIPTOR_CONTENT(%rdi), %rdx                    # Put address of attached decompressed kernel image to RDX
#endif
```

Otherwise RDX should point to address where we will put the decompressed image.

Since we are done with the registers we can go back to C++ code for extracting kernel image.

```
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    call    extractKernel                                                       # Call extractKernel function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
                                                                                #
    cmpq    $0, %rax                                                            # IF result == 0
    je      fail                                                                #   THEN jump to fail
                                                                                #
    jmp     *%rax                                                               # Jump to decompressed kernel
```

RSI register is pointing to boot parameters. So we need to store this address since it may be changed during extractKernel() function call.

extractKernel() function located in [src/os/configure/src/bits64/b_early/main/kernelextraction.cpp](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/kernelextraction.cpp#L16) file.

Here is the extractKernel declaration:

```
CPP_EXTERN_C
u64 extractKernel(KernelDescriptor *kernelDescriptor, BootParams *params, u8 *decompressedAddress, u8 *pageTable)
```

As a result we should get the address of extracted kernel binary image.<br/>
In case when result is null that means that we have some problem and we will jump to fail label.

```
fail:                                                                           # Label for failure
    hlt                                                                         # Wait for interrupt
    jmp    fail                                                                 # Loop in fail forever
```

In case of issue we came to fail label and hold PC into a forever loop.
