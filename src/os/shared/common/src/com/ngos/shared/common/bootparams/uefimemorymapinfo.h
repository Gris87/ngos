#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIMEMORYMAPINFO_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIMEMORYMAPINFO_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefimemorydescriptor.h>



struct UefiMemoryMapInfo
{
    UefiMemoryDescriptor *map;
    u64                   size;
    u64                   descriptorSize;
    u32                   descriptorVersion;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIMEMORYMAPINFO_H
