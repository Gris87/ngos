#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/cpu/flags.h>
#include <common/src/com/ngos/shared/common/gdt/segments.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# switchToFiveLevelPaging declaration:                                          #
#     void switchToFiveLevelPaging(u8 *topLevelPaging);                         #
#                                                                               #
# RDI - topLevelPaging, address of top level page                               #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(switchToFiveLevelPaging)                                        # switchToFiveLevelPaging function
    movq    %cr4, %rbx                                                          # Put CR4 to RBX
    testq   $(X86_CR4_LA57), %rbx                                               # Check for LA57 flag in RBX
    jnz     paging_level_5_cr3                                                  # Jump to paging_level_5_cr3 label if flag LA57 is set
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  We need to go in 32 bit mode in order to enable 5 level paging               #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushq   $(GDT_KERNEL32_CS)                                                  # Push GDT_KERNEL32_CS to the stack will tell long return to go in 32 bit mode
    leaq    compatible_mode(%rip), %rax                                         # Assign address of compatible_mode label to RAX
    pushq   %rax                                                                # Push RAX to the stack
                                                                                #
    lretq                                                                       # Call long return will make us jump to compatible_mode label in 32 bit mode
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  We are in 32 bits now                                                        #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
.code32                                                                         # Generate code in 32 bits mode
compatible_mode:                                                                # Label used for long return with changing mode to 32 bits
    movl    $(GDT_KERNEL_DS), %eax                                              # Initialize via EAX...
    movl    %eax, %ds                                                           # Data segment to GDT_KERNEL_DS
    movl    %eax, %ss                                                           # Stack segment to GDT_KERNEL_DS
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  Disable paging                                                               #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movl    %cr0, %ecx                                                          # Put CR0 to ECX
    andl    $(~X86_CR0_PG), %ecx                                                # Remove paging flag from ECX
    movl    %ecx, %cr0                                                          # Store ECX to CR0
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  Initialize CR3 with our 5 level page table                                   #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movl    %edi, %cr3                                                          # Put address of page table to CR3
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  Enable PAE and LA57 mode                                                     #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    orl     $(X86_CR4_LA57), %ebx                                               # Adding LA57 flag to EBX. RBX was initialized with CR4 before
    movl    %ebx, %cr4                                                          # Store EBX to CR4
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  Since we can't use paging_level_5(%eip) we will calculate it as below        #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    call    1f                                                                  # These...
1:                                                                              # instructions...
    popl    %edi                                                                # will give us...
    subl    $1b, %edi                                                           # Image Base in EDI
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  Enable paging                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    orl     $(X86_CR0_PG | X86_CR0_PE), %ecx                                    # Adding paging flag to ECX. ECX was initialized with CR0 before
    movl    %ecx, %cr0                                                          # Store ECX to CR0
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  Go back to 64 bit mode                                                       #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    pushl   $(GDT_KERNEL_CS)                                                    # Push GDT_KERNEL_CS to the stack will tell long return to go in 64 bit mode
    leal    paging_level_5(%edi), %eax                                          # Assign address of paging_level_5 label to EAX
    pushl   %eax                                                                # Push EAX to the stack
                                                                                #
    lretl                                                                       # Call long return will make us jump to paging_level_5 label in 64 bit mode
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  We are in 64 bits now                                                        #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
paging_level_5_cr3:                                                             # Label for jumping when paging level 5 enabled but we need to update CR3
    movq    %rdi, %cr3                                                          # Put address of page table to CR3
paging_level_5:                                                                 # Label for jumping when paging level 5 enabled
    retq                                                                        # Return from the function
END_FUNCTION(switchToFiveLevelPaging)                                           # End of switchToFiveLevelPaging function
#endif
