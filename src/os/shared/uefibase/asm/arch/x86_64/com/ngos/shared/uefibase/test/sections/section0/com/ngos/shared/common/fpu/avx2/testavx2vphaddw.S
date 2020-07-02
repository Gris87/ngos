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
# testAvx2Vphaddw declaration:                                                  #
#     void testAvx2Vphaddw(u16 *a, u16 *b, u16 *c);                             #
#                                                                               #
# RDI - a, address of 16 words array                                            #
# RSI - b, address of 16 words array                                            #
# RDX - c, address of result 16 words array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx2Vphaddw)                                                # testAvx2Vphaddw function
    vmovdqa     (%rdi), %ymm1                                                   # Put 16 words located at RDI to YMM1
    vmovdqa     (%rsi), %ymm2                                                   # Put 16 words located at RSI to YMM2
                                                                                #
    vphaddw     %ymm2, %ymm1, %ymm0                                             # Add words from YMM2 with words from YMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; ... ; C[15] = B[14] + B[15]. The results stored in YMM0
                                                                                #
    vmovdqa     %ymm0, (%rdx)                                                   # Put 16 words from YMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx2Vphaddw)                                                   # End of testAvx2Vphaddw function
#endif
