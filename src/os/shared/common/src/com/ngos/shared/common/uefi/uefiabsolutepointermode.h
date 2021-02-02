#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointermodeattributeflags.h>



struct UefiAbsolutePointerMode
{
    bad_uint64                                   absoluteMinX;
    bad_uint64                                   absoluteMinY;
    bad_uint64                                   absoluteMinZ;
    bad_uint64                                   absoluteMaxX;
    bad_uint64                                   absoluteMaxY;
    bad_uint64                                   absoluteMaxZ;
    UefiAbsolutePointerModeAttributeFlags attributes;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODE_H
