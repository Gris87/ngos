#include <common/src/com/ngos/shared/common/ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# memset declaration:                                                           #
#     void* memset(void *dest, u8 ch, u64 length);                              #
#                                                                               #
# RDI - dest, destination address                                               #
# RSI - ch, byte value                                                          #
# RDX - length, amount of bytes                                                 #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(memset)                                                         # memset function
    movq    %rdi, %r9                                                           # Store RDI in R9
    movq    %rdx, %rcx                                                          # Duplicate RDX to RCX
    andq    $7, %rdx                                                            # Keep last 3 bits of RDX
    shrq    $3, %rcx                                                            # Remove last 3 bits of RCX (Divide by 8)
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
#  Cloning 1 byte from RSI to all 8 bytes of RAX                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movzbl  %sil, %esi                                                          # Put zeros to all bytes of ESI except the little one
    movabs  $0x0101010101010101, %rax                                           # Put ones to each byte of RAX
    imulq   %rsi, %rax                                                          # Multiply RAX on RSI. Clone byte from RSI to each byte of RAX
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    rep; stosq                                                                  # Assign with 8 byte blocks from RAX to RDI while RCX > 0
    movq    %rdx, %rcx                                                          # Assign RDX to RCX
    rep; stosb                                                                  # Assign byte to byte from RAX to RDI while RCX > 0
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    %r9, %rax                                                           # Restore original RDI value from R9 to RAX
    retq                                                                        # Return from the function
END_FUNCTION(memset)                                                            # End of memset function
