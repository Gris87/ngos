#include "testbase.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



TestBase* cpuTests[(u64)TestType::MAXIMUM];



TestBase::TestBase(TestType type, const char8 *name, u64 score)
    : mType(type)
    , mName(name)
    , mScore(score)
    , mProcedure(nullptr)
{
    UEFI_LT((" | type = %u, name = 0x%p, score = %u", type, name, score));

    UEFI_ASSERT(type < TestType::MAXIMUM, "type is invalid");
    UEFI_ASSERT(name,                     "name is null");
    UEFI_ASSERT(score > 0,                "score is zero");



    UEFI_TEST_ASSERT(cpuTests[(u64)mType] == nullptr);



    cpuTests[(u64)mType] = this;
}

TestBase::~TestBase()
{
    UEFI_LT((""));
}

const char8* TestBase::getName() const
{
    UEFI_LT((""));



    return mName;
}

u64 TestBase::getScore() const
{
    UEFI_LT((""));



    return mScore;
}

uefi_ap_procedure TestBase::getProcedure() const
{
    UEFI_LT((""));



    return mProcedure;
}
