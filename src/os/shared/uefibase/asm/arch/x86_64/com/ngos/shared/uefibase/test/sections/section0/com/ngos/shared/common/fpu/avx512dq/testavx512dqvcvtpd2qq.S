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
# testAvx512dqVcvtpd2qq declaration:                                            #
#     void testAvx512dqVcvtpd2qq(u64 *a, double *b);                            #
#                                                                               #
# RDI - a, address of 8 doubles array                                           #
# RDX - b, address of result 8 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512dqVcvtpd2qq)                                          # testAvx512dqVcvtpd2qq function
    vmovapd     (%rdi), %zmm1                                                   # Put 8 doubles located at RDI to ZMM1
                                                                                #
    vcvtpd2qq   %zmm1, %zmm0                                                    # Convert 8 doubles in ZMM1 to 8 quadwords in ZMM0
                                                                                #
    vmovdqa64   %zmm0, (%rsi)                                                   # Put 8 quadwords from ZMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512dqVcvtpd2qq)                                             # End of testAvx512dqVcvtpd2qq function
#endif
