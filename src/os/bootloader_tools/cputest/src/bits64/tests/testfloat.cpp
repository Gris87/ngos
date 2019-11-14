#include "testfloat.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



void UEFI_API testFloatProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestFloat *test = (TestFloat *)buffer;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
    {
        // Nothing
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
}



TestFloat::TestFloat()
    : TestBase(TestType::FLOAT, "Testing float arithmetics", testFloatProcedure)
{
    UEFI_LT((""));
}

TestFloat::~TestFloat()
{
    UEFI_LT((""));
}



TestFloat testFloatInstance;
