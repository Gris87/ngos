#include <common/src/com/ngos/shared/common/ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# writeMemoryBlock declaration:                                                 #
#     void writeMemoryBlock(u8 *blockBuffer, u8 *address);                      #
#                                                                               #
# RDI - blockBuffer, address of temporary block storage                         #
# RSI - address, address of memory block to write                               #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(writeMemoryBlock)                                               # writeMemoryBlock function
    movq    $131072, %rcx                                                       # Put 131072 to RCX. 131072 * 8 = 1 MB
    rep; stosq                                                                  # Assign with 8 byte blocks from RAX to RDI while RCX > 0
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(writeMemoryBlock)                                                  # End of writeMemoryBlock function
