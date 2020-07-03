#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H



#include <common/src/com/ngos/shared/common/ngos/status.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



class StretchRange
{
public:
    StretchRange(u16 from, u16 to);
    ~StretchRange(); // TEST: NO

    u16 getSize() const;

    u16 getFrom() const;
    u16 getTo() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    u16 mFrom;
    u16 mTo;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H
