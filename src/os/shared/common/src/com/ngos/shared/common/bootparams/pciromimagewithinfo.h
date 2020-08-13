#ifndef COM_NGOS_SHARED_COMMON_BOOTPARAMS_PCIROMIMAGEWITHINFO_H
#define COM_NGOS_SHARED_COMMON_BOOTPARAMS_PCIROMIMAGEWITHINFO_H



#include <com/ngos/shared/common/ngos/types.h>



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



#endif // COM_NGOS_SHARED_COMMON_BOOTPARAMS_PCIROMIMAGEWITHINFO_H
