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
# testAvx512vlVsqrtps declaration:                                              #
#     void testAvx512vlVsqrtps(float *a, float *b);                             #
#                                                                               #
# RDI - a, address of 8 floats array                                            #
# RSI - b, address of result 8 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512vlVsqrtps)                                            # testAvx512vlVsqrtps function
    vmovaps     (%rdi), %ymm1                                                   # Put 8 floats located at RDI to YMM1
    movl        $0xFFFFFFFF, %eax                                               # Set all bits in EAX
    kmovw       %eax, %k1                                                       # Set all bits in K1 via EAX
                                                                                #
    vsqrtps     %ymm1, %ymm0 {%k1}                                              # Compute Square Roots in parallel for 8 floats in YMM1 and store results in YMM0
                                                                                #
    vmovaps     %ymm0, (%rsi)                                                   # Put 8 floats from YMM0 to location specified with RSI
    xorl        %esi, %esi                                                      # Put 0 to ESI
    kmovw       %esi, %k1                                                       # Reset K1
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512vlVsqrtps)                                               # End of testAvx512vlVsqrtps function
#endif
