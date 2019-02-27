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
# testAvx512dqVcvtps2qq declaration:                                            #
#     void testAvx512dqVcvtps2qq(u64 *a, float *b);                             #
#                                                                               #
# RDI - a, address of 8 floats array                                            #
# RDX - b, address of result 8 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512dqVcvtps2qq)                                          # testAvx512dqVcvtps2qq function
    vmovaps     (%rdi), %ymm1                                                   # Put 8 floats located at RDI to YMM1
                                                                                #
    vcvtps2qq   %ymm1, %zmm0                                                    # Convert 8 floats in YMM1 to 8 quadwords in ZMM0
                                                                                #
    vmovdqa64   %zmm0, (%rsi)                                                   # Put 8 quadwords from ZMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512dqVcvtps2qq)                                             # End of testAvx512dqVcvtps2qq function
#endif
