#include "testbase.h"

#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



TestBase* cpuTests[(u64)TestType::MAXIMUM];



TestBase::TestBase(TestType type, const char8 *name, uefi_ap_procedure procedure)
    : mName(name)
    , mProcedure(procedure)
    , mScore(0)
    , mCompleted(false)
{
    UEFI_LT((" | type = %u, name = 0x%p, procedure = 0x%p", type, name, procedure));

    UEFI_ASSERT(type < TestType::MAXIMUM, "type is invalid");
    UEFI_ASSERT(name,                     "name is null");
    UEFI_ASSERT(procedure,                "procedure is null");



    UEFI_TEST_ASSERT(cpuTests[(u64)type] == nullptr);



    cpuTests[(u64)type] = this;
}

TestBase::~TestBase()
{
    UEFI_LT((""));
}

NgosStatus TestBase::reset()
{
    UEFI_LT((""));



    mScore     = 0;
    mCompleted = false;



    return NgosStatus::OK;
}

const char8* TestBase::getName() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mName;
}

uefi_ap_procedure TestBase::getProcedure() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mProcedure;
}

NgosStatus TestBase::setScore(u64 score)
{
    // UEFI_LT((" | score = %u", score)); // Commented to avoid bad looking logs



    mScore     = score;
    mCompleted = true;



    return NgosStatus::OK;
}

u64 TestBase::getScore() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mScore;
}

bool TestBase::isCompleted() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mCompleted;
}
