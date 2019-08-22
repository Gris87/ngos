#include "ninepatch.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



NinePatch::NinePatch()
    : mStretchRangesX()
    , mStretchRangesY()
    , mPaddingLeft(0)
    , mPaddingTop(0)
    , mPaddingRight(0)
    , mPaddingBottom(0)
{
    COMMON_LT((""));
}

NinePatch::~NinePatch()
{
    COMMON_LT((""));
}

NgosStatus NinePatch::addStretchRangeX(const StretchRange &range)
{
    COMMON_LT((" | range = ..."));



    COMMON_TEST_ASSERT(!mStretchRangesX.mTail || mStretchRangesX.mTail->getData().getTo() < range.getFrom(), NgosStatus::ASSERTION);

    mStretchRangesX.append(range);



    return NgosStatus::OK;
}

NgosStatus NinePatch::addStretchRangeY(const StretchRange &range)
{
    COMMON_LT((" | range = ..."));



    COMMON_TEST_ASSERT(!mStretchRangesY.mTail || mStretchRangesY.mTail->getData().getTo() < range.getFrom(), NgosStatus::ASSERTION);

    mStretchRangesY.append(range);



    return NgosStatus::OK;
}

const List<StretchRange>& NinePatch::getStretchRangesX() const
{
    COMMON_LT((""));



    return mStretchRangesX;
}

const List<StretchRange>& NinePatch::getStretchRangesY() const
{
    COMMON_LT((""));



    return mStretchRangesY;
}

NgosStatus NinePatch::setPaddingLeft(u16 padding)
{
    COMMON_LT((" | padding = %u", padding));



    mPaddingLeft = padding;



    return NgosStatus::OK;
}

NgosStatus NinePatch::setPaddingTop(u16 padding)
{
    COMMON_LT((" | padding = %u", padding));



    mPaddingTop = padding;



    return NgosStatus::OK;
}

NgosStatus NinePatch::setPaddingRight(u16 padding)
{
    COMMON_LT((" | padding = %u", padding));



    mPaddingRight = padding;



    return NgosStatus::OK;
}

NgosStatus NinePatch::setPaddingBottom(u16 padding)
{
    COMMON_LT((" | padding = %u", padding));



    mPaddingBottom = padding;



    return NgosStatus::OK;
}

u16 NinePatch::getPaddingLeft() const
{
    COMMON_LT((""));



    return mPaddingLeft;
}

u16 NinePatch::getPaddingTop() const
{
    COMMON_LT((""));



    return mPaddingTop;
}

u16 NinePatch::getPaddingRight() const
{
    COMMON_LT((""));



    return mPaddingRight;
}

u16 NinePatch::getPaddingBottom() const
{
    COMMON_LT((""));



    return mPaddingBottom;
}
