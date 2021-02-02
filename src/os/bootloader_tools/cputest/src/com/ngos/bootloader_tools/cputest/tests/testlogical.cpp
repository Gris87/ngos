#include "testlogical.h"

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
#define SCORE_PER_SECOND     1100



CPP_NO_OPTIMIZATION
void UEFI_API testLogicalProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestLogical *test = (TestLogical *)buffer;



    bad_uint64 temp1  = 0;
    bad_uint64 temp2  = 0;
    bad_uint64 temp3  = 0;
    bad_uint64 temp4  = 0;
    bad_uint64 temp5  = 0;
    bad_uint64 temp6  = 0;
    bad_uint64 temp7  = 0;
    bad_uint64 temp8  = 0;
    bad_uint64 temp9  = 0;
    bad_uint64 temp10 = 0;



    bad_uint64 startTime = rdtsc();

    for (bad_int64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
    {
        if (temp1 < 3)
        {
            temp1 += 3;
        }
        else
        {
            temp1 -= 3;
        }



        if (temp2 <= 3)
        {
            temp2 += 3;
        }
        else
        {
            temp2 -= 3;
        }



        if (temp3 > 3)
        {
            temp3 -= 3;
        }
        else
        {
            temp3 += 3;
        }



        if (temp4 >= 3)
        {
            temp4 -= 3;
        }
        else
        {
            temp4 += 3;
        }



        if (temp5 == 3)
        {
            temp5 -= 3;
        }
        else
        {
            temp5 += 3;
        }



        if (temp6 != 3)
        {
            temp6 += 3;
        }
        else
        {
            temp6 -= 3;
        }



        if (temp7)
        {
            temp7 -= 3;
        }
        else
        {
            temp7 += 3;
        }



        if (!temp8)
        {
            temp8 += 3;
        }
        else
        {
            temp6 -= 3;
        }



        if (temp9 || temp2)
        {
            temp9 -= 3;
        }
        else
        {
            temp9 += 3;
        }



        if (temp10 && temp3)
        {
            temp10 -= 3;
        }
        else
        {
            temp10 += 3;
        }
    }

    bad_uint64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
}



TestLogical::TestLogical()
    : TestBase(TestType::LOGICAL, "Testing logical operators", testLogicalProcedure)
{
    UEFI_LT((""));
}

TestLogical::~TestLogical()
{
    UEFI_LT((""));
}



TestLogical testLogicalInstance;
