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
# testAvxVrsqrtps declaration:                                                  #
#     void testAvxVrsqrtps(float *a, float *b);                                 #
#                                                                               #
# RDI - a, address of 8 floats array                                            #
# RSI - b, address of result 8 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvxVrsqrtps)                                                # testAvxVrsqrtps function
    vmovaps     (%rdi), %ymm1                                                   # Put 8 floats located at RDI to YMM1
                                                                                #
    vrsqrtps    %ymm1, %ymm0                                                    # Compute Reciprocal of Square Roots (1/sqrt(A)) in parallel for 8 floats in YMM1 and store results in YMM0
                                                                                #
    vmovaps     %ymm0, (%rsi)                                                   # Put 8 floats from YMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvxVrsqrtps)                                                   # End of testAvxVrsqrtps function
#endif
