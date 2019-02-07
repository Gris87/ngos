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
# testSse2Rsqrtpd declaration:                                                  #
#     void testSse2Rsqrtpd(double *a, double *b);                               #
#                                                                               #
# RDI - a, address of 2 doubles array                                           #
# RSI - b, address of result 2 doubles array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Rsqrtpd)                                                # testSse2Rsqrtpd function
    movapd  (%rdi), %xmm0                                                       # Put 2 doubles located at RDI to XMM0
                                                                                #
    rsqrtpd  %xmm0, %xmm0                                                       # Compute Reciprocal of Square Roots (1/sqrt(A)) in parallel for 2 doubles in XMM0 and store results in XMM0
                                                                                #
    movapd  %xmm0, (%rdx)                                                       # Put 2 doubles from XMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Rsqrtpd)                                                   # End of testSse2Rsqrtpd function
#endif
