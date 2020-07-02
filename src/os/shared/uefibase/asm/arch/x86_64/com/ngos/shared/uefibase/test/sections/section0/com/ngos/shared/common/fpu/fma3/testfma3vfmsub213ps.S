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
# testFma3Vfmsub213ps declaration:                                              #
#     void testFma3Vfmsub213ps(float *a, float *b, float *c, float *d);         #
#                                                                               #
# RDI - a, address of 8 floats array                                            #
# RSI - b, address of 8 floats array                                            #
# RDX - c, address of 8 floats array                                            #
# RCX - d, address of result 8 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testFma3Vfmsub213ps)                                            # testFma3Vfmsub213ps function
    vmovaps         (%rdi), %ymm0                                               # Put 8 floats located at RDI to YMM0
    vmovaps         (%rsi), %ymm1                                               # Put 8 floats located at RSI to YMM1
    vmovaps         (%rdx), %ymm2                                               # Put 8 floats located at RDX to YMM2
                                                                                #
    vfmsub213ps     %ymm2, %ymm1, %ymm0                                         # Multiply in parallel 8 floats in YMM1 with 8 floats in YMM0, subtract 8 floats in YMM2 and store results in YMM0
                                                                                #
    vmovaps         %ymm0, (%rcx)                                               # Put 8 floats from YMM0 to location specified with RCX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testFma3Vfmsub213ps)                                               # End of testFma3Vfmsub213ps function
#endif
