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
# testSse2Sqrtpd declaration:                                                   #
#     void testSse2Sqrtpd(double *a, double *b);                                #
#                                                                               #
# RDI - a, address of 2 doubles array                                           #
# RSI - b, address of result 2 doubles array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Sqrtpd)                                                 # testSse2Sqrtpd function
    movapd  (%rdi), %xmm0                                                       # Put 2 doubles located at RDI to XMM0
                                                                                #
    sqrtpd  %xmm0, %xmm0                                                        # Compute Square Roots in parallel for 2 doubles in XMM0 and store results in XMM0
                                                                                #
    movapd  %xmm0, (%rsi)                                                       # Put 2 doubles from XMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Sqrtpd)                                                    # End of testSse2Sqrtpd function
#endif
