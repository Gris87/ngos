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
# testSse2Psubd declaration:                                                    #
#     void testSse2Psubd(u32 *a, u32 *b, u32 *c);                               #
#                                                                               #
# RDI - a, subress of 4 doublewords array                                       #
# RSI - b, subress of 4 doublewords array                                       #
# RDX - c, subress of result 4 doublewords array                                #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Psubd)                                                  # testSse2Psubd function
    movdqa  (%rdi), %xmm0                                                       # Put 4 doublewords located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 4 doublewords located at RSI to XMM1
                                                                                #
    psubd   %xmm1, %xmm0                                                        # Subtract in parallel 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 4 doublewords from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Psubd)                                                     # End of testSse2Psubd function
#endif
