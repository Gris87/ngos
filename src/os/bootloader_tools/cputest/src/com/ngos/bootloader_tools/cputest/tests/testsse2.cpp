#include "testsse2.h"

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
void UEFI_API testSse2Procedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSse2 *test = (TestSse2 *)buffer;

    if (CPU::hasFlag(X86Feature::XMM2))
    {
        double a[2] = { 0.5, 0.4 };
        double b[2] = { 0.8, 0.3 };



        u64 startTime = AsmUtils::rdtsc();

        for (good_i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "addpd      %%xmm1, %%xmm0"               // addpd      %xmm1, %xmm0        # Add in parallel 2 doubles in XMM0 with 2 doubles in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "divpd      %%xmm1, %%xmm0"               // divpd      %xmm1, %xmm0        # Divide in parallel 2 doubles in XMM0 with 2 doubles in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "maxpd      %%xmm1, %%xmm0"               // maxpd      %xmm1, %xmm0        # Get in parallel the maximum values in each pair of 2 doubles in XMM0 with 2 doubles in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "minpd      %%xmm1, %%xmm0"               // minpd      %xmm1, %xmm0        # Get in parallel the minimum values in each pair of 2 doubles in XMM0 with 2 doubles in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "mulpd      %%xmm1, %%xmm0"               // mulpd      %xmm1, %xmm0        # Multiply in parallel 2 doubles in XMM0 with 2 doubles in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 16 bytes located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 16 bytes located at %1 to XMM1
                "paddb      %%xmm1, %%xmm0"               // paddb      %xmm1, %xmm0        # Add in parallel 16 bytes in XMM0 with 16 bytes in XMM1 and store results in XMM0
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
                "paddd      %%xmm1, %%xmm0"               // paddd      %xmm1, %xmm0        # Add in parallel 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 2 quadwords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 2 quadwords located at %1 to XMM1
                "paddq      %%xmm1, %%xmm0"               // paddq      %xmm1, %xmm0        # Add in parallel 2 quadwords in XMM0 with 2 quadwords in XMM1 and store results in XMM0
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
                "paddw      %%xmm1, %%xmm0"               // paddw      %xmm1, %xmm0        # Add in parallel 8 words in XMM0 with 8 words in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 16 bytes located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 16 bytes located at %1 to XMM1
                "psubb      %%xmm1, %%xmm0"               // psubb      %xmm1, %xmm0        # Subtract in parallel 16 bytes in XMM0 with 16 bytes in XMM1 and store results in XMM0
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
                "psubd      %%xmm1, %%xmm0"               // psubd      %xmm1, %xmm0        # Subtract in parallel 4 doublewords in XMM0 with 4 doublewords in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 2 quadwords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 2 quadwords located at %1 to XMM1
                "psubq      %%xmm1, %%xmm0"               // psubq      %xmm1, %xmm0        # Subtract in parallel 2 quadwords in XMM0 with 2 quadwords in XMM1 and store results in XMM0
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
                "psubw      %%xmm1, %%xmm0"               // psubw      %xmm1, %xmm0        # Subtract in parallel 8 words in XMM0 with 8 words in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "sqrtpd     %%xmm0, %%xmm0"               // sqrtpd     %xmm0, %xmm0        # Compute Square Roots in parallel for 2 doubles in XMM0 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movapd     %0, %%xmm0"         "\n\t"    // movapd     0x20(%rsp), %xmm0   # Put 2 doubles located at %0 to XMM0
                "movapd     %1, %%xmm1"         "\n\t"    // movapd     0x10(%rsp), %xmm1   # Put 2 doubles located at %1 to XMM1
                "subpd      %%xmm1, %%xmm0"               // subpd      %xmm1, %xmm0        # Subtract in parallel 2 doubles in XMM0 with 2 doubles in XMM1 and store results in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
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



TestSse2::TestSse2()
    : TestBase(TestType::SSE2, "Testing SSE2 instructions", testSse2Procedure)
{
    UEFI_LT((""));
}

TestSse2::~TestSse2()
{
    UEFI_LT((""));
}



TestSse2 testSse2Instance;
