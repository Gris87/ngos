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
# testSseSqrtps declaration:                                                    #
#     void testSseSqrtps(float *a, float *b);                                   #
#                                                                               #
# RDI - a, address of 4 floats array                                            #
# RSI - b, address of result 4 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSseSqrtps)                                                  # testSseSqrtps function
    movaps  (%rdi), %xmm0                                                       # Put 4 floats located at RDI to XMM0
                                                                                #
    sqrtps  %xmm0, %xmm0                                                        # Compute Square Roots in parallel for 4 floats in XMM0 and store results in XMM0
                                                                                #
    movaps  %xmm0, (%rsi)                                                       # Put 4 floats from XMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSseSqrtps)                                                     # End of testSseSqrtps function
#endif
