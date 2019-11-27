#include "testinteger.h"

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
#define SCORE_PER_SECOND     500



CPP_NO_OPTIMIZATION
void UEFI_API testIntegerProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestInteger *test = (TestInteger *)buffer;



    u64 temp1 = 0;
    u64 temp2 = 0;
    u64 temp3 = 1;
    u64 temp4 = 1;
    u64 temp5 = 0;
    u64 temp6 = 0;
    u64 temp7 = 0;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
    {
        temp1 += 3;
        temp2 -= 5;
        temp3 *= 7;
        temp4 /= 9;
        temp5 %= 5;

        ++temp6;
        --temp7;
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
}



TestInteger::TestInteger()
    : TestBase(TestType::INTEGER, "Testing integer arithmetic operators", testIntegerProcedure)
{
    UEFI_LT((""));
}

TestInteger::~TestInteger()
{
    UEFI_LT((""));
}



TestInteger testIntegerInstance;
