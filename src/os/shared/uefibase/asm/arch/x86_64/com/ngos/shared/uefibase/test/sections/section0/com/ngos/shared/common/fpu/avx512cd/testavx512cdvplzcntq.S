#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
#if NGOS_BUILD_TEST_MODE == OPTION_YES
.code64                                                                         # Generate code in 64 bits mode
.section ".asm_code", "ax"                                                      # asm_code section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# testAvx512cdVplzcntq declaration:                                             #
#     void testAvx512cdVplzcntq(u64 *a, u64 *b);                                #
#                                                                               #
# RDI - a, address of 8 quadwords array                                         #
# RDX - c, address of result 8 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512cdVplzcntq)                                           # testAvx512cdVplzcntq function
    vmovdqa64   (%rdi), %zmm1                                                   # Put 8 quadwords located at RDI to ZMM1
                                                                                #
    vplzcntq    %zmm1, %zmm0                                                    # Count amount of leading zeros for 8 quadwords in ZMM1 and store results to ZMM0
                                                                                #
    vmovdqa64   %zmm0, (%rsi)                                                   # Put 8 quadwords from ZMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512cdVplzcntq)                                              # End of testAvx512cdVplzcntq function
#endif
