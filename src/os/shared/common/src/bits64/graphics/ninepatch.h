#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_NINEPATCH_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_NINEPATCH_H



#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/stretchrange.h>
#include <ngos/status.h>
#include <ngos/types.h>



class NinePatch
{
public:
    NinePatch();
    NinePatch(const NinePatch &patch);
    ~NinePatch(); // TEST: NO

    NgosStatus addStretchRangeX(const StretchRange &range);
    NgosStatus addStretchRangeY(const StretchRange &range);

    NgosStatus setPaddingLeft(u16 padding);
    NgosStatus setPaddingTop(u16 padding);
    NgosStatus setPaddingRight(u16 padding);
    NgosStatus setPaddingBottom(u16 padding);

    const List<StretchRange>& getStretchRangesX() const;
    const List<StretchRange>& getStretchRangesY() const;

    u16 getPaddingLeft() const;
    u16 getPaddingTop() const;
    u16 getPaddingRight() const;
    u16 getPaddingBottom() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    List<StretchRange> mStretchRangesX;
    List<StretchRange> mStretchRangesY;
    u16                mPaddingLeft;
    u16                mPaddingTop;
    u16                mPaddingRight;
    u16                mPaddingBottom;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_NINEPATCH_H
