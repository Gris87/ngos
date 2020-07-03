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
# testSse3Phaddd declaration:                                                   #
#     void testSse3Phaddd(u32 *a, u32 *b, u32 *c);                              #
#                                                                               #
# RDI - a, address of 4 doublewords array                                       #
# RSI - b, address of 4 doublewords array                                       #
# RDX - c, address of result 4 doublewords array                                #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse3Phaddd)                                                 # testSse3Phaddd function
    movdqa  (%rdi), %xmm0                                                       # Put 4 doublewords located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 4 doublewords located at RSI to XMM1
                                                                                #
    phaddd  %xmm1, %xmm0                                                        # Add doublewords from XMM0 with doublewords from XMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; C[2] = B[0] + B[1]; C[3] = B[2] + B[3]. The results stored in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 4 doublewords from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse3Phaddd)                                                    # End of testSse3Phaddd function
#endif
