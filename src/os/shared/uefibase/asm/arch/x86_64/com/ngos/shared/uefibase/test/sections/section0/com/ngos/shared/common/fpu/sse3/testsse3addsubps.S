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
# testSse3Addsubps declaration:                                                 #
#     void testSse3Addsubps(float *a, float *b, float *c);                      #
#                                                                               #
# RDI - a, address of 4 floats array                                            #
# RSI - b, address of 4 floats array                                            #
# RDX - c, address of result 4 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse3Addsubps)                                               # testSse3Addsubps function
    movaps      (%rdi), %xmm0                                                   # Put 4 floats located at RDI to XMM0
    movaps      (%rsi), %xmm1                                                   # Put 4 floats located at RSI to XMM1
                                                                                #
    addsubps    %xmm1, %xmm0                                                    # Add 2nd/4th float of XMM0 with 2nd/4th float of XMM1 and subtract 1st/3rd float of XMM0 with 1st/3rd float of XMM1. The results stored in XMM0
                                                                                #
    movaps      %xmm0, (%rdx)                                                   # Put 4 floats from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse3Addsubps)                                                  # End of testSse3Addsubps function
#endif
