#include "testbase.h"

#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



TestBase* memoryTests[(bad_uint64)TestType::MAXIMUM];



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



    UEFI_TEST_ASSERT(memoryTests[(bad_uint64)type] == nullptr);



    memoryTests[(bad_uint64)type] = this;
}

TestBase::~TestBase()
{
    UEFI_LT((""));
}

NgosStatus TestBase::reset(bad_uint64 start, bad_uint64 end, bad_int64 testSize)
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

NgosStatus TestBase::setScore(bad_uint64 score)
{
    // UEFI_LT((" | score = %u", score)); // Commented to avoid bad looking logs



    mScore = score;



    return NgosStatus::OK;
}

bad_uint64 TestBase::getScore() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mScore;
}

NgosStatus TestBase::setAverageSpeed(bad_uint64 speed)
{
    // UEFI_LT((" | speed = %u", speed)); // Commented to avoid bad looking logs



    mAverageSpeed = speed;



    return NgosStatus::OK;
}

bad_uint64 TestBase::getAverageSpeed() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mAverageSpeed;
}

bool TestBase::isCompleted() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mScore != 0;
}

bad_uint64 TestBase::getRegionStart() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mRegionStart;
}

bad_uint64 TestBase::getRegionEnd() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mRegionEnd;
}

bad_int64 TestBase::getTestSize() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mTestSize;
}

bad_int64 TestBase::getProgress() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mProgress;
}

NgosStatus TestBase::setHandledProgress(bad_int64 progress)
{
    // UEFI_LT((" | progress = %d", progress)); // Commented to avoid bad looking logs



    mHandledProgress = progress;



    return NgosStatus::OK;
}

bad_int64 TestBase::getHandledProgress() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mHandledProgress;
}

NgosStatus TestBase::setMaximumSpeed(bad_uint64 speed)
{
    // UEFI_LT((" | speed = %u", speed)); // Commented to avoid bad looking logs



    mMaximumSpeed = speed;



    return NgosStatus::OK;
}

bad_uint64 TestBase::getMaximumSpeed() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mMaximumSpeed;
}

NgosStatus TestBase::setStartTsc(bad_uint64 tsc)
{
    // UEFI_LT((" | tsc = %u", tsc)); // Commented to avoid bad looking logs



    mStartTsc        = tsc;
    mIntermediateTsc = tsc;



    return NgosStatus::OK;
}

bad_uint64 TestBase::getStartTsc() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mStartTsc;
}

NgosStatus TestBase::setIntermediateTsc(bad_uint64 tsc)
{
    // UEFI_LT((" | tsc = %u", tsc)); // Commented to avoid bad looking logs



    mIntermediateTsc = tsc;



    return NgosStatus::OK;
}

bad_uint64 TestBase::getIntermediateTsc() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mIntermediateTsc;
}
