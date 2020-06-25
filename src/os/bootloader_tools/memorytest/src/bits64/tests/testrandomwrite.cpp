#include "testrandomwrite.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/fpu/fpu.h>
#include <macro/constants.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/memorytest.h"
#include "src/bits64/main/memorytestgui.h"
#include "src/bits64/tests/asm_writememoryblock.h"



#define SCORE_PER_SECOND 600



CPP_NO_OPTIMIZATION
void UEFI_API testRandomWriteProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestRandomWrite *test = (TestRandomWrite *)buffer;



    u64  regionStart = test->getRegionStart();
    u64  regionEnd   = test->getRegionEnd();
    i64  testSize    = test->getTestSize();
    u8  *blockBuffer = test->getBuffer();
    u64  rand;



    u64 startTime = rdtsc();

    if (CPU::hasFlag(X86Feature::RDRAND))
    {
        for (i64 i = 0; i < testSize && !MemoryTestGUI::isTerminated(); i += TEST_BLOCK_SIZE)
        {
            test->setProgress(i);

            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "rdrand     %0"         // rdrand     %rax    # Generate random number to RAX. %rax == (rand)
                    :                   // Output parameters
                        "=r"  (rand)    // 'r' - any general register, '=' - write only
            );
            // Ignore CppAlignmentVerifier [END]

            writeMemoryBlock(blockBuffer, (u8 *)(regionStart + (rand * TEST_BLOCK_SIZE) % (regionEnd - regionStart - TEST_BLOCK_SIZE)));
        }
    }
    else
    {
        for (i64 i = 0; i < testSize && !MemoryTestGUI::isTerminated(); i += TEST_BLOCK_SIZE)
        {
            test->setProgress(i);

            rand = i * 7;

            writeMemoryBlock(blockBuffer, (u8 *)(regionStart + rand % (regionEnd - regionStart - TEST_BLOCK_SIZE)));
        }
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * MemoryTest::getCpuSpeed() / (endTime - startTime) * testSize / GB));
}



TestRandomWrite::TestRandomWrite()
    : TestBase(MemoryTestType::RANDOM_WRITE, testRandomWriteProcedure)
    , mBuffer(nullptr)
{
    UEFI_LT((""));



    mBuffer = (u8 *)malloc(TEST_BLOCK_SIZE);
    UEFI_TEST_ASSERT(mBuffer != nullptr);
}

TestRandomWrite::~TestRandomWrite()
{
    UEFI_LT((""));
}

u8* TestRandomWrite::getBuffer() const
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return mBuffer;
}



TestRandomWrite testRandomWriteInstance;
