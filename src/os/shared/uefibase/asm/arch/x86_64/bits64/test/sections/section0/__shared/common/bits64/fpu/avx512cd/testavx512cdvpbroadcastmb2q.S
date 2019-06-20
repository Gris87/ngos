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
# testAvx512cdVpbroadcastmb2q declaration:                                      #
#     void testAvx512cdVpbroadcastmb2q(u64 *a, u8 mask);                        #
#                                                                               #
# RDI - a, address of 8 quadwords array                                         #
# RSI - mask, value used for broadcasting                                       #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512cdVpbroadcastmb2q)                                    # testAvx512cdVpbroadcastmb2q function
    kmovb               %esi, %k1                                               # Put mask value to K1
                                                                                #
    vpbroadcastmb2q     %k1, %zmm0                                              # Broadcast value from K1 to 8 quadwords in ZMM0
                                                                                #
    vmovdqa64           %zmm0, (%rdi)                                           # Put 8 quadwords from ZMM0 to location specified with RDI
    xorl                %esi, %esi                                              # Put 0 to ESI
    kmovb               %esi, %k1                                               # Reset K1
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512cdVpbroadcastmb2q)                                       # End of testAvx512cdVpbroadcastmb2q function
#endif
