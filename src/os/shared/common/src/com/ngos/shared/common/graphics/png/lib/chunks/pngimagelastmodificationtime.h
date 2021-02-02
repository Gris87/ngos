#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H



#include <com/ngos/shared/common/ngos/types.h>



struct PngImageLastModificationTime
{
    bad_uint16 year;
    bad_uint8  month;
    bad_uint8  day;
    bad_uint8  hour;
    bad_uint8  minute;
    bad_uint8  second;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H
