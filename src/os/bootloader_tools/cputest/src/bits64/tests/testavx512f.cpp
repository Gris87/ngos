#include "testavx512f.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"
#include "src/bits64/main/cputestgui.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testAvx512FProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAvx512F *test = (TestAvx512F *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512F))
    {
        float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
        float b[16] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1, 0.6, 0.9, 0.4, 0.3, 0.7, 0.2, 0.8, 0.7 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"                 "\n\t"    // vmovaps    0x20(%rsp), %zmm1       # Put 16 floats located at %0 to ZMM1
                "vmovaps    %1, %%zmm2"                 "\n\t"    // vmovaps    0x40(%rsp), %zmm2       # Put 16 floats located at %1 to ZMM2
                "vaddps     %%zmm2, %%zmm1, %%zmm0"               // vaddps     %zmm2, %zmm1, %zmm0     # Add in parallel 16 floats in ZMM2 with 16 floats in ZMM1 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"                 "\n\t"    // vmovaps    0x20(%rsp), %zmm1       # Put 16 floats located at %0 to ZMM1
                "vmovaps    %1, %%zmm2"                 "\n\t"    // vmovaps    0x40(%rsp), %zmm2       # Put 16 floats located at %1 to ZMM2
                "vdivps     %%zmm2, %%zmm1, %%zmm0"               // vdivps     %zmm2, %zmm1, %zmm0     # Divide in parallel 16 floats in ZMM2 with 16 floats in ZMM1 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"                 "\n\t"    // vmovaps    0x20(%rsp), %zmm1       # Put 16 floats located at %0 to ZMM1
                "vmovaps    %1, %%zmm2"                 "\n\t"    // vmovaps    0x40(%rsp), %zmm2       # Put 16 floats located at %1 to ZMM2
                "vmaxps     %%zmm2, %%zmm1, %%zmm0"               // vmaxps     %zmm2, %zmm1, %zmm0     # Get in parallel the maximum values in each pair of 16 floats in ZMM2 with 16 floats in ZMM1 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"                 "\n\t"    // vmovaps    0x20(%rsp), %zmm1       # Put 16 floats located at %0 to ZMM1
                "vmovaps    %1, %%zmm2"                 "\n\t"    // vmovaps    0x40(%rsp), %zmm2       # Put 16 floats located at %1 to ZMM2
                "vminps     %%zmm2, %%zmm1, %%zmm0"               // vminps     %zmm2, %zmm1, %zmm0     # Get in parallel the minimum values in each pair of 16 floats in ZMM2 with 16 floats in ZMM1 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"                 "\n\t"    // vmovaps    0x20(%rsp), %zmm1       # Put 16 floats located at %0 to ZMM1
                "vmovaps    %1, %%zmm2"                 "\n\t"    // vmovaps    0x40(%rsp), %zmm2       # Put 16 floats located at %1 to ZMM2
                "vmulps     %%zmm2, %%zmm1, %%zmm0"               // vmulps     %zmm2, %zmm1, %zmm0     # Multiply in parallel 16 floats in ZMM2 with 16 floats in ZMM1 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"         "\n\t"    // vmovaps    0x20(%rsp), %zmm1   # Put 16 floats located at %0 to ZMM1
                "vrcp14ps   %%zmm1, %%zmm0"               // vrcp14ps   %zmm1, %zmm0        # Compute Reciprocal (1/A) in parallel for 16 floats in ZMM1 and store results in ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps        %0, %%zmm1"         "\n\t"    // vmovaps        0x20(%rsp), %zmm1   # Put 16 floats located at %0 to ZMM1
                "vrsqrt14ps     %%zmm1, %%zmm0"               // vrsqrt14ps     %zmm1, %zmm0        # Compute Reciprocal of Square Roots (1/sqrt(A)) in parallel for 16 floats in ZMM1 and store results in ZMM0
                    :                                         // Output parameters
                    :                                         // Input parameters
                        "m" (a)                               // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"         "\n\t"    // vmovaps    0x20(%rsp), %zmm1   # Put 16 floats located at %0 to ZMM1
                "vsqrtps    %%zmm1, %%zmm0"               // vsqrtps    %zmm1, %zmm0        # Compute Square Roots in parallel for 16 floats in ZMM1 and store results in ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%zmm1"                 "\n\t"    // vmovaps    0x20(%rsp), %zmm1       # Put 16 floats located at %0 to ZMM1
                "vmovaps    %1, %%zmm2"                 "\n\t"    // vmovaps    0x40(%rsp), %zmm2       # Put 16 floats located at %1 to ZMM2
                "vsubps     %%zmm2, %%zmm1, %%zmm0"               // vsubps     %zmm2, %zmm1, %zmm0     # Subtract in parallel 16 floats in ZMM2 with 16 floats in ZMM1 and store results in ZMM0
                    :                                             // Output parameters
                    :                                             // Input parameters
                        "m" (a),                                  // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                                   // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]
        }

        u64 endTime = rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
    }
    else
    {
        UEFI_ASSERT_EXECUTION(test->setScore(0));
    }
}



TestAvx512F::TestAvx512F()
    : TestBase(TestType::AVX512F, "Testing AVX512F instructions", testAvx512FProcedure)
{
    UEFI_LT((""));
}

TestAvx512F::~TestAvx512F()
{
    UEFI_LT((""));
}



TestAvx512F testAvx512FInstance;
