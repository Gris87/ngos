#ifndef BOOTPARAMS_BOOTPARAMS_H
#define BOOTPARAMS_BOOTPARAMS_H



#include <bootparams/bootparamsheader.h>
#include <bootparams/memorymapentry.h>
#include <bootparams/pciromimagewithinfo.h>
#include <bootparams/uefiinfo.h>
#include <uefi/uefigraphicsoutputprotocol.h>



struct BootParams
{
    BootParamsHeader             header;
    UefiInfo                     uefi;
    u64                          screensCount;
    UefiGraphicsOutputProtocol **screens;
    PciRomImageWithInfo         *pciRomImages;
    u64                          memoryMapEntriesCount;
    MemoryMapEntry              *memoryMapEntries;
};



#endif // BOOTPARAMS_BOOTPARAMS_H
