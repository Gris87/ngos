#ifndef BOOTPARAMS_BOOTPARAMS_H
#define BOOTPARAMS_BOOTPARAMS_H



#include <bootparams/bootparamsheader.h>
#include <bootparams/memorymapentry.h>
#include <bootparams/pciromimagewithinfo.h>
#include <bootparams/screeninfo.h>
#include <bootparams/uefiinfo.h>



struct BootParams
{
    BootParamsHeader     header;
    ScreenInfo           screenInfo;
    PciRomImageWithInfo *pciRomImages;
    UefiInfo             uefi;
    u64                  memoryMapEntriesCount;
    MemoryMapEntry      *memoryMapEntries;
};



#endif // BOOTPARAMS_BOOTPARAMS_H
