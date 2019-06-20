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
# testAvx512bwVpsrlvw declaration:                                              #
#     void testAvx512bwVpsrlvw(u16 *a, u16 *b, u16 *c);                         #
#                                                                               #
# RDI - a, address of 32 words array                                            #
# RSI - b, address of 32 words array                                            #
# RDX - c, address of result 32 words array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512bwVpsrlvw)                                            # testAvx512bwVpsrlvw function
    vmovdqa64   (%rdi), %zmm1                                                   # Put 32 words located at RDI to ZMM1
    vmovdqa64   (%rsi), %zmm2                                                   # Put 32 words located at RSI to ZMM2
                                                                                #
    vpsrlvw     %zmm2, %zmm1, %zmm0                                             # Shift right 32 words in ZMM1 with shift counts in ZMM2 and store results in ZMM0
                                                                                #
    vmovdqa64   %zmm0, (%rdx)                                                   # Put 32 words from ZMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512bwVpsrlvw)                                               # End of testAvx512bwVpsrlvw function
#endif
