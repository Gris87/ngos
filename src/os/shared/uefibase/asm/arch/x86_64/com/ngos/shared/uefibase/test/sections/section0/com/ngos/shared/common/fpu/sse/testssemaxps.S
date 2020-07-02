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
# testSseMaxps declaration:                                                     #
#     void testSseMaxps(float *a, float *b, float *c);                          #
#                                                                               #
# RDI - a, address of 4 floats array                                            #
# RSI - b, address of 4 floats array                                            #
# RDX - c, address of result 4 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSseMaxps)                                                   # testSseMaxps function
    movaps  (%rdi), %xmm0                                                       # Put 4 floats located at RDI to XMM0
    movaps  (%rsi), %xmm1                                                       # Put 4 floats located at RSI to XMM1
                                                                                #
    maxps   %xmm1, %xmm0                                                        # Get in parallel the maximum values in each pair of 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                                                                                #
    movaps  %xmm0, (%rdx)                                                       # Put 4 floats from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSseMaxps)                                                      # End of testSseMaxps function
#endif
