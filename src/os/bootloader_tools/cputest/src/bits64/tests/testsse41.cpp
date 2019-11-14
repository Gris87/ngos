#include "testsse41.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testSse41Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestSse41::TestSse41()
    : TestBase(TestType::SSE41, "Testing SSE41 instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testSse41Procedure;
}

TestSse41::~TestSse41()
{
    UEFI_LT((""));
}



TestSse41 testSse41Instance;
