#include "testavx.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAvxProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAvx::TestAvx()
    : TestBase(TestType::AVX, "Testing AVX instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAvxProcedure;
}

TestAvx::~TestAvx()
{
    UEFI_LT((""));
}



TestAvx testAvxInstance;
