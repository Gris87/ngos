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
# testSse3Addsubpd declaration:                                                 #
#     void testSse3Addsubpd(double *a, double *b, double *c);                   #
#                                                                               #
# RDI - a, address of 2 doubles array                                           #
# RSI - b, address of 2 doubles array                                           #
# RDX - c, address of result 2 doubles array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse3Addsubpd)                                               # testSse3Addsubpd function
    movapd      (%rdi), %xmm0                                                   # Put 2 doubles located at RDI to XMM0
    movapd      (%rsi), %xmm1                                                   # Put 2 doubles located at RSI to XMM1
                                                                                #
    addsubpd    %xmm1, %xmm0                                                    # Add 2nd double of XMM0 with 2nd double of XMM1 and subtract 1st double of XMM0 with 1st double of XMM1. The results stored in XMM0
                                                                                #
    movapd      %xmm0, (%rdx)                                                   # Put 2 doubles from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse3Addsubpd)                                                  # End of testSse3Addsubpd function
#endif
