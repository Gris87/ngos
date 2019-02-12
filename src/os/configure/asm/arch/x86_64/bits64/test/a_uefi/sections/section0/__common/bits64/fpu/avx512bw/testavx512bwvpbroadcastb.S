#include <buildconfig.h>
#include <ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
#if NGOS_BUILD_TEST_MODE == OPTION_YES
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# testAvx512bwVpbroadcastb declaration:                                         #
#     void testAvx512bwVpbroadcastb(u8 *a, u8 value);                           #
#                                                                               #
# RDI - a, address of 64 bytes array                                            #
# RSI - value, value used for broadcasting                                      #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512bwVpbroadcastb)                                       # testAvx512bwVpbroadcastb function
    vpbroadcastb    %esi, %zmm0                                                 # Broadcast value from ESI to 64 bytes in ZMM0
                                                                                #
    vmovdqa64       %zmm0, (%rdi)                                               # Put 64 bytes from ZMM0 to location specified with RDI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512bwVpbroadcastb)                                          # End of testAvx512bwVpbroadcastb function
#endif
