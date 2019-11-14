#include "testinteger.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testIntegerProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestInteger::TestInteger()
    : TestBase(TestType::INTEGER, "Testing INTEGER arithmetics", 100)
{
    UEFI_LT((""));



    mProcedure = testIntegerProcedure;
}

TestInteger::~TestInteger()
{
    UEFI_LT((""));
}



TestInteger testIntegerInstance;
