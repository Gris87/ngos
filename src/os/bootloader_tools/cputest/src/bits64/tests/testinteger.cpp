#include "testinteger.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



void UEFI_API testIntegerProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestInteger *test = (TestInteger *)buffer;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
    {
        // Nothing
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
}



TestInteger::TestInteger()
    : TestBase(TestType::INTEGER, "Testing integer arithmetics", testIntegerProcedure)
{
    UEFI_LT((""));
}

TestInteger::~TestInteger()
{
    UEFI_LT((""));
}



TestInteger testIntegerInstance;
