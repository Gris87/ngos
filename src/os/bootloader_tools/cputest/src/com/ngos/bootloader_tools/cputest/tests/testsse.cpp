#include "testsse.h"

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
#define SCORE_PER_SECOND     500



CPP_NO_OPTIMIZATION
void UEFI_API testSseProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSse *test = (TestSse *)buffer;

    if (CPU::hasFlag(X86Feature::XMM))
    {
        float a[4] = { 0.5, 0.4, 0.2, 0.1 };
        float b[4] = { 0.8, 0.3, 0.8, 0.6 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x10(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "addps      %%xmm1, %%xmm0"               // addps      %xmm1, %xmm0        # Add in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x10(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "divps      %%xmm1, %%xmm0"               // divps      %xmm1, %xmm0        # Divide in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x10(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "maxps      %%xmm1, %%xmm0"               // maxps      %xmm1, %xmm0        # Get in parallel the maximum values in each pair of 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x10(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "minps      %%xmm1, %%xmm0"               // minps      %xmm1, %xmm0        # Get in parallel the minimum values in each pair of 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x10(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "mulps      %%xmm1, %%xmm0"               // mulps      %xmm1, %xmm0        # Multiply in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "rcpps      %%xmm0, %%xmm0"               // rcpps      %xmm0, %xmm0        # Compute Reciprocal (1/A) in parallel for 4 floats in XMM0 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "rsqrtps    %%xmm0, %%xmm0"               // rsqrtps    %xmm0, %xmm0        # Compute Reciprocal of Square Roots (1/sqrt(A)) in parallel for 4 floats in XMM0 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "sqrtps     %%xmm0, %%xmm0"               // sqrtps     %xmm0, %xmm0        # Compute Square Roots in parallel for 4 floats in XMM0 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x20(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x10(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "subps      %%xmm1, %%xmm0"               // subps      %xmm1, %xmm0        # Subtract in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
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



TestSse::TestSse()
    : TestBase(TestType::SSE, "Testing SSE instructions", testSseProcedure)
{
    UEFI_LT((""));
}

TestSse::~TestSse()
{
    UEFI_LT((""));
}



TestSse testSseInstance;
