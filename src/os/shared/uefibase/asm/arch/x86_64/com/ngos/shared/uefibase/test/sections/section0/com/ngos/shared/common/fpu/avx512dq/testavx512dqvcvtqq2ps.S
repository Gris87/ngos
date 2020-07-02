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
# testAvx512dqVcvtqq2ps declaration:                                            #
#     void testAvx512dqVcvtqq2ps(u64 *a, float *b);                             #
#                                                                               #
# RDI - a, address of 8 quadwords array                                         #
# RDX - b, address of result 8 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512dqVcvtqq2ps)                                          # testAvx512dqVcvtqq2ps function
    vmovdqa64   (%rdi), %zmm1                                                   # Put 8 quadwords located at RDI to ZMM1
                                                                                #
    vcvtqq2ps   %zmm1, %ymm0                                                    # Convert 8 quadwords in ZMM1 to 8 floats in YMM0
                                                                                #
    vmovaps     %ymm0, (%rsi)                                                   # Put 8 floats from YMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512dqVcvtqq2ps)                                             # End of testAvx512dqVcvtqq2ps function
#endif
