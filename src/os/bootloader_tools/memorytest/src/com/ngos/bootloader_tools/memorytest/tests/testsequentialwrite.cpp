#include "testsequentialwrite.h"

#include <asm/instructions.h>
#include <common/src/bits64/fpu/fpu.h>
#include <macro/constants.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/memorytest.h"
#include "src/bits64/main/memorytestgui.h"
#include "src/bits64/tests/asm_writememoryblock.h"



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
    : TestBase(MemoryTestType::SEQUENTIAL_WRITE, testSequentialWriteProcedure)
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
