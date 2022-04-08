#include "testavx512bw.h"

#include <com/ngos/bootloader_tools/cputest/main/cputest.h>
#include <com/ngos/bootloader_tools/cputest/main/cputestgui.h>
#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testAvx512BwProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAvx512Bw *test = (TestAvx512Bw *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512BW))
    {
        u16 a[32] __attribute__((aligned(64))) = { 1, 2, 3, 1, 9, 3, 1, 7, 6, 2, 4, 3, 2, 1, 8, 6, 2, 7, 3, 2, 9, 7, 1, 2, 9, 4, 6, 2, 3, 7, 6, 2 };
        u16 b[32] __attribute__((aligned(64))) = { 6, 2, 7, 3, 2, 9, 7, 1, 2, 9, 4, 6, 2, 3, 7, 6, 2, 1, 2, 3, 1, 9, 3, 1, 7, 6, 2, 4, 3, 2, 1, 8 };



        u64 startTime = AsmUtils::rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vpbroadcastb   %esi, %zmm0"    // vpbroadcastb   %esi, %zmm0     # Broadcast value from ESI to 64 bytes in ZMM0
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vpbroadcastw   %esi, %zmm0"    // vpbroadcastw   %esi, %zmm0     # Broadcast value from ESI to 32 words in ZMM0
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa64  %0, %%zmm1"                 "\n\t"    // vmovdqa64  0x40(%rsp), %zmm1       # Put 32 words located at %0 to ZMM1
                "vmovdqa64  %1, %%zmm2"                 "\n\t"    // vmovdqa64  0x80(%rsp), %zmm2       # Put 32 words located at %1 to ZMM2
                "vpsllvw    %%zmm2, %%zmm1, %%zmm0"               // vpsllvw    %zmm2, %zmm1, %zmm0     # Shift left 32 words in ZMM1 with shift counts in ZMM2 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa64  %0, %%zmm1"                 "\n\t"    // vmovdqa64  0x40(%rsp), %zmm1       # Put 32 words located at %0 to ZMM1
                "vmovdqa64  %1, %%zmm2"                 "\n\t"    // vmovdqa64  0x80(%rsp), %zmm2       # Put 32 words located at %1 to ZMM2
                "vpsrlvw    %%zmm2, %%zmm1, %%zmm0"               // vpsrlvw    %zmm2, %zmm1, %zmm0     # Shift right 32 words in ZMM1 with shift counts in ZMM2 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]
        }

        u64 endTime = AsmUtils::rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
    }
    else
    {
        UEFI_ASSERT_EXECUTION(test->setScore(0));
    }
}



TestAvx512Bw::TestAvx512Bw()
    : TestBase(TestType::AVX512BW, "Testing AVX512BW instructions", testAvx512BwProcedure)
{
    UEFI_LT((""));
}

TestAvx512Bw::~TestAvx512Bw()
{
    UEFI_LT((""));
}



TestAvx512Bw testAvx512BwInstance;
