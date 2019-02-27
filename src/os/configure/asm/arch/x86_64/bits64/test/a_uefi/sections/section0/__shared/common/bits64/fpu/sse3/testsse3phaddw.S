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
# testSse3Phaddw declaration:                                                   #
#     void testSse3Phaddw(u16 *a, u16 *b, u16 *c);                              #
#                                                                               #
# RDI - a, address of 8 words array                                             #
# RSI - b, address of 8 words array                                             #
# RDX - c, address of result 8 words array                                      #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse3Phaddw)                                                 # testSse3Phaddw function
    movdqa  (%rdi), %xmm0                                                       # Put 8 words located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 8 words located at RSI to XMM1
                                                                                #
    phaddw  %xmm1, %xmm0                                                        # Add words from XMM0 with words from XMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; ... ; C[7] = B[6] + B[7]. The results stored in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 8 words from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse3Phaddw)                                                    # End of testSse3Phaddw function
#endif
