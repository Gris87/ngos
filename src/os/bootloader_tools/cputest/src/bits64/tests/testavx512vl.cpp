#include "testavx512vl.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testAvx512VlProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    TestAvx512Vl *test = (TestAvx512Vl *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512VL))
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



TestAvx512Vl::TestAvx512Vl()
    : TestBase(TestType::AVX512VL, "Testing AVX512VL instructions", testAvx512VlProcedure)
{
    UEFI_LT((""));
}

TestAvx512Vl::~TestAvx512Vl()
{
    UEFI_LT((""));
}



TestAvx512Vl testAvx512VlInstance;
