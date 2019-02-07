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
# testSse2Paddd declaration:                                                    #
#     void testSse2Paddd(u32 *a, u32 *b, u32 *c);                               #
#                                                                               #
# RDI - a, address of 4 doublewords array                                       #
# RSI - b, address of 4 doublewords array                                       #
# RDX - c, address of result 4 doublewords array                                #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Paddd)                                                  # testSse2Paddd function
    movapd  (%rdi), %xmm0                                                       # Put 4 doublewords located at RDI to XMM0
    movapd  (%rsi), %xmm1                                                       # Put 4 doublewords located at RSI to XMM1
                                                                                #
    paddd   %xmm1, %xmm0                                                        # Add in parallel 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                                                                                #
    movapd  %xmm0, (%rdx)                                                       # Put 4 doublewords from XMM1 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Paddd)                                                     # End of testSse2Paddd function
#endif
