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
# testAvxVaddps declaration:                                                    #
#     void testAvxVaddps(float *a, float *b, float *c);                         #
#                                                                               #
# RDI - a, address of 4 floats array                                            #
# RSI - b, address of 4 floats array                                            #
# RDX - c, address of result 4 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvxVaddps)                                                  # testAvxVaddps function
    vmovaps     (%rdi), %xmm2                                                   # Put 4 floats located at RDI to XMM2
    vmovaps     (%rsi), %xmm1                                                   # Put 4 floats located at RSI to XMM1
                                                                                #
    vaddps      %xmm2, %xmm1, %xmm0                                             # Add in parallel 4 floats in XMM2 with 4 floats in XMM1 and store results in XMM0
                                                                                #
    vmovaps     %xmm0, (%rdx)                                                   # Put 4 floats from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvxVaddps)                                                     # End of testAvxVaddps function
#endif
