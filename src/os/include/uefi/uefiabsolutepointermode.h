#ifndef UEFI_UEFIABSOLUTEPOINTERMODE_H
#define UEFI_UEFIABSOLUTEPOINTERMODE_H



#include <ngos/types.h>
#include <uefi/uefiabsolutepointermodeattributeflags.h>



struct UefiAbsolutePointerMode
{
    u64                                        absoluteMinX;
    u64                                        absoluteMinY;
    u64                                        absoluteMinZ;
    u64                                        absoluteMaxX;
    u64                                        absoluteMaxY;
    u64                                        absoluteMaxZ;
    uefi_absolute_pointer_mode_attribute_flags attributes;
};



#endif // UEFI_UEFIABSOLUTEPOINTERMODE_H
