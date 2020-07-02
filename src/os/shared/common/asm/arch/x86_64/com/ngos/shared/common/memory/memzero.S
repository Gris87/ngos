#include <common/src/com/ngos/shared/common/ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# memzero declaration:                                                          #
#     void* memzero(void *dest, u64 length);                                    #
#                                                                               #
# RDI - dest, destination address                                               #
# RSI - length, amount of bytes                                                 #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(memzero)                                                        # memzero function
    movq    %rdi, %r9                                                           # Store RDI in R9
    movq    %rsi, %rcx                                                          # Duplicate RSI to RCX
    andq    $7, %rsi                                                            # Keep last 3 bits of RSI
    shrq    $3, %rcx                                                            # Remove last 3 bits of RCX (Divide by 8)
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq  $0, %rax                                                              # Assign RAX to 0
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    rep; stosq                                                                  # Assign with 8 byte blocks from RAX to RDI while RCX > 0
    movq    %rsi, %rcx                                                          # Assign RSI to RCX
    rep; stosb                                                                  # Assign byte to byte from RAX to RDI while RCX > 0
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    %r9, %rax                                                           # Restore original RDI value from R9 to RAX
    retq                                                                        # Return from the function
END_FUNCTION(memzero)                                                           # End of memzero function
