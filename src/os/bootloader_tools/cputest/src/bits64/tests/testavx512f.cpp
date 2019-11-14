#include "testavx512f.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



void UEFI_API testAvx512FProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestAvx512F *test = (TestAvx512F *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512F))
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



TestAvx512F::TestAvx512F()
    : TestBase(TestType::AVX512F, "Testing AVX512F instructions", testAvx512FProcedure)
{
    UEFI_LT((""));
}

TestAvx512F::~TestAvx512F()
{
    UEFI_LT((""));
}



TestAvx512F testAvx512FInstance;
