#include "testbitwise.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     300



void UEFI_API testBitwiseProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestBitwise *test = (TestBitwise *)buffer;



    u64 temp1 = 0;
    u64 temp2 = 0;
    u64 temp3 = 0;
    u64 temp4 = 0;
    u64 temp5 = 0;
    u64 temp6 = 0;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS; ++i)
    {
        temp1 ^=  1;
        temp2 &=  1;
        temp3 |=  1;
        temp4 <<= 1;
        temp5 >>= 1;
        temp6 =   ~temp6;
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
}



TestBitwise::TestBitwise()
    : TestBase(TestType::BITWISE, "Testing bitwise operators", testBitwiseProcedure)
{
    UEFI_LT((""));
}

TestBitwise::~TestBitwise()
{
    UEFI_LT((""));
}



TestBitwise testBitwiseInstance;
