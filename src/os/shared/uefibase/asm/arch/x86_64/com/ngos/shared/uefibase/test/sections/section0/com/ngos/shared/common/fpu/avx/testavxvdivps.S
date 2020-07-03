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
# testAvxVdivps declaration:                                                    #
#     void testAvxVdivps(float *a, float *b, float *c);                         #
#                                                                               #
# RDI - a, address of 8 floats array                                            #
# RSI - b, address of 8 floats array                                            #
# RDX - c, address of result 8 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvxVdivps)                                                  # testAvxVdivps function
    vmovaps     (%rdi), %ymm1                                                   # Put 8 floats located at RDI to YMM1
    vmovaps     (%rsi), %ymm2                                                   # Put 8 floats located at RSI to YMM2
                                                                                #
    vdivps      %ymm2, %ymm1, %ymm0                                             # Divide in parallel 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                                                                                #
    vmovaps     %ymm0, (%rdx)                                                   # Put 8 floats from YMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvxVdivps)                                                     # End of testAvxVdivps function
#endif
