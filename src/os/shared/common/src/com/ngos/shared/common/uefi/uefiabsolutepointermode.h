#ifndef UEFI_UEFIABSOLUTEPOINTERMODE_H
#define UEFI_UEFIABSOLUTEPOINTERMODE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointermodeattributeflags.h>



struct UefiAbsolutePointerMode
{
    u64                                   absoluteMinX;
    u64                                   absoluteMinY;
    u64                                   absoluteMinZ;
    u64                                   absoluteMaxX;
    u64                                   absoluteMaxY;
    u64                                   absoluteMaxZ;
    UefiAbsolutePointerModeAttributeFlags attributes;
};



#endif // UEFI_UEFIABSOLUTEPOINTERMODE_H
