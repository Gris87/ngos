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
# testAvx512fVsqrtps declaration:                                               #
#     void testAvx512fVsqrtps(float *a, float *b);                              #
#                                                                               #
# RDI - a, address of 16 floats array                                           #
# RSI - b, address of result 16 floats array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512fVsqrtps)                                             # testAvx512fVsqrtps function
    vmovaps     (%rdi), %zmm1                                                   # Put 16 floats located at RDI to ZMM1
                                                                                #
    vsqrtps     %zmm1, %zmm0                                                    # Compute Square Roots in parallel for 16 floats in ZMM1 and store results in ZMM0
                                                                                #
    vmovaps     %zmm0, (%rsi)                                                   # Put 16 floats from ZMM0 to location specified with RSI
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512fVsqrtps)                                                # End of testAvx512fVsqrtps function
#endif
