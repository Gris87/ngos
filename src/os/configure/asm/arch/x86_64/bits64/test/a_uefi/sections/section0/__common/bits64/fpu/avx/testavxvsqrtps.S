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
# testAvxVsqrtps declaration:                                                   #
#     void testAvxVsqrtps(float *a, float *b);                                  #
#                                                                               #
# RDI - a, address of 8 floats array                                            #
# RSI - b, address of result 8 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvxVsqrtps)                                                 # testAvxVsqrtps function
    vmovaps     (%rdi), %ymm1                                                   # Put 8 floats located at RDI to YMM1
                                                                                #
    vsqrtps     %ymm1, %ymm0                                                    # Compute Square Roots in parallel for 8 floats in YMM1 and store results in YMM0
                                                                                #
    vmovaps     %ymm0, (%rsi)                                                   # Put 8 floats from YMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvxVsqrtps)                                                    # End of testAvxVsqrtps function
#endif
