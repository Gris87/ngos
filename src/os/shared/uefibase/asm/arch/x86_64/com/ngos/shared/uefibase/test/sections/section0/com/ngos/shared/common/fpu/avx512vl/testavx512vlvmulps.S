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
# testAvx512vlVmulps declaration:                                               #
#     void testAvx512vlVmulps(float *a, float *b, float *c);                    #
#                                                                               #
# RDI - a, address of 8 floats array                                            #
# RSI - b, address of 8 floats array                                            #
# RDX - c, address of result 8 floats array                                     #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(testAvx512vlVmulps)                                             # testAvx512vlVmulps function
    vmovaps     (%rdi), %ymm1                                                   # Put 8 floats located at RDI to YMM1
    vmovaps     (%rsi), %ymm2                                                   # Put 8 floats located at RSI to YMM2
    movl        $0xFFFFFFFF, %eax                                               # Set all bits in EAX
    kmovw       %eax, %k1                                                       # Set all bits in K1 via EAX
                                                                                #
    vmulps      %ymm2, %ymm1, %ymm0 {%k1}                                       # Multiply in parallel 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                                                                                #
    vmovaps     %ymm0, (%rdx)                                                   # Put 8 floats from YMM0 to location specified with RDX
    xorl        %esi, %esi                                                      # Put 0 to ESI
    kmovw       %esi, %k1                                                       # Reset K1
                                                                                #
    retq                                                                        # Return from the function
END_FUNCTION(testAvx512vlVmulps)                                                # End of testAvx512vlVmulps function
#endif
