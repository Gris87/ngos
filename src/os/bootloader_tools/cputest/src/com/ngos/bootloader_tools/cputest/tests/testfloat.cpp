#include "testfloat.h"

#include <common/src/com/ngos/shared/common/asm/instructions.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <common/src/com/ngos/shared/common/fpu/fpu.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <uefibase/src/com/ngos/shared/uefibase/main/setupcr4.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>

#include "src/com/ngos/bootloader_tools/cputest/main/cputest.h"
#include "src/com/ngos/bootloader_tools/cputest/main/cputestgui.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     600



CPP_NO_OPTIMIZATION
void UEFI_API testFloatProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestFloat *test = (TestFloat *)buffer;



    float temp1 = 0.0f;
    float temp2 = 0.0f;
    float temp3 = 1.0f;
    float temp4 = 1.0f;
    float temp5 = 0.0f;
    float temp6 = 0.0f;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
    {
        temp1 += 3.123f;
        temp2 -= 5.987f;
        temp3 *= 7.197f;
        temp4 /= 9.678f;

        ++temp5;
        --temp6;
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
}



TestFloat::TestFloat()
    : TestBase(TestType::FLOAT, "Testing float arithmetic operators", testFloatProcedure)
{
    UEFI_LT((""));
}

TestFloat::~TestFloat()
{
    UEFI_LT((""));
}



TestFloat testFloatInstance;
