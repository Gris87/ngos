#include "testsse2.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testSse2Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestSse2 *test = (TestSse2 *)buffer;

    if (CPU::hasFlag(X86Feature::XMM2))
    {
        u64 startTime = rdtsc();

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
        {
            // Nothing
        }

        u64 endTime = rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
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
