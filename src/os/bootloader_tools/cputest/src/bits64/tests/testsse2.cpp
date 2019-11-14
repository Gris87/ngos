#include "testsse2.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testSse2Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestSse2::TestSse2()
    : TestBase(TestType::SSE2, "Testing SSE2 instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testSse2Procedure;
}

TestSse2::~TestSse2()
{
    UEFI_LT((""));
}



TestSse2 testSse2Instance;
