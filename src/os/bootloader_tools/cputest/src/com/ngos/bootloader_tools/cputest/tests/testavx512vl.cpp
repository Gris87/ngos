#include "testavx512vl.h"

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
void UEFI_API testAvx512VlProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAvx512Vl *test = (TestAvx512Vl *)buffer;

    if (CPU::hasFeature(X86Feature::AVX512VL))
    {
        float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
        float b[8] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1 };



        u64 startTime = AsmUtils::rdtsc();

        for (good_I64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"                     "\n\t"    // vmovaps    0x20(%rsp), %ymm1           # Put 8 floats located at %0 to YMM1
                "vmovaps    %1, %%ymm2"                     "\n\t"    // vmovaps    0x40(%rsp), %ymm2           # Put 8 floats located at %1 to YMM2
                "vaddps     %%ymm2, %%ymm1, %%ymm0 %{%%k1}"           // vaddps     %ymm2, %ymm1, %ymm0 {%k1}   # Add in parallel 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                       // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"                     "\n\t"    // vmovaps    0x20(%rsp), %ymm1           # Put 8 floats located at %0 to YMM1
                "vmovaps    %1, %%ymm2"                     "\n\t"    // vmovaps    0x40(%rsp), %ymm2           # Put 8 floats located at %1 to YMM2
                "vdivps     %%ymm2, %%ymm1, %%ymm0 %{%%k1}"           // vdivps     %ymm2, %ymm1, %ymm0 {%k1}   # Divide in parallel 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                       // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"                     "\n\t"    // vmovaps    0x20(%rsp), %ymm1           # Put 8 floats located at %0 to YMM1
                "vmovaps    %1, %%ymm2"                     "\n\t"    // vmovaps    0x40(%rsp), %ymm2           # Put 8 floats located at %1 to YMM2
                "vmaxps     %%ymm2, %%ymm1, %%ymm0 %{%%k1}"           // vmaxps     %ymm2, %ymm1, %ymm0 {%k1}   # Get in parallel the maximum values in each pair of 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                       // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"                     "\n\t"    // vmovaps    0x20(%rsp), %ymm1           # Put 8 floats located at %0 to YMM1
                "vmovaps    %1, %%ymm2"                     "\n\t"    // vmovaps    0x40(%rsp), %ymm2           # Put 8 floats located at %1 to YMM2
                "vminps     %%ymm2, %%ymm1, %%ymm0 %{%%k1}"           // vminps     %ymm2, %ymm1, %ymm0 {%k1}   # Get in parallel the minimum values in each pair of 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                       // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"                     "\n\t"    // vmovaps    0x20(%rsp), %ymm1           # Put 8 floats located at %0 to YMM1
                "vmovaps    %1, %%ymm2"                     "\n\t"    // vmovaps    0x40(%rsp), %ymm2           # Put 8 floats located at %1 to YMM2
                "vmulps     %%ymm2, %%ymm1, %%ymm0 %{%%k1}"           // vmulps     %ymm2, %ymm1, %ymm0 {%k1}   # Multiply in parallel 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                       // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"             "\n\t"    // vmovaps    0x20(%rsp), %ymm1   # Put 8 floats located at %0 to YMM1
                "vrcp14ps   %%ymm1, %%ymm0 %{%%k1}"           // vrcp14ps   %ymm1, %ymm0 {%k1}  # Compute Reciprocal (1/A) in parallel for 8 floats in YMM1 and store results in YMM0
                    :                                         // Output parameters
                    :                                         // Input parameters
                        "m" (a)                               // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps        %0, %%ymm1"             "\n\t"    // vmovaps        0x20(%rsp), %ymm1   # Put 8 floats located at %0 to YMM1
                "vrsqrt14ps     %%ymm1, %%ymm0 %{%%k1}"           // vrsqrt14ps     %ymm1, %ymm0 {%k1}  # Compute Reciprocal of Square Roots (1/sqrt(A)) in parallel for 8 floats in YMM1 and store results in YMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"             "\n\t"    // vmovaps    0x20(%rsp), %ymm1   # Put 8 floats located at %0 to YMM1
                "vsqrtps    %%ymm1, %%ymm0 %{%%k1}"           // vsqrtps    %ymm1, %ymm0 {%k1}  # Compute Square Roots in parallel for 8 floats in YMM1 and store results in YMM0
                    :                                         // Output parameters
                    :                                         // Input parameters
                        "m" (a)                               // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"                     "\n\t"    // vmovaps    0x20(%rsp), %ymm1           # Put 8 floats located at %0 to YMM1
                "vmovaps    %1, %%ymm2"                     "\n\t"    // vmovaps    0x40(%rsp), %ymm2           # Put 8 floats located at %1 to YMM2
                "vsubps     %%ymm2, %%ymm1, %%ymm0 %{%%k1}"           // vsubps     %ymm2, %ymm1, %ymm0 {%k1}   # Subtract in parallel 8 floats in YMM2 with 8 floats in YMM1 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                       // 'm' - use memory // Ignore CppSingleCharVerifier
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



TestAvx512Vl::TestAvx512Vl()
    : TestBase(TestType::AVX512VL, "Testing AVX512VL instructions", testAvx512VlProcedure)
{
    UEFI_LT((""));
}

TestAvx512Vl::~TestAvx512Vl()
{
    UEFI_LT((""));
}



TestAvx512Vl testAvx512VlInstance;
