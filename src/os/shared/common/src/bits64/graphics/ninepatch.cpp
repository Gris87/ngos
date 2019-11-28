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

NinePatch::NinePatch(const NinePatch &patch)
    : mStretchRangesX()
    , mStretchRangesY()
    , mPaddingLeft(patch.mPaddingLeft)
    , mPaddingTop(patch.mPaddingTop)
    , mPaddingRight(patch.mPaddingRight)
    , mPaddingBottom(patch.mPaddingBottom)
{
    COMMON_LT((" | patch = ..."));



    ListElement<StretchRange> *element = patch.mStretchRangesX.getHead();

    while (element)
    {
        mStretchRangesX.append(element->getData());

        element = element->getNext();
    }



    element = patch.mStretchRangesY.getHead();

    while (element)
    {
        mStretchRangesY.append(element->getData());

        element = element->getNext();
    }
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

const List<StretchRange>& NinePatch::getStretchRangesX() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mStretchRangesX;
}

const List<StretchRange>& NinePatch::getStretchRangesY() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mStretchRangesY;
}

u16 NinePatch::getPaddingLeft() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPaddingLeft;
}

u16 NinePatch::getPaddingTop() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPaddingTop;
}

u16 NinePatch::getPaddingRight() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPaddingRight;
}

u16 NinePatch::getPaddingBottom() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPaddingBottom;
}
