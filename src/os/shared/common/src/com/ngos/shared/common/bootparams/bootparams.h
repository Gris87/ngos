#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMS_H



#include <common/src/com/ngos/shared/common/bootparams/bootparamsheader.h>
#include <common/src/com/ngos/shared/common/bootparams/memorymapentry.h>
#include <common/src/com/ngos/shared/common/bootparams/pciromimagewithinfo.h>
#include <common/src/com/ngos/shared/common/bootparams/uefiinfo.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h>



#define HARDWARE_ID_LENGTH 512



struct BootParams
{
    BootParamsHeader             header;
    UefiInfo                     uefi;
    u64                          screensCount;
    UefiGraphicsOutputProtocol **screens;
    PciRomImageWithInfo         *pciRomImages;
    u64                          memoryMapEntriesCount;
    MemoryMapEntry              *memoryMapEntries;
    char8                        hardwareId[HARDWARE_ID_LENGTH];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMS_H
