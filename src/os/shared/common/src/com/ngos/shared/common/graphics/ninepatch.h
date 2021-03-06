#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_NINEPATCH_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_NINEPATCH_H



#include <com/ngos/shared/common/containers/list.h>
#include <com/ngos/shared/common/graphics/stretchrange.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



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



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_NINEPATCH_H
