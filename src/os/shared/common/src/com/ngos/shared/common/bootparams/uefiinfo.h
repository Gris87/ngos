#ifndef BOOTPARAMS_UEFIINFO_H
#define BOOTPARAMS_UEFIINFO_H



#include <bootparams/uefimemorymapinfo.h>
#include <uefi/uefisystemtable.h>



struct UefiInfo
{
    UefiMemoryMapInfo  memoryMap;
    UefiSystemTable   *systemTable;
};



#endif // BOOTPARAMS_UEFIINFO_H
