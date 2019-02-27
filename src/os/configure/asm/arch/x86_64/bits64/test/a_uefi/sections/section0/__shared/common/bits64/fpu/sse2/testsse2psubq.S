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
# testSse2Psubq declaration:                                                    #
#     void testSse2Psubq(u64 *a, u64 *b, u64 *c);                               #
#                                                                               #
# RDI - a, subress of 2 quadwords array                                         #
# RSI - b, subress of 2 quadwords array                                         #
# RDX - c, subress of result 2 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Psubq)                                                  # testSse2Psubq function
    movdqa  (%rdi), %xmm0                                                       # Put 2 quadwords located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 2 quadwords located at RSI to XMM1
                                                                                #
    psubq   %xmm1, %xmm0                                                        # Subtract in parallel 2 quadwords in XMM0 with 2 quadwords in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 2 quadwords from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Psubq)                                                     # End of testSse2Psubq function
#endif
