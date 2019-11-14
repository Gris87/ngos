#include "testavx512bw.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAvx512BwProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAvx512Bw::TestAvx512Bw()
    : TestBase(TestType::AVX512BW, "Testing AVX512BW instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAvx512BwProcedure;
}

TestAvx512Bw::~TestAvx512Bw()
{
    UEFI_LT((""));
}



TestAvx512Bw testAvx512BwInstance;
