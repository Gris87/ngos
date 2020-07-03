#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
#if NGOS_BUILD_TEST_MODE == OPTION_YES
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# testAvx512cdVplzcntd declaration:                                             #
#     void testAvx512cdVplzcntd(u32 *a, u32 *b);                                #
#                                                                               #
# RDI - a, address of 16 doublewords array                                      #
# RDX - c, address of result 16 doublewords array                               #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512cdVplzcntd)                                           # testAvx512cdVplzcntd function
    vmovdqa32   (%rdi), %zmm1                                                   # Put 16 doublewords located at RDI to ZMM1
                                                                                #
    vplzcntd    %zmm1, %zmm0                                                    # Count amount of leading zeros for 16 doublewords in ZMM1 and store results to ZMM0
                                                                                #
    vmovdqa32   %zmm0, (%rsi)                                                   # Put 16 doublewords from ZMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512cdVplzcntd)                                              # End of testAvx512cdVplzcntd function
#endif
