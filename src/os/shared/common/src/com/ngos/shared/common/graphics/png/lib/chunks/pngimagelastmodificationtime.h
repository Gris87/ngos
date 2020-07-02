#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct PngImageLastModificationTime
{
    u16 year;
    u8  month;
    u8  day;
    u8  hour;
    u8  minute;
    u8  second;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGELASTMODIFICATIONTIME_H
