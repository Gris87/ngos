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
# testSse2Psubw declaration:                                                    #
#     void testSse2Psubw(u16 *a, u16 *b, u16 *c);                               #
#                                                                               #
# RDI - a, subress of 8 words array                                             #
# RSI - b, subress of 8 words array                                             #
# RDX - c, subress of result 8 words array                                      #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Psubw)                                                  # testSse2Psubw function
    movdqa  (%rdi), %xmm0                                                       # Put 8 words located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 8 words located at RSI to XMM1
                                                                                #
    psubw   %xmm1, %xmm0                                                        # Subtract in parallel 8 words in XMM0 with 8 words in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 8 words from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Psubw)                                                     # End of testSse2Psubw function
#endif
