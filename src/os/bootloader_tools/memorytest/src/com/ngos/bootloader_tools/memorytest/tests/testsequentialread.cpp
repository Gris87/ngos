#include "testsequentialread.h"

#include <com/ngos/bootloader_tools/memorytest/main/memorytest.h>
#include <com/ngos/bootloader_tools/memorytest/main/memorytestgui.h>
#include <com/ngos/bootloader_tools/memorytest/tests/asm_readmemoryblock.h>
#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/macro/constants.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define SCORE_PER_GB_PER_SECOND 500



CPP_NO_OPTIMIZATION
void UEFI_API testSequentialReadProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSequentialRead *test = (TestSequentialRead *)buffer;



    bad_int64 testSize = test->getTestSize();



    bad_uint64 startTime = rdtsc();

    for (bad_int64 i = 0; i < testSize && !MemoryTestGUI::isTerminated(); i += TEST_BLOCK_SIZE)
    {
        test->setProgress(i);

        readMemoryBlock(nullptr, (bad_uint8 *)i);
    }

    bad_uint64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setAverageSpeed(testSize * MemoryTest::getCpuSpeed() / (endTime - startTime)));
    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_GB_PER_SECOND * test->getAverageSpeed() / GB));
}



TestSequentialRead::TestSequentialRead()
    : TestBase(TestType::SEQUENTIAL_READ, testSequentialReadProcedure)
{
    UEFI_LT((""));
}

TestSequentialRead::~TestSequentialRead()
{
    UEFI_LT((""));
}



TestSequentialRead testSequentialReadInstance;
