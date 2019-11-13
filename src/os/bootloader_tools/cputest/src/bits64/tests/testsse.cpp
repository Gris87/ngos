#include "testsse.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testSseProcedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestSse::TestSse()
    : TestBase(TestType::SSE, "Testing SSE instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testSseProcedure;
}

TestSse::~TestSse()
{
    UEFI_LT((""));
}



TestSse testSseInstance;
