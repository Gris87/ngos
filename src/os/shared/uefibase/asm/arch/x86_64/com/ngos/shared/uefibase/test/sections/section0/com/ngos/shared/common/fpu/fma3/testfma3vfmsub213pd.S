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
# testFma3Vfmsub213pd declaration:                                              #
#     void testFma3Vfmsub213pd(double *a, double *b, double *c, double *d);     #
#                                                                               #
# RDI - a, address of 4 doubles array                                           #
# RSI - b, address of 4 doubles array                                           #
# RDX - c, address of 4 doubles array                                           #
# RCX - d, address of result 4 doubles array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testFma3Vfmsub213pd)                                            # testFma3Vfmsub213pd function
    vmovapd         (%rdi), %ymm0                                               # Put 4 doubles located at RDI to YMM0
    vmovapd         (%rsi), %ymm1                                               # Put 4 doubles located at RSI to YMM1
    vmovapd         (%rdx), %ymm2                                               # Put 4 doubles located at RDX to YMM2
                                                                                #
    vfmsub213pd     %ymm2, %ymm1, %ymm0                                         # Multiply in parallel 4 doubles in YMM1 with 4 doubles in YMM0, subtract 4 doubles in YMM2 and store results in YMM0
                                                                                #
    vmovapd         %ymm0, (%rcx)                                               # Put 4 doubles from YMM0 to location specified with RCX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testFma3Vfmsub213pd)                                               # End of testFma3Vfmsub213pd function
#endif
