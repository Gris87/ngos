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
# testAvx512bwVpsllvw declaration:                                              #
#     void testAvx512bwVpsllvw(u16 *a, u16 *b, u16 *c);                         #
#                                                                               #
# RDI - a, address of 32 words array                                            #
# RSI - b, address of 32 words array                                            #
# RDX - c, address of result 32 words array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512bwVpsllvw)                                            # testAvx512bwVpsllvw function
    vmovdqa64   (%rdi), %zmm1                                                   # Put 32 words located at RDI to ZMM1
    vmovdqa64   (%rsi), %zmm2                                                   # Put 32 words located at RSI to ZMM2
                                                                                #
    vpsllvw     %zmm2, %zmm1, %zmm0                                             # Shift left 32 words in ZMM1 with shift counts in ZMM2 and store results in ZMM0
                                                                                #
    vmovdqa64   %zmm0, (%rdx)                                                   # Put 32 words from ZMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512bwVpsllvw)                                               # End of testAvx512bwVpsllvw function
#endif
