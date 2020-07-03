#include "testsequentialwrite.h"

#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/macro/constants.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>

#include "com/ngos/bootloader_tools/memorytest/main/memorytest.h"
#include "com/ngos/bootloader_tools/memorytest/main/memorytestgui.h"
#include "com/ngos/bootloader_tools/memorytest/tests/asm_writememoryblock.h"



#define SCORE_PER_GB_PER_SECOND 500



CPP_NO_OPTIMIZATION
void UEFI_API testSequentialWriteProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSequentialWrite *test = (TestSequentialWrite *)buffer;



    i64  testSize    = test->getTestSize();
    u8  *blockBuffer = test->getBuffer();



    u64 startTime = rdtsc();

    for (i64 i = 0; i < testSize && !MemoryTestGUI::isTerminated(); i += TEST_BLOCK_SIZE)
    {
        test->setProgress(i);

        writeMemoryBlock(blockBuffer, (u8 *)i);
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setAverageSpeed(testSize * MemoryTest::getCpuSpeed() / (endTime - startTime)));
    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_GB_PER_SECOND * test->getAverageSpeed() / GB));
}



TestSequentialWrite::TestSequentialWrite()
    : TestBase(TestType::SEQUENTIAL_WRITE, testSequentialWriteProcedure)
    , mBuffer(nullptr)
{
    UEFI_LT((""));



    mBuffer = (u8 *)malloc(TEST_BLOCK_SIZE);
    UEFI_TEST_ASSERT(mBuffer != nullptr);
}

TestSequentialWrite::~TestSequentialWrite()
{
    UEFI_LT((""));
}

u8* TestSequentialWrite::getBuffer() const
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return mBuffer;
}



TestSequentialWrite testSequentialWriteInstance;
