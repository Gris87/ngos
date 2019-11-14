#include "testsse.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     500



void UEFI_API testSseProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestSse *test = (TestSse *)buffer;

    if (CPU::hasFlag(X86Feature::XMM))
    {
        float a[4] = { 0.5, 0.4, 0.2, 0.1 };
        float b[4] = { 0.8, 0.3, 0.8, 0.6 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "movaps  %1, %%xmm1"    "\n\t"  // movaps  0x10(%rsp), %xmm1    # Put 4 floats located at %1 to XMM1
                "addps   %%xmm1, %%xmm0"        // addps   %xmm1, %xmm0         # Add in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a),                // 'm' - use memory
                        "m" (b)                 // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "movaps  %1, %%xmm1"    "\n\t"  // movaps  0x10(%rsp), %xmm1    # Put 4 floats located at %1 to XMM1
                "divps   %%xmm1, %%xmm0"        // divps   %xmm1, %xmm0         # Divide in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a),                // 'm' - use memory
                        "m" (b)                 // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "movaps  %1, %%xmm1"    "\n\t"  // movaps  0x10(%rsp), %xmm1    # Put 4 floats located at %1 to XMM1
                "maxps   %%xmm1, %%xmm0"        // maxps   %xmm1, %xmm0         # Get in parallel the maximum values in each pair of 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a),                // 'm' - use memory
                        "m" (b)                 // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "movaps  %1, %%xmm1"    "\n\t"  // movaps  0x10(%rsp), %xmm1    # Put 4 floats located at %1 to XMM1
                "minps   %%xmm1, %%xmm0"        // minps   %xmm1, %xmm0         # Get in parallel the minimum values in each pair of 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a),                // 'm' - use memory
                        "m" (b)                 // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "movaps  %1, %%xmm1"    "\n\t"  // movaps  0x10(%rsp), %xmm1    # Put 4 floats located at %1 to XMM1
                "mulps   %%xmm1, %%xmm0"        // mulps   %xmm1, %xmm0         # Multiply in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a),                // 'm' - use memory
                        "m" (b)                 // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "movaps  %1, %%xmm1"    "\n\t"  // movaps  0x10(%rsp), %xmm1    # Put 4 floats located at %1 to XMM1
                "subps   %%xmm1, %%xmm0"        // subps   %xmm1, %xmm0         # Subtract in parallel 4 floats in XMM0 with 4 floats in XMM1 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a),                // 'm' - use memory
                        "m" (b)                 // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "rcpps   %%xmm0, %%xmm0"        // rcpps   %xmm0, %xmm0         # Compute Reciprocal (1/A) in parallel for 4 floats in XMM0 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a)                // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "rsqrtps %%xmm0, %%xmm0"        // rsqrtps %xmm0, %xmm0         # Compute Reciprocal of Square Roots (1/sqrt(A)) in parallel for 4 floats in XMM0 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a)                // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps  %0, %%xmm0"    "\n\t"  // movaps  0x20(%rsp), %xmm0    # Put 4 floats located at %0 to XMM0
                "sqrtps  %%xmm0, %%xmm0"        // sqrtps  %xmm0, %xmm0         # Compute Square Roots in parallel for 4 floats in XMM0 and store results in XMM0
                    :                           // Output parameters
                    :                           // Input parameters
                        "m" (a)                // 'm' - use memory
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
