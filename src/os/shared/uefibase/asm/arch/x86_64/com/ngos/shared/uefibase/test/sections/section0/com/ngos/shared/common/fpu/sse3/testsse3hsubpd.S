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
# testSse3Hsubpd declaration:                                                   #
#     void testSse3Hsubpd(double *a, double *b, double *c);                     #
#                                                                               #
# RDI - a, address of 2 doubles array                                           #
# RSI - b, address of 2 doubles array                                           #
# RDX - c, address of result 2 doubles array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse3Hsubpd)                                                 # testSse3Hsubpd function
    movapd  (%rdi), %xmm0                                                       # Put 2 doubles located at RDI to XMM0
    movapd  (%rsi), %xmm1                                                       # Put 2 doubles located at RSI to XMM1
                                                                                #
    hsubpd  %xmm1, %xmm0                                                        # Subtract doubles from XMM0 with doubles from XMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = B[0] - B[1]. The results stored in XMM0
                                                                                #
    movapd  %xmm0, (%rdx)                                                       # Put 2 doubles from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse3Hsubpd)                                                    # End of testSse3Hsubpd function
#endif
