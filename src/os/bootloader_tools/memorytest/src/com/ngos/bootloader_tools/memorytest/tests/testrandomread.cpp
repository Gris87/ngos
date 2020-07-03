#include "testrandomread.h"

#include <com/ngos/shared/common/asm/instructions.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/macro/constants.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>

#include "com/ngos/bootloader_tools/memorytest/main/memorytest.h"
#include "com/ngos/bootloader_tools/memorytest/main/memorytestgui.h"
#include "com/ngos/bootloader_tools/memorytest/tests/asm_readmemoryblock.h"



#define SCORE_PER_GB_PER_SECOND 500



CPP_NO_OPTIMIZATION
void UEFI_API testRandomReadProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestRandomRead *test = (TestRandomRead *)buffer;



    u64 regionStart = test->getRegionStart();
    u64 regionEnd   = test->getRegionEnd();
    i64 testSize    = test->getTestSize();
    u64 rand;



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

            readMemoryBlock(nullptr, (u8 *)(regionStart + (rand * TEST_BLOCK_SIZE) % (regionEnd - regionStart - TEST_BLOCK_SIZE)));
        }
    }
    else
    {
        for (i64 i = 0; i < testSize && !MemoryTestGUI::isTerminated(); i += TEST_BLOCK_SIZE)
        {
            test->setProgress(i);

            rand = i * 7;

            readMemoryBlock(nullptr, (u8 *)(regionStart + rand % (regionEnd - regionStart - TEST_BLOCK_SIZE)));
        }
    }

    u64 endTime = rdtsc();



    UEFI_ASSERT_EXECUTION(test->setAverageSpeed(testSize * MemoryTest::getCpuSpeed() / (endTime - startTime)));
    UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_GB_PER_SECOND * test->getAverageSpeed() / GB));
}



TestRandomRead::TestRandomRead()
    : TestBase(TestType::RANDOM_READ, testRandomReadProcedure)
{
    UEFI_LT((""));
}

TestRandomRead::~TestRandomRead()
{
    UEFI_LT((""));
}



TestRandomRead testRandomReadInstance;
