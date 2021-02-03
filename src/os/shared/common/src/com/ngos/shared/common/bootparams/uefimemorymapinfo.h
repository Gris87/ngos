#ifndef COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIMEMORYMAPINFO_H
#define COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIMEMORYMAPINFO_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefimemorydescriptor.h>



struct UefiMemoryMapInfo
{
    UefiMemoryDescriptor *map;
    u64                   size;
    u64                   descriptorSize;
    u32                   descriptorVersion;
};



#endif // COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIMEMORYMAPINFO_H
