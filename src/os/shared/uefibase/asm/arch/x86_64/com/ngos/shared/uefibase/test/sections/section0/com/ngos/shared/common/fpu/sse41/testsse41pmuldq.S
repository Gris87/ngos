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
# testSse41Pmuldq declaration:                                                  #
#     void testSse41Pmuldq(i32 *a, i32 *b, i64 *c);                             #
#                                                                               #
# RDI - a, address of 4 doublewords array                                       #
# RSI - b, address of 4 doublewords array                                       #
# RDX - c, address of result 2 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse41Pmuldq)                                                # testSse41Pmuldq function
    movdqa  (%rdi), %xmm0                                                       # Put 4 doublewords located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 4 doublewords located at RSI to XMM1
                                                                                #
    pmuldq  %xmm1, %xmm0                                                        # Multiply in parallel 2 doublewords in XMM0 with 2 doublewords in XMM1 as following: C[0] = A[0] * B[0]; C[1] = A[2] * B[2]. The 64 bit results stored in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 2 quadwords from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse41Pmuldq)                                                   # End of testSse41Pmuldq function
#endif
