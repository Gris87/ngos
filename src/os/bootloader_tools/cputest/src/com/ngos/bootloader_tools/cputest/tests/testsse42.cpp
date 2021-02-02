#include "testsse42.h"

#include <com/ngos/bootloader_tools/cputest/main/cputest.h>
#include <com/ngos/bootloader_tools/cputest/main/cputestgui.h>
#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     250



CPP_NO_OPTIMIZATION
void UEFI_API testSse42Procedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSse42 *test = (TestSse42 *)buffer;

    if (CPU::hasFlag(X86Feature::XMM4_2))
    {
        bad_int64 a[2] = { 1987965842, -1987077212 };
        bad_int64 b[2] = { 1981132191, 1271329132 };



        bad_uint64 startTime = rdtsc();

        for (bad_int64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "movdqa     %0, %%xmm0"         "\n\t"    // movdqa     0x20(%rsp), %xmm0   # Put 2 quadwords located at %0 to XMM0
                "movdqa     %1, %%xmm1"         "\n\t"    // movdqa     0x10(%rsp), %xmm1   # Put 2 quadwords located at %1 to XMM1
                "pcmpgtq    %%xmm1, %%xmm0"               // pcmpgtq    %xmm1, %xmm0        # Compare signed quadwords in XMM0 with quadwords in XMM1. If quadword in XMM0 is greater then returns -1, otherwise 0. The results stored in XMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]
        }

        bad_uint64 endTime = rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
    }
    else
    {
        UEFI_ASSERT_EXECUTION(test->setScore(0));
    }
}



TestSse42::TestSse42()
    : TestBase(TestType::SSE42, "Testing SSE42 instructions", testSse42Procedure)
{
    UEFI_LT((""));
}

TestSse42::~TestSse42()
{
    UEFI_LT((""));
}



TestSse42 testSse42Instance;
