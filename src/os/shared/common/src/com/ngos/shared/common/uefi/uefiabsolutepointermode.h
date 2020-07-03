#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointermodeattributeflags.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERMODE_H
