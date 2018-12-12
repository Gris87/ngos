NGOS
====

2.1. First steps in the kernel
------------------------------

If you already read the previous [chapter](../../1.%20Booting/README.md) then you probably know that we are loading Kernel part of image into a random place in the memory.

Let's refresh one's memory and check it again:

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

Here we calls [extractKernel()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/b_early/main/kernelextraction.cpp#L16) function that should extract included Kernel part to some place in memory and return it's address in RAX register.

After that we are jumping to this address. It is expected that the first instruction is located at the first byte of Kernel part.<br/>
But what is the place of that first instruction?

If you check [src/os/kernel/linker.ld](../../../src/os/kernel/linker.ld) file you will see the following:

```
OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    . = 0xFFFFFFFF80000000;

    .kernel_code : AT(0) { *(.kernel_code) }
    .asm_code    :       { *(.asm_code) }
    .text        :       { *(.text*) }
    .rodata      :       { *(.rodata*) }
    .data        :       { *(.data*) }

    . = ALIGN((1 << 12));
    .pagetable   :       { *(.pagetable) }
    . = ALIGN((1 << 12));

    .gdt         :       { *(.gdt) }
    .idt         :       { *(.idt) }

    .assets      :       {
        _assets_begin = .;
        *(.assets)
        _assets_end = .;
    }

    . = ALIGN(4);
    .stack       :       {
        *(.stack)
        _stack_begin = .;
    }

    .bss         :       {
        _bss_begin = .;
        *(.bss)
        _bss_end = .;
    }

    _end = .;



    . = ASSERT(_start == 0xFFFFFFFF80000000, "Invalid entry point!");
}
```

We have the list of sections below:
* .kernel_code - located at zero offset. This section contains the first kernel instructions.
* .asm_code - section for code written in Assembler.
* .text - section for C++ code.
* .rodata - section with string constants.
* .data - another data if exists.
* .pagetable - section with page table that we gonna use as soon as we come to the Kernel part image. This section should be aligned by page size.
* .gdt - Global Descriptor Table.
* .idt - Interrupt Descriptor Table.
* .assets - section with content of files located in [src/os/kernel/assets](../../../src/os/kernel/assets) folder.
* .stack - section with the stack.
* .bss - zero filled section for uninitialized data.

You can also see that kernel image suppose to be loaded at virtual address 0xFFFFFFFF80000000.<br/>
We will go to virtual address space as soon as possible at the very beginning.

The initial kernel code is located in .kernel_code section.

If you search for .kernel_code section you will find that it is only declared at [src/os/kernelbase/asm/arch/x86_64/main.S](../../../src/os/kernelbase/asm/arch/x86_64/main.S) file.<br/>
Let's check this [file](../../../src/os/kernelbase/asm/arch/x86_64/main.S).

### CPU validation

```
# ============================================================================= # =============================================================================
# Entry point                                                                   #
#                                                                               #
# RSI - address of BootParams                                                   #
# ============================================================================= # =============================================================================
                                                                                #
    leaq    _stack_begin(%rip), %rsp                                            # Setup stack in physical address space
```

First of all we setup the stack because we want to use our own stack for the kernel.

### Clear BSS section

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clear BSS                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    leaq    _bss_begin(%rip), %rdi                                              # Put start address of bss section to RDI. _bss_begin declared in linker.ld
    leaq    _bss_end(%rip), %rsi                                                # Put end address of bss section to RSI. _bss_end declared in linker.ld
    subq    %rdi, %rsi                                                          # Put size of bss section to RSI
    call    memzero                                                             # Call memzero function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
```

We can choose such random address for kernel image that may contain some garbage in bss section.<br/>
Therefore we are doing clean up for bss section.

### Setup page table and jumping to virtual address space

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Adapt page table                                                              #
#                                                                               #
# We have predefined page table already. But we need to update it in order to   #
# make it valid for the physical address where the image was loaded.            #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    leaq    _start(%rip), %rdi                                                  # Put address of entry point to RDI
    call    adaptPageTable                                                      # Call adaptPageTable function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
                                                                                #
    cmpq    $0, %rax                                                            # IF result != NgosStatus::OK
    jne     fail                                                                #   THEN jump to fail
```

At the next step we calls [adaptPageTable()](https://github.com/Gris87/ngos/blob/master/src/os/kernelbase/src/bits64/other/adaptpagetable.cpp#L417) function in order to update page table in a proper way.<br/>
We are providing kernel address as an argument for that function.

Here is the adaptPageTable declaration:

```
CPP_EXTERN_C
NgosStatus adaptPageTable(u64 imageLocation)
```

As output we should get positive or negative result.<br/>
In case of failure we will jump to fail label.

```
fail:                                                                           # Label for failure
    hlt                                                                         # Wait for interrupt
    jmp    fail                                                                 # Loop in fail forever
```

If we came to fail label we will hold PC into a forever loop.

As we already said we have predefined page table:

```
.section ".pagetable", "a"                                                      # pagetable section (a - allocatable)
                                                                                #
                                                                                #
                                                                                #
DECLARE_PAGE(early_pagetable)                                                   # Declaration for early_pagetable variable
    .fill   511, 8, 0                                                           # Skip 511 entries in PGD
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    .quad   early_pagetable_level4 + USER_PAGE_TABLE_FLAGS                      # In case of 5 level paging we put address of early_pagetable_level4
#else
    .quad   early_pagetable_level3 + USER_PAGE_TABLE_FLAGS                      # In case of 4 level paging we put address of early_pagetable_level3
#endif
END_ENTRY(early_pagetable)                                                      # End of declaration for early_pagetable variable
                                                                                #
                                                                                #
                                                                                #
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
DECLARE_PAGE(early_pagetable_level4)                                            # Declaration for early_pagetable_level4 variable
    .fill   511, 8, 0                                                           # Skip 511 entries in P4D
    .quad   early_pagetable_level3 + USER_PAGE_TABLE_FLAGS                      # Put address of early_pagetable_level3
END_ENTRY(early_pagetable_level4)                                               # End of declaration for early_pagetable_level4 variable
#endif
                                                                                #
                                                                                #
                                                                                #
DECLARE_PAGE(early_pagetable_level3)                                            # Declaration for early_pagetable_level3 variable
    .fill   510, 8, 0                                                           # Skip 510 entries in PUD
    .quad   early_pagetable_level2  + KERNEL_PAGE_TABLE_FLAGS                   # Put address of early_pagetable_level2
    .quad   fixmap_pagetable_level2 + USER_PAGE_TABLE_FLAGS                     # Put address of fixmap_pagetable_level2
END_ENTRY(early_pagetable_level3)                                               # End of declaration for early_pagetable_level3 variable
                                                                                #
                                                                                #
                                                                                #
DECLARE_PAGE(early_pagetable_level2)                                            # Declaration for early_pagetable_level2 variable
    PMDS(0, KERNEL_PAGE_LARGE_EXEC_FLAGS, PTRS_PER_PMD)                         # Put 512 PMD entries with 1 to 1 mapping for 1 GB
END_ENTRY(early_pagetable_level2)                                               # End of declaration for early_pagetable_level2 variable
                                                                                #
                                                                                #
                                                                                #
DECLARE_PAGE(fixmap_pagetable_level2)                                           # Declaration for fixmap_pagetable_level2 variable
    .fill   506, 8, 0                                                           # Skip 506 entries in PUD
    .quad   fixmap_pagetable_level1 + USER_PAGE_TABLE_FLAGS                     # Put address of fixmap_pagetable_level1
    .fill   5, 8, 0                                                             # 8MB reserved for vsyscalls + a 2 MB hole = 4 + 1 entries
END_ENTRY(fixmap_pagetable_level2)                                              # End of declaration for fixmap_pagetable_level2 variable
                                                                                #
                                                                                #
                                                                                #
DECLARE_PAGE(fixmap_pagetable_level1)                                           # Declaration for fixmap_pagetable_level1 variable
    .fill   512, 8, 0                                                           # Put 512 PTE entries
END_ENTRY(fixmap_pagetable_level1)                                              # End of declaration for fixmap_pagetable_level1 variable
                                                                                #
                                                                                #
                                                                                #
DECLARE_PAGE(dynamic_pagetable_pages)                                           # Declaration for dynamic_pagetable_pages variable
    .fill   EARLY_DYNAMIC_PAGE_TABLES * PAGE_SIZE, 1, 0                         # List of pages that we can dynamically update in runtime
END_ENTRY(dynamic_pagetable_pages)                                              # End of declaration for dynamic_pagetable_pages variable
                                                                                #
                                                                                #
                                                                                #
DECLARE_PAGE(init_pagetable)                                                    # Declaration for init_pagetable variable
    .fill   512, 8, 0                                                           # Put 512 PGD entries
END_ENTRY(init_pagetable)                                                       # End of declaration for init_pagetable variable
```

Here we are doing initial preparation for page table that we gonna use as<br/>
soon as possible

We want to jump to virtual address space starting from 0xFFFFFFFF80000000

According to Virtual -> Physical address conversion rules:<br/>
0xFFFFFFFF80000000 the same as<br/>
1111111111111111111111111111111110000000000000000000000000000000

Where:<br/>
1111111111111111 - Identify virtual address<br/>
111111111 - entry #511 in PGD<br/>
111111110 - entry #510 in PUD<br/>
000000000 - entry #0 in PMD<br/>
000000000000000000000 - Address in 2 MB PMD page<br/>
                        Combined with PTE since PMD pages has PGE flag

In case of 5 level paging:<br/>
1111111 - Identify virtual address<br/>
111111111 - entry #511 in PGD<br/>
111111111 - entry #511 in P4D<br/>
111111110 - entry #510 in PUD<br/>
000000000 - entry #0 in PMD<br/>
000000000000000000000 - Address in 2 MB PMD page<br/>
                        Combined with PTE since PMD pages has PGE flag

[adaptPageTable()](https://github.com/Gris87/ngos/blob/master/src/os/kernelbase/src/bits64/other/adaptpagetable.cpp#L417) function can be splitted into 3 parts:
* Adapting for predefined page table entries in order to make them points to the real physical address
* Adapting a set of PMD entries for 1 to 1 mapping of 1 GB starting from kernel image
* Creating additional entries in page table that let us finish instructions before jumping to virtual address space

We should get page table like on the image below:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/2.%20Kernel%20initialization/1.%20First%20steps%20in%20the%20kernel/Page%20table.png?raw=true" alt="Page table"/>
</p>

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Apply new page table                                                          #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    movq    $(X86_CR4_PAE | X86_CR4_PGE | X86_CR4_LA57), %rcx                   # Enable PAE mode, PGE and LA57
#else
    movq    $(X86_CR4_PAE | X86_CR4_PGE), %rcx                                  # Enable PAE mode and PGE
#endif
    movq    %rcx, %cr4                                                          # Update CR4 register with the provided flags
                                                                                #
    leaq    early_pagetable(%rip), %rax                                         # Put address of page table to RAX
    movq    %rax, %cr3                                                          # Update CR3 register with the address of page table
```

Since we have a valid page table we can apply it for further usage.

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Jump to virtual address space                                                 #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    $(virtual_address_space), %rax                                      # Put address of virtual_address_space label in virtual address space to RAX
    jmp     *%rax                                                               # Jump to virtual_address_space label in virtual address space
                                                                                #
virtual_address_space:                                                          # Label for jumping to virtual address space
```

We are ready to jump to virtual address space now.<br/>
Since we are building kernel image to be loaded at 0xFFFFFFFF80000000 address then the address of virtual_address_space label will be found at virtual address space.

### Setup stack for virtual address space

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup stack for virtual address space                                         #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    leaq    _stack_begin(%rip), %rsp                                            # Setup stack for virtual address space
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clear EFLAGS                                                                  #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   $0                                                                  # Push 0 to the stack
    popfq                                                                       # Restore EFLAGS from the stack
```

Here we are setting RSP register to address of _stack_begin variable located at the end of .stack section.<br/>
We also reset EFLAGS register after that.

### Clean up page table

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clean up page table                                                           #
# Since we are already at virtual address space we don't need for last resort   #
# entries that let us finish with the jump to virtual address space             #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    leaq    early_pagetable(%rip), %rdi                                         # Put address of early_pagetable variable to RDI
    movq    $(511 * 8), %rsi                                                    # We should clear all PGD entries except the last one
    call    memzero                                                             # Call memzero function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
```

We are not longer needed for last resort entries in page table since we made jump to virtual address space.<br/>
Here we are cleaning all PGD entries except the last one.

### Updating control register

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup CR0                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    $(X86_CR0_PE | X86_CR0_MP | X86_CR0_ET | \
              X86_CR0_NE | X86_CR0_WP | X86_CR0_AM | \
              X86_CR0_PG), %rax                                                 # Put flags to RAX
    movq    %rax, %cr0                                                          # Setup CR0 via RAX
```

Here we are setting some bits in the CR0 control register:

* X86_CR0_PE - system is in protected mode;
* X86_CR0_MP - controls interaction of WAIT/FWAIT instructions with TS flag in CR0;
* X86_CR0_ET - on the 386, it allowed to specify whether the external math coprocessor was an 80287 or 80387;
* X86_CR0_NE - enable internal x87 floating point error reporting when set, else enables PC style x87 error detection;
* X86_CR0_WP - when set, the CPU can't write to read-only pages when privilege level is 0;
* X86_CR0_AM - alignment check enabled if AM set, AC flag (in EFLAGS register) set, and privilege level is 3;
* X86_CR0_PG - enable paging.

### Setup Global Descriptor Table

The Global Descriptor Table (GDT) is a data structure used by Intel x86-family processors starting with the 80286 in order to define the characteristics of the various memory areas used during program execution, including the base address, the size, and access privileges like executability and writability. These memory areas are called segments in Intel terminology.<br/>
The GDT is still present in 64 bit mode; a GDT must be defined, but is generally never changed or used for segmentation.

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup GDT                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    lgdt    early_gdt_register(%rip)                                            # Setup GDT
```

The GDT is loaded using the `lgdt` instruction. It expects the location points to following structure:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/2.%20Kernel%20initialization/1.%20First%20steps%20in%20the%20kernel/GDT%20register.png?raw=true" alt="GDT register"/>
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

We also provide GDT location as address of gdt variable in virtual address space.

The table contains 8-byte entries. Each entry has the following structure:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/2.%20Kernel%20initialization/1.%20First%20steps%20in%20the%20kernel/GDT%20entry.png?raw=true" alt="GDT entry"/>
</p>

What "Limit 0:15" means is that the field contains bits 0-15 of the limit value. The base is a 32 bit value containing the linear address where the segment begins. The limit, a 20 bit value, tells the maximum addressable unit (either in 1 byte units, or in pages). Hence, if you choose page granularity (4 KB) and set the limit value to 0xFFFFF the segment will span the full 4 GiB address space. Here is the structure of the access byte and flags:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/2.%20Kernel%20initialization/1.%20First%20steps%20in%20the%20kernel/GDT%20flags.png?raw=true" alt="GDT flags"/>
</p>

The bit fields are:

* Pr: Present bit. This must be 1 for all valid selectors.
* Privl: Privilege, 2 bits. Contains the ring level, 0 = highest (kernel), 3 = lowest (user applications).
* Ex: Executable bit. If 1 code in this segment can be executed, ie. a code selector. If 0 it is a data selector.
* DC: Direction bit/Conforming bit.
    * Direction bit for data selectors: Tells the direction. 0 the segment grows up. 1 the segment grows down, ie. the offset has to be greater than the limit.
    * Conforming bit for code selectors:
        * If 1 code in this segment can be executed from an equal or lower privilege level. For example, code in ring 3 can far-jump to conforming code in a ring 2 segment. The privl-bits represent the highest privilege level that is allowed to execute the segment. For example, code in ring 0 cannot far-jump to a conforming code segment with privl==0x2, while code in ring 2 and 3 can. Note that the privilege level remains the same, ie. a far-jump form ring 3 to a privl==2-segment remains in ring 3 after the jump.
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
    .quad   0x00CF9B000000FFFF                                                  # GDT_ENTRY_KERNEL32_CS
    .quad   0x00AF9B000000FFFF                                                  # GDT_ENTRY_KERNEL_CS
    .quad   0x00CF93000000FFFF                                                  # GDT_ENTRY_KERNEL_DS
    .quad   0x00CFFB000000FFFF                                                  # GDT_ENTRY_DEFAULT_USER32_CS
    .quad   0x00CFF3000000FFFF                                                  # GDT_ENTRY_DEFAULT_USER_DS
    .quad   0x00AFFB000000FFFF                                                  # GDT_ENTRY_DEFAULT_USER_CS
    .quad   0x0000000000000000                                                  # Ignored
    .quad   0x0000000000000000                                                  # GDT_ENTRY_TSS
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

After that we setup GS register that points to the special IRQ stack used for interrupts handling:

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup GS segment                                                              #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movl    $(MSR_GS_BASE), %ecx                                                # Set ECX to MSR_GS_BASE
    leaq    irqStack(%rip), %rax                                                # Put address of irqStack variable to RAX
    movq    %rax, %rdx                                                          # Also put address of irqStack variable to RDX
    shrq    $32, %rdx                                                           # Keep only highest 32 bits in EDX, EAX will have lowest 32 bits
    wrmsr                                                                       # Write new value EDX:EAX to MSR_GS_BASE register
```

We need to put MSR_GS_BASE to the ECX register and load data from the EAX and EDX (which are point to the irqStack) with `wrmsr` instruction.<br/>
We don't use CS, FS, DS and SS segment registers for addressing in the 64 bit mode, but FS and GS registers can be used. FS and GS have a hidden part and this part contains descriptor which mapped to Model Specific Registers.<br/>
When a system call or interrupt occurred, there is no kernel stack at the entry point, so the value of the MSR_GS_BASE will store address of the interrupt stack.

### Jumping to C++ code

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Go to C++ code                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    %rsi, %rdi                                                          # Put address of boot parameters (RSI) to RDI
                                                                                #
    pushq   $(kernelMain_exit)                                                  # Push address of kernelMain_exit label to the stack in order to let us come back from the kernelMain function
    pushq   $(GDT_KERNEL_CS)                                                    # Push GDT_KERNEL_CS to the stack will tell long return to go in 64 bit mode and it will setup CS register as well
    pushq   $(kernelMain)                                                       # Push address of kernelMain function to the stack
    lretq                                                                       # Call long return will make us jump to kernelMain function in 64 bit mode
kernelMain_exit:                                                                # Label that we gonna use for returning from kernelMain function
```

Here we put the address of boot parameters to RDI and call [kernelMain()](https://github.com/Gris87/ngos/blob/master/src/os/kernelbase/src/main.cpp#L27) function by performing long jump return.<br/>
Pushing GDT_KERNEL_CS to the stack required for long jump return for CS register initialization.<br/>
We also push address of kernelMain_exit label to the stack that let us come back from kernelMain() function.

kernelMain() function declared in [src/os/kernelbase/src/main.cpp](https://github.com/Gris87/ngos/blob/master/src/os/kernelbase/src/main.cpp#L27) file:

```
CPP_EXTERN_C
void kernelMain(BootParams *params)
```

It is expected that we never leave kernelMain() function, but if we leave it somehow we will come to fail label:

```
fail:                                                                           # Label for failure
    hlt                                                                         # Wait for interrupt
    jmp    fail                                                                 # Loop in fail forever
```

In case of issue we came to fail label and hold PC into a forever loop.
