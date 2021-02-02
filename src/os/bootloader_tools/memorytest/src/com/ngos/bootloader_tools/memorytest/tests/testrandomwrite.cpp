#include "testrandomwrite.h"

#include <com/ngos/bootloader_tools/memorytest/main/memorytest.h>
#include <com/ngos/bootloader_tools/memorytest/main/memorytestgui.h>
#include <com/ngos/bootloader_tools/memorytest/tests/asm_writememoryblock.h>
#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/macro/constants.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define SCORE_PER_GB_PER_SECOND 500



CPP_NO_OPTIMIZATION
void UEFI_API testRandomWriteProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestRandomWrite *test = (TestRandomWrite *)buffer;



    bad_uint64  regionStart = test->getRegionStart();
    bad_uint64  regionEnd   = test->getRegionEnd();
    bad_int64  testSize    = test->getTestSize();
    bad_uint8  *blockBuffer = test->getBuffer();
    bad_uint64  rand;



    bad_uint64 startTime = rdtsc();

    if (CPU::hasFlag(X86Feature::RDRAND))
    {
        for (bad_int64 i = 0; i < testSize && !MemoryTestGUI::isTerminated(); i += TEST_BLOCK_SIZE)
        {
            test->setProgress(i);

            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "rdrand     %0"         // rdrand     %rax    # Generate random number to RAX. %rax == (rand)
                    :                   // Output parameters
                        "=r"  (rand)    // 'r' - any general register, '=' - write only
            );
            // Ignore CppAlignmentVerifier [END]

            writeMemoryBlock(blockBuffer, (bad_uint8 *)(regionStart + (rand * TEST_BLOCK_SIZE) % (regionEnd - regionStart - TEST_BLOCK_SIZE)));
        }
    }
    else
    {
        for (bad_int64 i = 0; i < testSize && !MemoryTestGUI::isTerminated(); i += TEST_BLOCK_SIZE)
        {
            test->setProgress(i);

            rand = i * 7;

            writeMemoryBlock(blockBuffer, (bad_uint8 *)(regionStart + rand % (regionEnd - regionStart - TEST_BLOCK_SIZE)));
        }
    }

    bad_uint64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setAverageSpeed(testSize * MemoryTest::getCpuSpeed() / (endTime - startTime)));
    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_GB_PER_SECOND * test->getAverageSpeed() / GB));
}



TestRandomWrite::TestRandomWrite()
    : TestBase(TestType::RANDOM_WRITE, testRandomWriteProcedure)
    , mBuffer(nullptr)
{
    UEFI_LT((""));



    mBuffer = (bad_uint8 *)malloc(TEST_BLOCK_SIZE);
    UEFI_TEST_ASSERT(mBuffer != nullptr);
}

TestRandomWrite::~TestRandomWrite()
{
    UEFI_LT((""));
}

bad_uint8* TestRandomWrite::getBuffer() const
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return mBuffer;
}



TestRandomWrite testRandomWriteInstance;
