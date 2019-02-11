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
# testAvx512cdVpbroadcastmw2d declaration:                                      #
#     void testAvx512cdVpbroadcastmw2d(u32 *a, u16 mask);                       #
#                                                                               #
# RDI - a, address of 16 doublewords array                                      #
# RSI - mask, value used for broadcasting                                       #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512cdVpbroadcastmw2d)                                    # testAvx512cdVpbroadcastmw2d function
    kmovw               %esi, %k0                                               # Put mask value to K0
                                                                                #
    vpbroadcastmw2d     %k0, %zmm0                                              # Broadcast value from K0 to 16 doublewords in ZMM0
                                                                                #
    vmovdqa32           %zmm0, (%rdi)                                           # Put 16 doublewords from ZMM0 to location specified with RDI
    xorq                %rsi, %rsi                                              # Put 0 to RSI
    kmovw               %esi, %k0                                               # Reset K0
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512cdVpbroadcastmw2d)                                       # End of testAvx512cdVpbroadcastmw2d function
#endif
