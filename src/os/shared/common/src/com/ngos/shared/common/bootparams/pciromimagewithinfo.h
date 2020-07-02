#ifndef BOOTPARAMS_PCIROMIMAGEWITHINFO_H
#define BOOTPARAMS_PCIROMIMAGEWITHINFO_H



#include <ngos/types.h>



struct PciRomImageWithInfo
{
    PciRomImageWithInfo *next;

    u16 vendorId;
    u16 deviceId;

    u64 segmentNumber;
    u64 busNumber;
    u64 deviceNumber;
    u64 functionNumber;

    u64 romSize;
    u8  romImage[0];
};



#endif // BOOTPARAMS_PCIROMIMAGEWITHINFO_H
