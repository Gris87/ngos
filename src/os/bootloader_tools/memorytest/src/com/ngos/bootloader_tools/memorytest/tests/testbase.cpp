#include "testbase.h"

#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>



TestBase* memoryTests[(u64)TestType::MAXIMUM];



TestBase::TestBase(TestType type, uefi_ap_procedure procedure)
    : mProcedure(procedure)
    , mScore(0)
    , mAverageSpeed(0)
    , mRegionStart(0)
    , mRegionEnd(0)
    , mTestSize(0)
    , mProgress(0)
    , mHandledProgress(0)
    , mMaximumSpeed(0)
    , mStartTsc(0)
    , mIntermediateTsc(0)
{
    UEFI_LT((" | type = %u, procedure = 0x%p", type, procedure));

    UEFI_ASSERT(type      <  TestType::MAXIMUM, "type is invalid");
    UEFI_ASSERT(procedure != nullptr,           "procedure is null");



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

    UEFI_ASSERT(end                        >  start, "end is invalid",      NgosStatus::ASSERTION);
    UEFI_ASSERT(testSize                   >  0,     "testSize is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(testSize % TEST_BLOCK_SIZE == 0,     "testSize is invalid", NgosStatus::ASSERTION);



    mScore           = 0;
    mAverageSpeed    = 0;
    mRegionStart     = start;
    mRegionEnd       = end;
    mTestSize        = testSize;
    mProgress        = 0;
    mHandledProgress = 0;
    mMaximumSpeed    = 0;
    mStartTsc        = 0;
    mIntermediateTsc = 0;



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

NgosStatus TestBase::setAverageSpeed(u64 speed)
{
    // UEFI_LT((" | speed = %u", speed)); // Commented to avoid bad looking logs



    mAverageSpeed = speed;



    return NgosStatus::OK;
}

u64 TestBase::getAverageSpeed() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mAverageSpeed;
}

bool TestBase::isCompleted() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mScore != 0;
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

i64 TestBase::getTestSize() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mTestSize;
}

i64 TestBase::getProgress() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mProgress;
}

NgosStatus TestBase::setHandledProgress(i64 progress)
{
    // UEFI_LT((" | progress = %d", progress)); // Commented to avoid bad looking logs



    mHandledProgress = progress;



    return NgosStatus::OK;
}

i64 TestBase::getHandledProgress() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mHandledProgress;
}

NgosStatus TestBase::setMaximumSpeed(u64 speed)
{
    // UEFI_LT((" | speed = %u", speed)); // Commented to avoid bad looking logs



    mMaximumSpeed = speed;



    return NgosStatus::OK;
}

u64 TestBase::getMaximumSpeed() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mMaximumSpeed;
}

NgosStatus TestBase::setStartTsc(u64 tsc)
{
    // UEFI_LT((" | tsc = %u", tsc)); // Commented to avoid bad looking logs



    mStartTsc        = tsc;
    mIntermediateTsc = tsc;



    return NgosStatus::OK;
}

u64 TestBase::getStartTsc() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mStartTsc;
}

NgosStatus TestBase::setIntermediateTsc(u64 tsc)
{
    // UEFI_LT((" | tsc = %u", tsc)); // Commented to avoid bad looking logs



    mIntermediateTsc = tsc;



    return NgosStatus::OK;
}

u64 TestBase::getIntermediateTsc() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mIntermediateTsc;
}
