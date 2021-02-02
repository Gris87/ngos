#include "testdouble.h"

#include <com/ngos/bootloader_tools/cputest/main/cputest.h>
#include <com/ngos/bootloader_tools/cputest/main/cputestgui.h>
#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     600



CPP_NO_OPTIMIZATION
void UEFI_API testDoubleProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestDouble *test = (TestDouble *)buffer;



    double temp1 = 0.0;
    double temp2 = 0.0;
    double temp3 = 1.0;
    double temp4 = 1.0;
    double temp5 = 0.0;
    double temp6 = 0.0;



    bad_uint64 startTime = rdtsc();

    for (bad_int64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
    {
        temp1 += 3.123;
        temp2 -= 5.987;
        temp3 *= 7.197;
        temp4 /= 9.678;

        ++temp5;
        --temp6;
    }

    bad_uint64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
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
