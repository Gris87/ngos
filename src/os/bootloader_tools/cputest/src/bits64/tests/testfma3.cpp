#include "testfma3.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 1000
#define SCORE_PER_SECOND     1000



void UEFI_API testFma3Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestFma3 *test = (TestFma3 *)buffer;

    if (CPU::hasFlag(X86Feature::FMA))
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
