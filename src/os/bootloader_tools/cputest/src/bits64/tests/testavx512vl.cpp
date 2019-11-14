#include "testavx512vl.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAvx512VlProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAvx512Vl::TestAvx512Vl()
    : TestBase(TestType::AVX512VL, "Testing AVX512VL instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAvx512VlProcedure;
}

TestAvx512Vl::~TestAvx512Vl()
{
    UEFI_LT((""));
}



TestAvx512Vl testAvx512VlInstance;
