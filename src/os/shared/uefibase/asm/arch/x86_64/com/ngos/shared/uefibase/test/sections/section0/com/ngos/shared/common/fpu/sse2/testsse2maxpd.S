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
# testSse2Maxpd declaration:                                                    #
#     void testSse2Maxpd(double *a, double *b, double *c);                      #
#                                                                               #
# RDI - a, address of 2 doubles array                                           #
# RSI - b, address of 2 doubles array                                           #
# RDX - c, address of result 2 doubles array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Maxpd)                                                  # testSse2Maxpd function
    movapd  (%rdi), %xmm0                                                       # Put 2 doubles located at RDI to XMM0
    movapd  (%rsi), %xmm1                                                       # Put 2 doubles located at RSI to XMM1
                                                                                #
    maxpd   %xmm1, %xmm0                                                        # Get in parallel the maximum values in each pair of 2 doubles in XMM0 with 2 doubles in XMM1 and store results in XMM0
                                                                                #
    movapd  %xmm0, (%rdx)                                                       # Put 2 doubles from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Maxpd)                                                     # End of testSse2Maxpd function
#endif
