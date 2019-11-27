#include "testsse41.h"

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
#define SCORE_PER_SECOND     400



CPP_NO_OPTIMIZATION
void UEFI_API testSse41Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSse41 *test = (TestSse41 *)buffer;

    if (CPU::hasFlag(X86Feature::XMM4_1))
    {
        i8 a[16] = { 10, 64, 32, -46, -34, 97, -13, 64, 31, 97, -43, 37, 67, -24, 95, 32 };
        i8 b[16] = { 31, 13, 92, -16, -54, 27, -73, 34, 41, 87, -63, 27, 47, -94, 35, 62 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 16 bytes located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 16 bytes located at %1 to XMM1
                "pmaxsb     %%xmm1, %%xmm0"               // pmaxsb     %xmm1, %xmm0        # Get in parallel the maximum signed values in each pair of 16 bytes in XMM0 with 16 bytes in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "pmaxsd     %%xmm1, %%xmm0"               // pmaxsd     %xmm1, %xmm0        # Get in parallel the maximum signed values in each pair of 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "pmaxud     %%xmm1, %%xmm0"               // pmaxud     %xmm1, %xmm0        # Get in parallel the maximum unsigned values in each pair of 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 8 words located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 8 words located at %1 to XMM1
                "pmaxuw     %%xmm1, %%xmm0"               // pmaxuw     %xmm1, %xmm0        # Get in parallel the maximum unsigned values in each pair of 8 words in XMM0 with 8 words in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 16 bytes located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 16 bytes located at %1 to XMM1
                "pminsb     %%xmm1, %%xmm0"               // pminsb     %xmm1, %xmm0        # Get in parallel the minimum signed values in each pair of 16 bytes in XMM0 with 16 bytes in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "pminsd     %%xmm1, %%xmm0"               // pminsd     %xmm1, %xmm0        # Get in parallel the minimum signed values in each pair of 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "pminud     %%xmm1, %%xmm0"               // pminud     %xmm1, %xmm0        # Get in parallel the minimum unsigned values in each pair of 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 8 words located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 8 words located at %1 to XMM1
                "pminuw     %%xmm1, %%xmm0"               // pminuw     %xmm1, %xmm0        # Get in parallel the minimum unsigned values in each pair of 8 words in XMM0 with 8 words in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "pmuldq     %%xmm1, %%xmm0"               // pmuldq     %xmm1, %xmm0        # Multiply in parallel 2 doublewords in XMM0 with 2 doublewords in XMM1 as following: C[0] = A[0] * B[0]; C[1] = A[2] * B[2]. The 64 bit results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "pmulld     %%xmm1, %%xmm0"               // pmulld     %xmm1, %xmm0        # Multiply in parallel 4 doublewords in XMM0 with 4 doublewords in XMM1 and store the lowest 32 bit results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory
                        "m" (b)                           // 'm' - use memory
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



TestSse41::TestSse41()
    : TestBase(TestType::SSE41, "Testing SSE41 instructions", testSse41Procedure)
{
    UEFI_LT((""));
}

TestSse41::~TestSse41()
{
    UEFI_LT((""));
}



TestSse41 testSse41Instance;
