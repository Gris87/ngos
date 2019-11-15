#include "testavx512dq.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testAvx512DqProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::init());



    TestAvx512Dq *test = (TestAvx512Dq *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512DQ))
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



TestAvx512Dq::TestAvx512Dq()
    : TestBase(TestType::AVX512DQ, "Testing AVX512DQ instructions", testAvx512DqProcedure)
{
    UEFI_LT((""));
}

TestAvx512Dq::~TestAvx512Dq()
{
    UEFI_LT((""));
}



TestAvx512Dq testAvx512DqInstance;
