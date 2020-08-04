#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H



#include <com/ngos/shared/common/ngos/types.h>



struct PngImageLastModificationTime
{
    u16 year;
    u8  month;
    u8  day;
    u8  hour;
    u8  minute;
    u8  second;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H
