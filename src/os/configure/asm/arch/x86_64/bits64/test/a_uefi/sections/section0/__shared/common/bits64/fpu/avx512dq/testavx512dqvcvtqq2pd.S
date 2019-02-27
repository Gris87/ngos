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
# testAvx512dqVcvtqq2pd declaration:                                            #
#     void testAvx512dqVcvtqq2pd(u64 *a, double *b);                            #
#                                                                               #
# RDI - a, address of 8 quadwords array                                         #
# RDX - b, address of result 8 doubles array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512dqVcvtqq2pd)                                          # testAvx512dqVcvtqq2pd function
    vmovdqa64   (%rdi), %zmm1                                                   # Put 8 quadwords located at RDI to ZMM1
                                                                                #
    vcvtqq2pd   %zmm1, %zmm0                                                    # Convert 8 quadwords in ZMM1 to 8 doubles in ZMM0
                                                                                #
    vmovapd     %zmm0, (%rsi)                                                   # Put 8 doubles from ZMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512dqVcvtqq2pd)                                             # End of testAvx512dqVcvtqq2pd function
#endif
