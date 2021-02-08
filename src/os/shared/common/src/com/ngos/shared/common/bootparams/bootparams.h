#ifndef COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMS_H
#define COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMS_H



#include <com/ngos/shared/common/bootparams/bootparamsheader.h>
#include <com/ngos/shared/common/bootparams/memorymapentry.h>
#include <com/ngos/shared/common/bootparams/pciromimagewithinfo.h>
#include <com/ngos/shared/common/bootparams/uefiinfo.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h>



#define HARDWARE_ID_LENGTH 512



struct BootParams
{
    BootParamsHeader             header;
    UefiInfo                     uefi;
    u64                          screensCount;
    UefiGraphicsOutputProtocol **screens;
    PciRomImageWithInfo         *pciRomImages;
    i64                          memoryMapEntriesCount;
    MemoryMapEntry              *memoryMapEntries;
    char8                        hardwareId[HARDWARE_ID_LENGTH];
};



#endif // COM_NGOS_SHARED_COMMON_BOOTPARAMS_BOOTPARAMS_H
