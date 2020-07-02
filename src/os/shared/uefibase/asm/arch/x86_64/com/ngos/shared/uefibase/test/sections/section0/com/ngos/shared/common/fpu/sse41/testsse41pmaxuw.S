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
# testSse41Pmaxuw declaration:                                                  #
#     void testSse41Pmaxuw(u16 *a, u16 *b, u16 *c);                             #
#                                                                               #
# RDI - a, address of 8 words array                                             #
# RSI - b, address of 8 words array                                             #
# RDX - c, address of result 8 words array                                      #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse41Pmaxuw)                                                # testSse41Pmaxuw function
    movdqa  (%rdi), %xmm0                                                       # Put 8 words located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 8 words located at RSI to XMM1
                                                                                #
    pmaxuw  %xmm1, %xmm0                                                        # Get in parallel the maximum unsigned values in each pair of 8 words in XMM0 with 8 words in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 8 words from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse41Pmaxuw)                                                   # End of testSse41Pmaxuw function
#endif
