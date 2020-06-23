#include "testsequentialread.h"

#include <common/src/bits64/fpu/fpu.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/memorytestgui.h"





CPP_NO_OPTIMIZATION
void UEFI_API testSequentialReadProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestSequentialRead *test = (TestSequentialRead *)buffer;



    for (i64 i = 0; i < test->getTestSize(); ++i)
    {
        UEFI_ASSERT_EXECUTION(test->setProgress(i));
    }



    UEFI_ASSERT_EXECUTION(test->setScore(10000));
}



TestSequentialRead::TestSequentialRead()
    : TestBase(MemoryTestType::SEQUENTIAL_READ, testSequentialReadProcedure)
{
    UEFI_LT((""));
}

TestSequentialRead::~TestSequentialRead()
{
    UEFI_LT((""));
}



TestSequentialRead testSequentialReadInstance;
