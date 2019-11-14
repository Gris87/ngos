#include "testfloat.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testFloatProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestFloat::TestFloat()
    : TestBase(TestType::FLOAT, "Testing FLOAT instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testFloatProcedure;
}

TestFloat::~TestFloat()
{
    UEFI_LT((""));
}



TestFloat testFloatInstance;
