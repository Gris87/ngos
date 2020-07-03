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
# testSse41Pminsd declaration:                                                  #
#     void testSse41Pminsd(i32 *a, i32 *b, i32 *c);                             #
#                                                                               #
# RDI - a, address of 4 doublewords array                                       #
# RSI - b, address of 4 doublewords array                                       #
# RDX - c, address of result 4 doublewords array                                #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse41Pminsd)                                                # testSse41Pminsd function
    movdqa  (%rdi), %xmm0                                                       # Put 4 doublewords located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 4 doublewords located at RSI to XMM1
                                                                                #
    pminsd  %xmm1, %xmm0                                                        # Get in parallel the minimum signed values in each pair of 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 4 doublewords from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse41Pminsd)                                                   # End of testSse41Pminsd function
#endif
