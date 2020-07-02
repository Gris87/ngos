#ifndef BOOTPARAMS_BOOTPARAMS_H
#define BOOTPARAMS_BOOTPARAMS_H



#include <bootparams/bootparamsheader.h>
#include <bootparams/memorymapentry.h>
#include <bootparams/pciromimagewithinfo.h>
#include <bootparams/uefiinfo.h>
#include <uefi/uefigraphicsoutputprotocol.h>



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



#endif // BOOTPARAMS_BOOTPARAMS_H
