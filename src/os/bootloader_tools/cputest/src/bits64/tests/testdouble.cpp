#include "testdouble.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     500



CPP_NO_OPTIMIZATION
void UEFI_API testDoubleProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::init());



    TestDouble *test = (TestDouble *)buffer;



    double temp1 = 0.0;
    double temp2 = 0.0;
    double temp3 = 1.0;
    double temp4 = 1.0;
    double temp5 = 0.0;
    double temp6 = 0.0;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
    {
        temp1 += 3.123;
        temp2 -= 5.987;
        temp3 *= 7.197;
        temp4 /= 9.678;

        ++temp5;
        --temp6;
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
}



TestDouble::TestDouble()
    : TestBase(TestType::DOUBLE, "Testing double arithmetic operators", testDoubleProcedure)
{
    UEFI_LT((""));
}

TestDouble::~TestDouble()
{
    UEFI_LT((""));
}



TestDouble testDoubleInstance;
