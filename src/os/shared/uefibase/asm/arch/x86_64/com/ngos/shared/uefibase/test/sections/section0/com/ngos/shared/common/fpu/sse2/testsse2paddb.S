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
# testSse2Paddb declaration:                                                    #
#     void testSse2Paddb(u8 *a, u8 *b, u8 *c);                                  #
#                                                                               #
# RDI - a, address of 16 bytes array                                            #
# RSI - b, address of 16 bytes array                                            #
# RDX - c, address of result 16 bytes array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testSse2Paddb)                                                  # testSse2Paddb function
    movdqa  (%rdi), %xmm0                                                       # Put 16 bytes located at RDI to XMM0
    movdqa  (%rsi), %xmm1                                                       # Put 16 bytes located at RSI to XMM1
                                                                                #
    paddb   %xmm1, %xmm0                                                        # Add in parallel 16 bytes in XMM0 with 16 bytes in XMM1 and store results in XMM0
                                                                                #
    movdqa  %xmm0, (%rdx)                                                       # Put 16 bytes from XMM0 to location specified with RDX
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testSse2Paddb)                                                     # End of testSse2Paddb function
#endif
