#include "testavx512f.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAvx512FProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAvx512F::TestAvx512F()
    : TestBase(TestType::AVX512F, "Testing AVX512F instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAvx512FProcedure;
}

TestAvx512F::~TestAvx512F()
{
    UEFI_LT((""));
}



TestAvx512F testAvx512FInstance;
