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
# testAvx512dqVpmullq declaration:                                              #
#     void testAvx512dqVpmullq(u64 *a, u64 *b, u64 *c);                         #
#                                                                               #
# RDI - a, address of 8 quadwords array                                         #
# RSI - b, address of 8 quadwords array                                         #
# RDX - c, address of result 8 quadwords array                                  #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512dqVpmullq)                                            # testAvx512dqVpmullq function
    vmovdqa64   (%rdi), %zmm1                                                   # Put 8 quadwords located at RDI to ZMM1
    vmovdqa64   (%rsi), %zmm2                                                   # Put 8 quadwords located at RSI to ZMM2
                                                                                #
    vpmullq     %zmm2, %zmm1, %zmm0                                             # Multiply 8 quadwords in ZMM1 with 8 quadwords in ZMM2 and store results in ZMM0
                                                                                #
    vmovdqa64   %zmm0, (%rdx)                                                   # Put 8 quadwords from ZMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512dqVpmullq)                                               # End of testAvx512dqVpmullq function
#endif
