#include "testavx512cd.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAvx512CdProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAvx512Cd::TestAvx512Cd()
    : TestBase(TestType::AVX512CD, "Testing AVX512CD instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAvx512CdProcedure;
}

TestAvx512Cd::~TestAvx512Cd()
{
    UEFI_LT((""));
}



TestAvx512Cd testAvx512CdInstance;
