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
# testSse3Hsubps declaration:                                                   #
#     void testSse3Hsubps(float *a, float *b, float *c);                        #
#                                                                               #
# RDI - a, address of 4 floats array                                            #
# RSI - b, address of 4 floats array                                            #
# RDX - c, address of result 4 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse3Hsubps)                                                 # testSse3Hsubps function
    movaps  (%rdi), %xmm0                                                       # Put 4 floats located at RDI to XMM0
    movaps  (%rsi), %xmm1                                                       # Put 4 floats located at RSI to XMM1
                                                                                #
    hsubps  %xmm1, %xmm0                                                        # Subtract floats from XMM0 with floats from XMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = A[2] - A[3]; C[2] = B[0] - B[1]; C[3] = B[2] - B[3]. The results stored in XMM0
                                                                                #
    movaps  %xmm0, (%rdx)                                                       # Put 4 floats from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse3Hsubps)                                                    # End of testSse3Hsubps function
#endif
