#include "testsse42.h"

#include <ngos/linkage.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



void UEFI_API testSse42Procedure(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));



    AVOID_UNUSED(buffer);
}



TestSse42::TestSse42()
    : TestBase(TestType::SSE42, "Testing SSE42 instructions", 100)
{
    UEFI_LT((""));



    mProcedure = testSse42Procedure;
}

TestSse42::~TestSse42()
{
    UEFI_LT((""));
}



TestSse42 testSse42Instance;
