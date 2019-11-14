#include "testaes.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAesProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAes::TestAes()
    : TestBase(TestType::AES, "Testing AES instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAesProcedure;
}

TestAes::~TestAes()
{
    UEFI_LT((""));
}



TestAes testAesInstance;
