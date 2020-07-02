#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/gdt/segments.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/page/macros.h>
#include "src/com/ngos/configure/other/asm/generated/asmoffsets.h"
#include "src/com/ngos/configure/other/configuredefines.h"
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".entry_point", "ax"                                                   # entry_point section (a - allocatable, x - executable)
                                                                                #
.globl  _start                                                                  # Make _start visible for linker
_start:                                                                         # Global pointer to the entry point in order to make linker silent
                                                                                #
# ============================================================================= # =============================================================================
# Entry point                                                                   #
#                                                                               #
# RDX - address of systemTable                                                  #
# RCX - address of imageHandle                                                  #
# ============================================================================= # =============================================================================
                                                                                #
    andq    $-0x10, %rsp                                                        # Make RSP aligned
                                                                                #
    movq    %rcx, %rdi                                                          # Put address of imageHandle to RDI
    movq    %rdx, %rsi                                                          # Put address of systemTable to RSI
    leaq    _start(%rip), %rdx                                                  # Put address of entry point to RDX
                                                                                #
    call    uefiMain                                                            # Call uefiMain function
                                                                                #
    cmpq    $0, %rax                                                            # IF result == 0
    je      fail                                                                #   THEN jump to fail
                                                                                #
    movq    %rax, %rsi                                                          # Put address of boot parameters to RSI
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Jump to the relocated address                                                 #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    ASM_OFFSET_BOOT_PARAM_KERNEL_LOCATION(%rsi), %rax                   # Get the relocated address of kernel
    addq    $(relocated_address - _start), %rax                                 # Get address of relocated_address label in relocated address space
    jmp     *%rax                                                               # Jump to relocated_address label in relocated address space
                                                                                #
relocated_address:                                                              # Label for relocated address
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clear EFLAGS                                                                  #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   $0                                                                  # Push 0 to the stack
    popfq                                                                       # Restore EFLAGS from the stack
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup GDT                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    leaq    gdt(%rip), %rax                                                     # Put address of gdt variable to RAX
    movq    %rax, early_gdt_register + 0x02(%rip)                               # Store address of gdt variable in early_gdt_register
                                                                                #
    lgdt    early_gdt_register(%rip)                                            # Setup GDT
                                                                                #
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
                                                                                #
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
                                                                                #
                                                                                #
                                                                                #
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    call    extractKernel                                                       # Call extractKernel function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
                                                                                #
    cmpq    $0, %rax                                                            # IF result == 0
    je      fail                                                                #   THEN jump to fail
                                                                                #
    jmp     *%rax                                                               # Jump to decompressed kernel
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Failure                                                                       #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
fail:                                                                           # Label for failure
    hlt                                                                         # Wait for interrupt
    jmp    fail                                                                 # Loop in fail forever
                                                                                #
                                                                                #
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Global Descriptor Table                                                       #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
.section ".gdt", "a"                                                            # gdt section (a - allocatable)
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
                                                                                #
ENTRY(early_gdt_register)                                                       # Declaration for early_gdt_register variable
    .word   GDT_ENTRIES * 8 - 1                                                 # Put size of gdt variable. The size subtracted by 1 because the maximum value of size is 65535, while the GDT can be up to 65536 bytes (a maximum of 8192 entries). Further no GDT can have a size of 0.
    .quad   gdt                                                                 # Put address of gdt variable
END_ENTRY(early_gdt_register)                                                   # End of declaration for early_gdt_register variable
