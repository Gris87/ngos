#include "testbitwise.h"

#include <common/src/com/ngos/shared/common/asm/instructions.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <common/src/com/ngos/shared/common/fpu/fpu.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/com/ngos/bootloader_tools/cputest/main/cputest.h"
#include "src/com/ngos/bootloader_tools/cputest/main/cputestgui.h"



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     350



CPP_NO_OPTIMIZATION
void UEFI_API testBitwiseProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestBitwise *test = (TestBitwise *)buffer;



    u64 temp1 = 0;
    u64 temp2 = 0;
    u64 temp3 = 0;
    u64 temp4 = 0;
    u64 temp5 = 0;
    u64 temp6 = 0;



    u64 startTime = rdtsc();

    for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
    {
        temp1 ^=  1;
        temp2 &=  1;
        temp3 |=  1;
        temp4 <<= 1;
        temp5 >>= 1;
        temp6 =   ~temp6;
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
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
