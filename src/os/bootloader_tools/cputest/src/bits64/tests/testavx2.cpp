#include "testavx2.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAvx2Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAvx2::TestAvx2()
    : TestBase(TestType::AVX2, "Testing AVX2 instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAvx2Procedure;
}

TestAvx2::~TestAvx2()
{
    UEFI_LT((""));
}



TestAvx2 testAvx2Instance;
