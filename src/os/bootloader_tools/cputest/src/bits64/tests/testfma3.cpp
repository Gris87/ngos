#include "testfma3.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testFma3Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestFma3::TestFma3()
    : TestBase(TestType::FMA3, "Testing FMA3 instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testFma3Procedure;
}

TestFma3::~TestFma3()
{
    UEFI_LT((""));
}



TestFma3 testFma3Instance;
