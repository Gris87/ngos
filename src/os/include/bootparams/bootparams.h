#ifndef BOOTPARAMS_BOOTPARAMS_H
#define BOOTPARAMS_BOOTPARAMS_H



#include <bootparams/bootparamsheader.h>
#include <bootparams/memorymapentry.h>
#include <bootparams/pciromimagewithinfo.h>
#include <bootparams/screeninfo.h>



struct BootParams
{
    BootParamsHeader     header;
    ScreenInfo           screenInfo;
    PciRomImageWithInfo *pciRomImages;
    MemoryMapEntry      *memoryMapEntries;
    u64                  memoryMapEntriesCount;
};



#endif // BOOTPARAMS_BOOTPARAMS_H
