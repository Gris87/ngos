#include "testavx2.h"

#include <common/src/com/ngos/shared/common/asm/instructions.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <common/src/com/ngos/shared/common/fpu/fpu.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/com/ngos/bootloader_tools/cputest/main/cputest.h"
#include "src/com/ngos/bootloader_tools/cputest/main/cputestgui.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     400



CPP_NO_OPTIMIZATION
void UEFI_API testAvx2Procedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAvx2 *test = (TestAvx2 *)buffer;

    if (CPU::hasFlag(X86Feature::AVX2))
    {
        u16 a[16] __attribute__((aligned(32))) = { 10, 54, 34, 97, 31, 51, 33, 97, 19, 34, 27, 18, 74, 85, 36, 39 };
        u16 b[16] __attribute__((aligned(32))) = { 91, 37, 21, 49, 37, 21, 37, 44, 67, 39, 26, 17, 34, 24, 86, 26 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa    %0, %%ymm1"                 "\n\t"    // vmovdqa    0x20(%rsp), %ymm1       # Put 8 doublewords located at %0 to YMM1
                "vmovdqa    %1, %%ymm2"                 "\n\t"    // vmovdqa    0x40(%rsp), %ymm2       # Put 8 doublewords located at %1 to YMM2
                "vphaddd    %%ymm2, %%ymm1, %%ymm0"               // vphaddd    %ymm2, %ymm1, %ymm0     # Add doublewords from YMM2 with doublewords from YMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; ... ; C[7] = B[6] + B[7]. The results stored in YMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa    %0, %%ymm1"                 "\n\t"    // vmovdqa    0x20(%rsp), %ymm1       # Put 16 words located at %0 to YMM1
                "vmovdqa    %1, %%ymm2"                 "\n\t"    // vmovdqa    0x40(%rsp), %ymm2       # Put 16 words located at %1 to YMM2
                "vphaddw    %%ymm2, %%ymm1, %%ymm0"               // vphaddw    %ymm2, %ymm1, %ymm0     # Add words from YMM2 with words from YMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; ... ; C[15] = B[14] + B[15]. The results stored in YMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa    %0, %%ymm1"                 "\n\t"    // vmovdqa    0x20(%rsp), %ymm1       # Put 8 doublewords located at %0 to YMM1
                "vmovdqa    %1, %%ymm2"                 "\n\t"    // vmovdqa    0x40(%rsp), %ymm2       # Put 8 doublewords located at %1 to YMM2
                "vphsubd    %%ymm2, %%ymm1, %%ymm0"               // vphsubd    %ymm2, %ymm1, %ymm0     # Subtract doublewords from YMM2 with doublewords from YMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = A[2] - A[3]; ... ; C[7] = B[6] - B[7]. The results stored in YMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa    %0, %%ymm1"                 "\n\t"    // vmovdqa    0x20(%rsp), %ymm1       # Put 16 words located at %0 to YMM1
                "vmovdqa    %1, %%ymm2"                 "\n\t"    // vmovdqa    0x40(%rsp), %ymm2       # Put 16 words located at %1 to YMM2
                "vphsubw    %%ymm2, %%ymm1, %%ymm0"               // vphsubw    %ymm2, %ymm1, %ymm0     # Subtract words from YMM2 with words from YMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = A[2] - A[3]; ... ; C[15] = B[14] - B[15]. The results stored in YMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
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



TestAvx2::TestAvx2()
    : TestBase(TestType::AVX2, "Testing AVX2 instructions", testAvx2Procedure)
{
    UEFI_LT((""));
}

TestAvx2::~TestAvx2()
{
    UEFI_LT((""));
}



TestAvx2 testAvx2Instance;
