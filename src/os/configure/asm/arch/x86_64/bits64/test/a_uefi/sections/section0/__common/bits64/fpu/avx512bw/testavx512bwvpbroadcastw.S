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
# testAvx512bwVpbroadcastw declaration:                                         #
#     void testAvx512bwVpbroadcastw(u16 *a, u16 value);                         #
#                                                                               #
# RDI - a, address of 32 words array                                            #
# RSI - value, value used for broadcasting                                      #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512bwVpbroadcastw)                                       # testAvx512bwVpbroadcastw function
    vpbroadcastw    %esi, %zmm0                                                 # Broadcast value from ESI to 32 words in ZMM0
                                                                                #
    vmovdqa64       %zmm0, (%rdi)                                               # Put 32 words from ZMM0 to location specified with RDI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512bwVpbroadcastw)                                          # End of testAvx512bwVpbroadcastw function
#endif
