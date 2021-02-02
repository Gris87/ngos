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

    NgosStatus setPaddingLeft(bad_uint16 padding);
    NgosStatus setPaddingTop(bad_uint16 padding);
    NgosStatus setPaddingRight(bad_uint16 padding);
    NgosStatus setPaddingBottom(bad_uint16 padding);

    const List<StretchRange>& getStretchRangesX() const;
    const List<StretchRange>& getStretchRangesY() const;

    bad_uint16 getPaddingLeft() const;
    bad_uint16 getPaddingTop() const;
    bad_uint16 getPaddingRight() const;
    bad_uint16 getPaddingBottom() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    List<StretchRange> mStretchRangesX;
    List<StretchRange> mStretchRangesY;
    bad_uint16                mPaddingLeft;
    bad_uint16                mPaddingTop;
    bad_uint16                mPaddingRight;
    bad_uint16                mPaddingBottom;
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_NINEPATCH_H
