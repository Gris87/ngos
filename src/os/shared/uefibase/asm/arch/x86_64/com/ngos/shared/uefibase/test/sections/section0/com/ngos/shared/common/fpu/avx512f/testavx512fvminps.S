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
# testAvx512fVminps declaration:                                                #
#     void testAvx512fVminps(float *a, float *b, float *c);                     #
#                                                                               #
# RDI - a, address of 16 floats array                                           #
# RSI - b, address of 16 floats array                                           #
# RDX - c, address of result 16 floats array                                    #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512fVminps)                                              # testAvx512fVminps function
    vmovaps     (%rdi), %zmm1                                                   # Put 16 floats located at RDI to ZMM1
    vmovaps     (%rsi), %zmm2                                                   # Put 16 floats located at RSI to ZMM2
                                                                                #
    vminps      %zmm2, %zmm1, %zmm0                                             # Get in parallel the minimum values in each pair of 16 floats in ZMM2 with 16 floats in ZMM1 and store results in ZMM0
                                                                                #
    vmovaps     %zmm0, (%rdx)                                                   # Put 16 floats from ZMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512fVminps)                                                 # End of testAvx512fVminps function
#endif
