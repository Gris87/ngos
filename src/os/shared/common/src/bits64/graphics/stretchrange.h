#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_STRETCHRANGE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_STRETCHRANGE_H



#include <ngos/status.h>
#include <ngos/types.h>



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



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_STRETCHRANGE_H
