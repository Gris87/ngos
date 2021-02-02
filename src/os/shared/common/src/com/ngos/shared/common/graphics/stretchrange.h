#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



class StretchRange
{
public:
    StretchRange(bad_uint16 from, bad_uint16 to);
    ~StretchRange(); // TEST: NO

    bad_uint16 getSize() const;

    bad_uint16 getFrom() const;
    bad_uint16 getTo() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    bad_uint16 mFrom;
    bad_uint16 mTo;
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H
