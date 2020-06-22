#include "testbase.h"

#include <macro/constants.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



TestBase* memoryTests[(u64)MemoryTestType::MAXIMUM];



TestBase::TestBase(MemoryTestType type, uefi_ap_procedure procedure)
    : mProcedure(procedure)
    , mScore(0)
    , mRegionStart(0)
    , mRegionEnd(0)
    , mTestSize(0)
{
    UEFI_LT((" | type = %u, procedure = 0x%p", type, procedure));

    UEFI_ASSERT(type < MemoryTestType::MAXIMUM, "type is invalid");
    UEFI_ASSERT(procedure,                      "procedure is null");



    UEFI_TEST_ASSERT(memoryTests[(u64)type] == nullptr);



    memoryTests[(u64)type] = this;
}

TestBase::~TestBase()
{
    UEFI_LT((""));
}

NgosStatus TestBase::reset(u64 start, u64 end, i64 testSize)
{
    UEFI_LT((" | start = %u, end = %u, testSize = %u", start, end, testSize));

    UEFI_ASSERT(end           >  start, "end is invalid",      NgosStatus::ASSERTION);
    UEFI_ASSERT(testSize      >  0,     "testSize is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(testSize % MB == 0,     "testSize is invalid", NgosStatus::ASSERTION);



    mScore       = 0;
    mRegionStart = start;
    mRegionEnd   = end;
    mTestSize    = testSize;



    return NgosStatus::OK;
}

uefi_ap_procedure TestBase::getProcedure() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mProcedure;
}

NgosStatus TestBase::setScore(u64 score)
{
    // UEFI_LT((" | score = %u", score)); // Commented to avoid bad looking logs



    mScore = score;



    return NgosStatus::OK;
}

u64 TestBase::getScore() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mScore;
}

u64 TestBase::getRegionStart() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mRegionStart;
}

u64 TestBase::getRegionEnd() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mRegionEnd;
}

u64 TestBase::getTestSize() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mTestSize;
}

bool TestBase::isCompleted() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mScore != 0;
}
