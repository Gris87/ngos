#include "testavx512cd.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/com/ngos/bootloader_tools/cputest/main/cputest.h"
#include "src/com/ngos/bootloader_tools/cputest/main/cputestgui.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testAvx512CdProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAvx512Cd *test = (TestAvx512Cd *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512CD))
    {
        u32 a[16] __attribute__((aligned(64))) = { 910, 154, 434, 397, 231, 151, 533, 697, 1109, 3234, 1227, 138, 704, 8485, 13636, 312019 };
        u64 b[8]  __attribute__((aligned(64))) = { 910, 154, 434, 397, 231, 151, 533, 697 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vpbroadcastmb2q    %k1, %zmm0"    // vpbroadcastmb2q   %k1, %zmm0  # Broadcast value from K1 to 8 quadwords in ZMM0
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vpbroadcastmw2d    %k1, %zmm0"    // vpbroadcastmw2d   %k1, %zmm0  # Broadcast value from K1 to 16 doublewords in ZMM0
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa32  %0, %%zmm1"         "\n\t"    // vmovdqa32  0x40(%rsp), %zmm1   # Put 16 doublewords located at %0 to ZMM1
                "vplzcntd   %%zmm1, %%zmm0"               // vplzcntd   %zmm1, %zmm0        # Count amount of leading zeros for 16 doublewords in ZMM1 and store results to ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa64  %0, %%zmm1"         "\n\t"    // vmovdqa64  0x40(%rsp), %zmm1   # Put 8 quadwords located at %0 to ZMM1
                "vplzcntq   %%zmm1, %%zmm0"               // vplzcntq   %zmm1, %zmm0        # Count amount of leading zeros for 8 quadwords in ZMM1 and store results to ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]
        }

        u64 endTime = rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
    }
    else
    {
        UEFI_ASSERT_EXECUTION(test->setScore(0));
    }
}



TestAvx512Cd::TestAvx512Cd()
    : TestBase(TestType::AVX512CD, "Testing AVX512CD instructions", testAvx512CdProcedure)
{
    UEFI_LT((""));
}

TestAvx512Cd::~TestAvx512Cd()
{
    UEFI_LT((""));
}



TestAvx512Cd testAvx512CdInstance;
