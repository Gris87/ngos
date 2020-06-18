#include "testrandomread.h"

#include <common/src/bits64/fpu/fpu.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/memorytestgui.h"





CPP_NO_OPTIMIZATION
void UEFI_API testRandomReadProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestRandomRead *test = (TestRandomRead *)buffer;



    UEFI_ASSERT_EXECUTION(test->setScore(1));
}



TestRandomRead::TestRandomRead()
    : TestBase(MemoryTestType::RANDOM_READ, testRandomReadProcedure)
{
    UEFI_LT((""));
}

TestRandomRead::~TestRandomRead()
{
    UEFI_LT((""));
}



TestRandomRead testRandomReadInstance;
