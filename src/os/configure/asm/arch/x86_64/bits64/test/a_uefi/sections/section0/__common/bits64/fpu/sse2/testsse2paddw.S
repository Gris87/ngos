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
# testSse2Paddw declaration:                                                    #
#     void testSse2Paddw(u16 *a, u16 *b, u16 *c);                               #
#                                                                               #
# RDI - a, address of 8 words array                                             #
# RSI - b, address of 8 words array                                             #
# RDX - c, address of result 8 words array                                      #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Paddw)                                                  # testSse2Paddw function
    movapd  (%rdi), %xmm0                                                       # Put 8 words located at RDI to XMM0
    movapd  (%rsi), %xmm1                                                       # Put 8 words located at RSI to XMM1
                                                                                #
    paddw   %xmm1, %xmm0                                                        # Add in parallel 8 words in XMM0 with 8 words in XMM1 and store results in XMM0
                                                                                #
    movapd  %xmm0, (%rdx)                                                       # Put 8 words from XMM1 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Paddw)                                                     # End of testSse2Paddw function
#endif
