#include "testavx512dq.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testAvx512DqProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestAvx512Dq::TestAvx512Dq()
    : TestBase(TestType::AVX512DQ, "Testing AVX512DQ instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testAvx512DqProcedure;
}

TestAvx512Dq::~TestAvx512Dq()
{
    UEFI_LT((""));
}



TestAvx512Dq testAvx512DqInstance;
