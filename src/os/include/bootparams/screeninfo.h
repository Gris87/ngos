#ifndef BOOTPARAMS_SCREENINFO_H
#define BOOTPARAMS_SCREENINFO_H



#include <ngos/types.h>



struct ScreenInfo
{
    u64 frameBufferBase;
    u64 frameBufferSize;
    u16 stride;

    u16 width;
    u16 height;
    u8  depth;

    u8  redOffset;
    u8  greenOffset;
    u8  blueOffset;
    u8  reservedOffset;
    u8  redSize;
    u8  greenSize;
    u8  blueSize;
    u8  reservedSize;
};



#endif // BOOTPARAMS_SCREENINFO_H
