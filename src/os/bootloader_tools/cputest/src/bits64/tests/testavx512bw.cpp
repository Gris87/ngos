#include "testavx512bw.h"

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
void UEFI_API testAvx512BwProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::init());



    TestAvx512Bw *test = (TestAvx512Bw *)buffer;

    if (CPU::hasFlag(X86Feature::AVX512BW))
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



TestAvx512Bw::TestAvx512Bw()
    : TestBase(TestType::AVX512BW, "Testing AVX512BW instructions", testAvx512BwProcedure)
{
    UEFI_LT((""));
}

TestAvx512Bw::~TestAvx512Bw()
{
    UEFI_LT((""));
}



TestAvx512Bw testAvx512BwInstance;