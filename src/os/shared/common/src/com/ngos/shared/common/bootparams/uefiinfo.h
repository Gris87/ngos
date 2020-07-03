#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIINFO_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIINFO_H



#include <common/src/com/ngos/shared/common/bootparams/uefimemorymapinfo.h>
#include <common/src/com/ngos/shared/common/uefi/uefisystemtable.h>



struct UefiInfo
{
    UefiMemoryMapInfo  memoryMap;
    UefiSystemTable   *systemTable;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_UEFIINFO_H
