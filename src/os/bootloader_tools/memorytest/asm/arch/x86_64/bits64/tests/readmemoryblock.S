#include <ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# readMemoryBlock declaration:                                                  #
#     void readMemoryBlock(u8 *blockBuffer, u8 *address);                       #
#                                                                               #
# RDI - blockBuffer, address of temporary block storage                         #
# RSI - address, address of memory block to read                                #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(readMemoryBlock)                                                # readMemoryBlock function
    movq    $131072, %rcx                                                       # Put 131072 to RCX. 131072 * 8 = 1 MB
    rep; lodsq                                                                  # Load 8 byte blocks from RSI to RAX while RCX > 0
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(readMemoryBlock)                                                   # End of readMemoryBlock function
