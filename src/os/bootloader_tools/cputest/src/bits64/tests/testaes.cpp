#include "testaes.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 1000
#define SCORE_PER_SECOND     1000



void UEFI_API testAesProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestAes *test = (TestAes *)buffer;

    if (CPU::hasFlag(X86Feature::AES))
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



TestAes::TestAes()
    : TestBase(TestType::AES, "Testing AES instructions", testAesProcedure)
{
    UEFI_LT((""));
}

TestAes::~TestAes()
{
    UEFI_LT((""));
}



TestAes testAesInstance;
