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



    float temp1 = 0.0f;
    float temp2 = 0.0f;
    float temp3 = 1.0f;
    float temp4 = 1.0f;
    float temp5 = 0.0f;
    float temp6 = 0.0f;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
    {
        temp1 += 3.123f;
        temp2 -= 5.987f;
        temp3 *= 7.197f;
        temp4 /= 9.678f;

        ++temp5;
        --temp6;
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
}



TestFloat::TestFloat()
    : TestBase(TestType::FLOAT, "Testing float arithmetic operators", testFloatProcedure)
{
    UEFI_LT((""));
}

TestFloat::~TestFloat()
{
    UEFI_LT((""));
}



TestFloat testFloatInstance;
