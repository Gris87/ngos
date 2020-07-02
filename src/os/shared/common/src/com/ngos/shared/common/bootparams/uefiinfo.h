#ifndef BOOTPARAMS_UEFIINFO_H
#define BOOTPARAMS_UEFIINFO_H



#include <common/src/com/ngos/shared/common/bootparams/uefimemorymapinfo.h>
#include <common/src/com/ngos/shared/common/uefi/uefisystemtable.h>



struct UefiInfo
{
    UefiMemoryMapInfo  memoryMap;
    UefiSystemTable   *systemTable;
};



#endif // BOOTPARAMS_UEFIINFO_H
