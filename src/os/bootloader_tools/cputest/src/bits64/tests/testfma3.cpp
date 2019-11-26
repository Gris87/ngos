#include "testfma3.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     250



CPP_NO_OPTIMIZATION
void UEFI_API testFma3Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestFma3 *test = (TestFma3 *)buffer;

    if (CPU::hasFlag(X86Feature::FMA))
    {
        double a[4] __attribute__((aligned(32))) = { 0.1, 0.9, 0.7, 0.5 };
        double b[4] __attribute__((aligned(32))) = { 0.8, 0.5, 0.3, 0.9 };
        double c[4] __attribute__((aligned(32))) = { 0.9, 0.7, 0.6, 0.8 };
        float  d[8] __attribute__((aligned(32))) = { 0.1, 0.9, 0.7, 0.5, 0.7, 0.3, 0.4, 0.9 };
        float  e[8] __attribute__((aligned(32))) = { 0.8, 0.5, 0.3, 0.9, 0.9, 0.7, 0.5, 0.7 };
        float  f[8] __attribute__((aligned(32))) = { 0.9, 0.7, 0.6, 0.8, 0.9, 0.6, 0.7, 0.8 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovapd        %0, %%ymm0"                 "\n\t"    // vmovapd        0x20(%rsp), %ymm0       # Put 4 doubles located at %0 to YMM0
                "vmovapd        %1, %%ymm1"                 "\n\t"    // vmovapd        0x40(%rsp), %ymm1       # Put 4 doubles located at %1 to YMM1
                "vmovapd        %2, %%ymm2"                 "\n\t"    // vmovapd        0x60(%rsp), %ymm2       # Put 4 doubles located at %2 to YMM2
                "vfmadd213pd    %%ymm2, %%ymm1, %%ymm0"               // vfmadd213pd    %ymm2, %ymm1, %ymm0     # Multiply in parallel 4 doubles in YMM1 with 4 doubles in YMM0, add 4 doubles in YMM2 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory
                        "m" (b),                                      // 'm' - use memory
                        "m" (c)                                       // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps        %0, %%ymm0"                 "\n\t"    // vmovaps        0x20(%rsp), %ymm0       # Put 8 floats located at %0 to YMM0
                "vmovaps        %1, %%ymm1"                 "\n\t"    // vmovaps        0x40(%rsp), %ymm1       # Put 8 floats located at %1 to YMM1
                "vmovaps        %2, %%ymm2"                 "\n\t"    // vmovaps        0x60(%rsp), %ymm2       # Put 8 floats located at %2 to YMM2
                "vfmadd213ps    %%ymm2, %%ymm1, %%ymm0"               // vfmadd213ps    %ymm2, %ymm1, %ymm0     # Multiply in parallel 8 floats in YMM1 with 8 floats in YMM0, add 8 floats in YMM2 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (d),                                      // 'm' - use memory
                        "m" (e),                                      // 'm' - use memory
                        "m" (f)                                       // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovapd        %0, %%ymm0"                 "\n\t"    // vmovapd        0x20(%rsp), %ymm0       # Put 4 doubles located at %0 to YMM0
                "vmovapd        %1, %%ymm1"                 "\n\t"    // vmovapd        0x40(%rsp), %ymm1       # Put 4 doubles located at %1 to YMM1
                "vmovapd        %2, %%ymm2"                 "\n\t"    // vmovapd        0x60(%rsp), %ymm2       # Put 4 doubles located at %2 to YMM2
                "vfmsub213pd    %%ymm2, %%ymm1, %%ymm0"               // vfmsub213pd    %ymm2, %ymm1, %ymm0     # Multiply in parallel 4 doubles in YMM1 with 4 doubles in YMM0, subtract 4 doubles in YMM2 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (a),                                      // 'm' - use memory
                        "m" (b),                                      // 'm' - use memory
                        "m" (c)                                       // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps        %0, %%ymm0"                 "\n\t"    // vmovaps        0x20(%rsp), %ymm0       # Put 8 floats located at %0 to YMM0
                "vmovaps        %1, %%ymm1"                 "\n\t"    // vmovaps        0x40(%rsp), %ymm1       # Put 8 floats located at %1 to YMM1
                "vmovaps        %2, %%ymm2"                 "\n\t"    // vmovaps        0x60(%rsp), %ymm2       # Put 8 floats located at %2 to YMM2
                "vfmsub213ps    %%ymm2, %%ymm1, %%ymm0"               // vfmsub213ps    %ymm2, %ymm1, %ymm0     # Multiply in parallel 8 floats in YMM1 with 8 floats in YMM0, subtract 8 floats in YMM2 and store results in YMM0
                    :                                                 // Output parameters
                    :                                                 // Input parameters
                        "m" (d),                                      // 'm' - use memory
                        "m" (e),                                      // 'm' - use memory
                        "m" (f)                                       // 'm' - use memory
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



TestFma3::TestFma3()
    : TestBase(TestType::FMA3, "Testing FMA3 instructions", testFma3Procedure)
{
    UEFI_LT((""));
}

TestFma3::~TestFma3()
{
    UEFI_LT((""));
}



TestFma3 testFma3Instance;
