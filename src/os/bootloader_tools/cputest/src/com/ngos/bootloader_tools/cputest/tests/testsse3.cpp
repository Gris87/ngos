#include "testsse3.h"

#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>

#include "com/ngos/bootloader_tools/cputest/main/cputest.h"
#include "com/ngos/bootloader_tools/cputest/main/cputestgui.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     600



CPP_NO_OPTIMIZATION
void UEFI_API testSse3Procedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSse3 *test = (TestSse3 *)buffer;

    if (CPU::hasFlag(X86Feature::XMM3))
    {
        double a[2] = { 0.5, 0.4 };
        double b[2] = { 0.8, 0.3 };
        float  c[4] = { 0.5, 0.4, 0.2, 0.1 };
        float  d[4] = { 0.8, 0.3, 0.8, 0.6 };



        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "addsubpd   %%xmm1, %%xmm0"               // addsubpd   %xmm1, %xmm0        # Add 2nd double of XMM0 with 2nd double of XMM1 and subtract 1st double of XMM0 with 1st double of XMM1. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x40(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x30(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "addsubps   %%xmm1, %%xmm0"               // addsubps   %xmm1, %xmm0        # Add 2nd/4th float of XMM0 with 2nd/4th float of XMM1 and subtract 1st/3rd float of XMM0 with 1st/3rd float of XMM1. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (c),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (d)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "haddpd     %%xmm1, %%xmm0"               // haddpd     %xmm1, %xmm0        # Add doubles from XMM0 with doubles from XMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = B[0] + B[1]. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x40(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x30(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "haddps     %%xmm1, %%xmm0"               // haddps     %xmm1, %xmm0        # Add floats from XMM0 with floats from XMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; C[2] = B[0] + B[1]; C[3] = B[2] + B[3]. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (c),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (d)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "hsubpd     %%xmm1, %%xmm0"               // hsubpd     %xmm1, %xmm0        # Subtract doubles from XMM0 with doubles from XMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = B[0] - B[1]. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movaps     %0, %%xmm0"         "\n\t"    // movaps     0x40(%rsp), %xmm0   # Put 4 floats located at %0 to XMM0
                "movaps     %1, %%xmm1"         "\n\t"    // movaps     0x30(%rsp), %xmm1   # Put 4 floats located at %1 to XMM1
                "hsubps     %%xmm1, %%xmm0"               // hsubps     %xmm1, %xmm0        # Subtract floats from XMM0 with floats from XMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = A[2] - A[3]; C[2] = B[0] - B[1]; C[3] = B[2] - B[3]. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (c),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (d)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "phaddd     %%xmm1, %%xmm0"               // phaddd     %xmm1, %xmm0        # Add doublewords from XMM0 with doublewords from XMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; C[2] = B[0] + B[1]; C[3] = B[2] + B[3]. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 8 words located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 8 words located at %1 to XMM1
                "phaddw     %%xmm1, %%xmm0"               // phaddw     %xmm1, %xmm0        # Add words from XMM0 with words from XMM1 horizontally in the following way: C[0] = A[0] + A[1]; C[1] = A[2] + A[3]; ... ; C[7] = B[6] + B[7]. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 4 doublewords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 4 doublewords located at %1 to XMM1
                "phsubd     %%xmm1, %%xmm0"               // phsubd     %xmm1, %xmm0        # Subtract doublewords from XMM0 with doublewords from XMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = A[2] - A[3]; C[2] = B[0] - B[1]; C[3] = B[2] - B[3]. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 8 words located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 8 words located at %1 to XMM1
                "phsubw     %%xmm1, %%xmm0"               // phsubw     %xmm1, %xmm0        # Subtract words from XMM0 with words from XMM1 horizontally in the following way: C[0] = A[0] - A[1]; C[1] = A[2] - A[3]; ... ; C[7] = B[6] - B[7]. The results stored in XMM0
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



TestSse3::TestSse3()
    : TestBase(TestType::SSE3, "Testing SSE3 instructions", testSse3Procedure)
{
    UEFI_LT((""));
}

TestSse3::~TestSse3()
{
    UEFI_LT((""));
}



TestSse3 testSse3Instance;
