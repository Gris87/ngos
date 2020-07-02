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
# testSse2Psubb declaration:                                                    #
#     void testSse2Psubb(u8 *a, u8 *b, u8 *c);                                  #
#                                                                               #
# RDI - a, subress of 16 bytes array                                            #
# RSI - b, subress of 16 bytes array                                            #
# RDX - c, subress of result 16 bytes array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Psubb)                                                  # testSse2Psubb function
    movdqa  (%rdi), %xmm0                                                       # Put 16 bytes located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 16 bytes located at RSI to XMM1
                                                                                #
    psubb   %xmm1, %xmm0                                                        # Subtract in parallel 16 bytes in XMM0 with 16 bytes in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 16 bytes from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Psubb)                                                     # End of testSse2Psubb function
#endif
