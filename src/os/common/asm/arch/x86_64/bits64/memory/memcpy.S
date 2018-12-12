#include <ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# memcpy declaration:                                                           #
#     void* memcpy(void *dest, const void *src, u64 length);                    #
#                                                                               #
# RDI - dest, destination address                                               #
# RSI - src, source address                                                     #
# RDX - length, amount of bytes                                                 #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(memcpy)                                                         # memcpy function
    pushq   %rcx                                                                # Push RCX to the stack
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
    movq    %rdi, %rax                                                          # Put RDI to RAX as return value
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    %rdx, %rcx                                                          # Assign RDX to RCX
    shrq    $3, %rcx                                                            # Remove last 3 bits of RCX (Divide by 8)
                                                                                #
    rep; movsq                                                                  # Move with 8 byte blocks from RSI to RDI while RCX > 0
                                                                                #
    movq    %rdx, %rcx                                                          # Assign RDX to RCX
    andq    $7, %rcx                                                            # Keep last 3 bits of RCX
                                                                                #
    rep; movsb                                                                  # Move byte to byte from RSI to RDI while RCX > 0
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    popq   %rcx                                                                 # Restore RCX from the stack
    retq                                                                        # Return from the function
END_FUNCTION(memcpy)                                                            # End of memcpy function
