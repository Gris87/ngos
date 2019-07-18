#include <buildconfig.h>
#include <common/src/bits64/cpu/flags.h>
#include <common/src/bits64/cpu/msr/msrregisters.h>
#include <gdt/segments.h>
#include <idt/macros.h>
#include <kernelbase/src/bits64/other/kerneldefines.h>
#include <ngos/linkage.h>
#include <pagetable/flags.h>
#include <pagetable/macros.h>
                                                                                #
                                                                                #
                                                                                #
# ============================================================================= # =============================================================================
# PMDS macro                                                                    # This macro is helpful to declare list of PMD entries with specified flags
# ============================================================================= # =============================================================================
                                                                                #
#define PMDS(START, PERMISSIONS, COUNT)                     \
    i = 0                                               ;   \
    .rept   (COUNT)                                     ;   \
    .quad   (START) + (i << PMD_SHIFT) + (PERMISSIONS)  ;   \
    i = i + 1                                           ;   \
    .endr
                                                                                #
                                                                                #
                                                                                #
# ============================================================================= # =============================================================================
# DECLARE_PAGE macro                                                            # This macro allows to declare well aligned page with global name
# ============================================================================= # =============================================================================
                                                                                #
#define DECLARE_PAGE(name)  \
    .balign PAGE_SIZE   ;   \
    ENTRY(name)
                                                                                #
                                                                                #
                                                                                #
# ============================================================================= # =============================================================================
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".kernel_code", "ax"                                                   # kernel_code section (a - allocatable, x - executable)
                                                                                #
.globl  _start                                                                  # Make _start visible for linker
_start:                                                                         # Global pointer to the entry point in order to make linker silent
                                                                                #
# ============================================================================= # =============================================================================
# Entry point                                                                   #
#                                                                               #
# RSI - address of BootParams                                                   #
# ============================================================================= # =============================================================================
                                                                                #
    leaq    _stack_begin(%rip), %rsp                                            # Setup stack in physical address space
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clear BSS                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    leaq    _bss_begin(%rip), %rdi                                              # Put start address of bss section to RDI. _bss_begin declared in linker.ld file
    leaq    _bss_end(%rip), %rsi                                                # Put end address of bss section to RSI. _bss_end declared in linker.ld file
    subq    %rdi, %rsi                                                          # Put size of bss section to RSI
    call    memzero                                                             # Call memzero function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
                                                                                #
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
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Apply new page table                                                          #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    leaq    early_pagetable(%rip), %rbx                                         # Put address of page table to RBX
    movq    %rbx, %cr3                                                          # Update CR3 register with the address of page table
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Jump to virtual address space                                                 #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    relocated_virtual_address(%rip), %rax                               # Put address of virtual_address_space label in virtual address space to RAX
    jmp     *%rax                                                               # Jump to virtual_address_space label in virtual address space
                                                                                #
relocated_virtual_address:                                                      # Label that holds address of virtual address space and should be changed during relocation
    .quad   virtual_address_space                                               # Put address of virtual_address_space label
                                                                                #
virtual_address_space:                                                          # Label for jumping to virtual address space
                                                                                #
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
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Clean up page table                                                           #
# Since we are already at virtual address space we don't need for last resort   #
# entries that let us finish with the jump to virtual address space             #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   %rsi                                                                # Push address of boot parameters (RSI) to the stack
    leaq    dynamic_pagetable_pages(%rip), %rdi                                 # Put address of dynamic_pagetable_pages variable to RDI
    movq    $(EARLY_DYNAMIC_PAGE_TABLES * PAGE_SIZE), %rsi                      # We should clear all entries
    call    memzero                                                             # Call memzero function
    popq    %rsi                                                                # Restore address of boot parameters back to RSI from the stack
                                                                                #
    movq    %rbx, %cr3                                                          # Update CR3 register with the address of page table once again to force CPU to clean TLB cache
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup CR0                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    $(X86_CR0_PE | X86_CR0_MP | X86_CR0_ET | \
              X86_CR0_NE | X86_CR0_WP | X86_CR0_AM | \
              X86_CR0_PG), %rax                                                 # Put flags to RAX
    movq    %rax, %cr0                                                          # Setup CR0 via RAX
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Setup GDT                                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
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
# Setup GS segment                                                              #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movl    $(MSR_GS_BASE), %ecx                                                # Set ECX to MSR_GS_BASE
    leaq    irqStack(%rip), %rax                                                # Put address of irqStack variable to RAX
    movq    %rax, %rdx                                                          # Also put address of irqStack variable to RDX
    shrq    $32, %rdx                                                           # Keep only highest 32 bits in EDX, EAX will have lowest 32 bits
    wrmsr                                                                       # Write new value EDX:EAX to MSR_GS_BASE register
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Go to C++ code                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    %rsi, %rdi                                                          # Put address of boot parameters (RSI) to RDI
                                                                                #
    leaq    kernelMain_exit(%rip), %rax                                         # Put address of kernelMain_exit label to RAX
    leaq    kernelMain(%rip), %rbx                                              # Put address of kernelMain function to RBX
                                                                                #
    pushq   %rax                                                                # Push address of kernelMain_exit label to the stack in order to let us come back from the kernelMain function
    pushq   $(GDT_KERNEL_CS)                                                    # Push GDT_KERNEL_CS to the stack will tell long return to go in 64 bit mode and it will setup CS register as well
    pushq   %rbx                                                                # Push address of kernelMain function to the stack
    lretq                                                                       # Call long return will make us jump to kernelMain function in 64 bit mode
kernelMain_exit:                                                                # Label that we gonna use for returning from kernelMain function
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
# Page table                                                                    #
#                                                                               #
# Here we are doing initial preparation for page table that we gonna use as     #
# soon as possible                                                              #
#                                                                               #
# We want to jump to virtual address space starting from 0xFFFFFFFF80000000     #
#                                                                               #
# According to Virtual -> Physical address conversion rules:                    #
# | 0xFFFFFFFF80000000 the same as                                              #
# | 1111111111111111111111111111111110000000000000000000000000000000            #
#                                                                               #
# Where:                                                                        #
# | 1111111111111111 - Identify virtual address                                 #
# | 111111111 - entry #511 in PGD                                               #
# | 111111110 - entry #510 in PUD                                               #
# | 000000000 - entry #0 in PMD                                                 #
# | 000000000000000000000 - Address in 2 MB PMD page                            #
#                           Combined with PTE since PMD pages has PGE flag      #
#                                                                               #
# In case of 5 level paging:                                                    #
# | 1111111 - Identify virtual address                                          #
# | 111111111 - entry #511 in PGD                                               #
# | 111111111 - entry #511 in P4D                                               #
# | 111111110 - entry #510 in PUD                                               #
# | 000000000 - entry #0 in PMD                                                 #
# | 000000000000000000000 - Address in 2 MB PMD page                            #
#                           Combined with PTE since PMD pages has PGE flag      #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
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
    .fill   506, 8, 0                                                           # Skip 506 entries in PMD
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
DECLARE_PAGE(video_ram_pagetable_pages)                                         # Declaration for video_ram_pagetable_pages variable
    .fill   EARLY_VIDEO_RAM_PAGE_TABLES * PAGE_SIZE, 1, 0                       # List of pages that we can use for video ram
END_ENTRY(video_ram_pagetable_pages)                                            # End of declaration for video_ram_pagetable_pages variable
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
                                                                                #
ENTRY(early_gdt_register)                                                       # Declaration for early_gdt_register variable
    .word   GDT_ENTRIES * 8 - 1                                                 # Put size of gdt variable. The size subtracted by 1 because the maximum value of size is 65535, while the GDT can be up to 65536 bytes (a maximum of 8192 entries). Further no GDT can have a size of 0.
    .quad   gdt                                                                 # Put address of gdt variable
END_ENTRY(early_gdt_register)                                                   # End of declaration for early_gdt_register variable
                                                                                #
                                                                                #
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# IDT Handlers                                                                  #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
.section ".idt", "ax"                                                           # idt section (a - allocatable, x - executable)
                                                                                #
ENTRY(earlyIdtHandlerArray)                                                     # Declaration for earlyIdtHandlerArray variable
    i = 0                                                                       # Initialize counter
                                                                                #
    .rept   IDT_EXCEPTIONS_COUNT                                                # Iterate through the number of IDT exceptions
                                                                                #
    .ifeq   (IDT_EXCEPTIONS_WITH_ERRCODES_MASK >> i) & 1                        # Some exceptions may push error code to the stack
    pushq   $0                                                                  # We will push error code 0 when...
    .endif                                                                      # current exception not in IDT_EXCEPTIONS_WITH_ERRCODES_MASK list
                                                                                #
    pushq   $i                                                                  # Push also exception vector number to the stack
                                                                                #
    jmp     earlyIdtHandler                                                     # Jump to earlyIdtHandler
    i = i + 1                                                                   # Increment counter
    .fill   earlyIdtHandlerArray + i * EARLY_IDT_HANDLER_SIZE - ., 1, 0xCC      # earlyIdtHandlerArray is the list of instruction blocks. Where block size is 9 bytes. We need to fill remaining bytes with 0xCC(int3) when block is less than 9 bytes
    .endr                                                                       # End of cycle
END_ENTRY(earlyIdtHandlerArray)                                                 # End of declaration for earlyIdtHandlerArray variable
                                                                                #
GLOBAL_FUNCTION(earlyIdtHandler)                                                # earlyIdtHandler function
    jmp     fail                                                                # Temp action
END_FUNCTION(earlyIdtHandler)                                                   # End of earlyIdtHandler function
                                                                                #
ENTRY(idt)                                                                      # Declaration for idt variable
    .fill   IDT_EXCEPTIONS_COUNT * 16, 1, 0                                     # Put zeros for IDT_EXCEPTIONS_COUNT entries
END_ENTRY(idt)                                                                  # End of declaration for idt variable
                                                                                #
ENTRY(earlyIdtRegister)                                                         # Declaration for earlyIdtRegister variable
    .word   IDT_EXCEPTIONS_COUNT * 16 - 1                                       # Put size of idt variable. The size subtracted by 1 because the maximum value of size is 65535
    .quad   idt                                                                 # Put address of idt variable
END_ENTRY(earlyIdtRegister)                                                     # End of declaration for earlyIdtRegister variable
                                                                                #
                                                                                #
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Stack                                                                         #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
.section ".stack", "a"                                                          # stack section (a - allocatable)
    .fill   EARLY_STACK_SIZE, 1, 0                                              # Identify the stack size
