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
# testAvx2Vphsubd declaration:                                                  #
#     void testAvx2Vphsubd(u32 *a, u32 *b, u32 *c);                             #
#                                                                               #
# RDI - a, address of 8 doublewords array                                       #
# RSI - b, address of 8 doublewords array                                       #
# RDX - c, address of result 8 doublewords array                                #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx2Vphsubd)                                                # testAvx2Vphsubd function
    vmovdqa     (%rdi), %ymm1                                                   # Put 8 doublewords located at RDI to YMM1
    vmovdqa     (%rsi), %ymm2                                                   # Put 8 doublewords located at RSI to YMM2
                                                                                #
    vphsubd     %ymm2, %ymm1, %ymm0                                             # Subtract doublewords from YMM2 with doublewords from YMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = A[2] - A[3]; ... ; C[7] = B[6] - B[7]. The results stored in YMM0
                                                                                #
    vmovdqa     %ymm0, (%rdx)                                                   # Put 8 doublewords from YMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx2Vphsubd)                                                   # End of testAvx2Vphsubd function
#endif
