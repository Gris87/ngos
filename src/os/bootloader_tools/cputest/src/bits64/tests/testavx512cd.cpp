#include "testavx512cd.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testAvx512CdProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestAvx512Cd *test = (TestAvx512Cd *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512CD))
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



TestAvx512Cd::TestAvx512Cd()
    : TestBase(TestType::AVX512CD, "Testing AVX512CD instructions", testAvx512CdProcedure)
{
    UEFI_LT((""));
}

TestAvx512Cd::~TestAvx512Cd()
{
    UEFI_LT((""));
}



TestAvx512Cd testAvx512CdInstance;
