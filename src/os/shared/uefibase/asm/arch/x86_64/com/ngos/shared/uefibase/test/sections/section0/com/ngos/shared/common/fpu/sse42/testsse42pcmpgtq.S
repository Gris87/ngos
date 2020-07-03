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
# testSse42Pcmpgtq declaration:                                                 #
#     void testSse42Pcmpgtq(i64 *a, i64 *b, i64 *c);                            #
#                                                                               #
# RDI - a, address of 2 quadwords array                                         #
# RSI - b, address of 2 quadwords array                                         #
# RDX - c, address of result 2 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse42Pcmpgtq)                                               # testSse42Pcmpgtq function
    movdqa      (%rdi), %xmm0                                                   # Put 2 quadwords located at RDI to XMM0
    movdqa      (%rsi), %xmm1                                                   # Put 2 quadwords located at RSI to XMM1
                                                                                #
    pcmpgtq     %xmm1, %xmm0                                                    # Compare signed quadwords in XMM0 with quadwords in XMM1. If quadword in XMM0 is greater then returns -1, otherwise 0. The results stored in XMM0
                                                                                #
    movdqa      %xmm0, (%rdx)                                                   # Put 2 quadwords from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse42Pcmpgtq)                                                  # End of testSse42Pcmpgtq function
#endif
