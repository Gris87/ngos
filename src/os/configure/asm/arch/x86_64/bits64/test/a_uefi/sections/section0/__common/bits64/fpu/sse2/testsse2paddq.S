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
# testSse2Paddq declaration:                                                    #
#     void testSse2Paddq(u64 *a, u64 *b, u64 *c);                               #
#                                                                               #
# RDI - a, address of 2 quadwords array                                         #
# RSI - b, address of 2 quadwords array                                         #
# RDX - c, address of result 2 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Paddq)                                                  # testSse2Paddq function
    movdqa  (%rdi), %xmm0                                                       # Put 2 quadwords located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 2 quadwords located at RSI to XMM1
                                                                                #
    paddq   %xmm1, %xmm0                                                        # Add in parallel 2 quadwords in XMM0 with 2 quadwords in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 2 quadwords from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Paddq)                                                     # End of testSse2Paddq function
#endif
