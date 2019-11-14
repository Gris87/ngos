#include "testsse3.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testSse3Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestSse3::TestSse3()
    : TestBase(TestType::SSE3, "Testing SSE3 instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testSse3Procedure;
}

TestSse3::~TestSse3()
{
    UEFI_LT((""));
}



TestSse3 testSse3Instance;
