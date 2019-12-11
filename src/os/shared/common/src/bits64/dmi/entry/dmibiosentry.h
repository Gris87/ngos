#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsextension.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsize.h>



struct DmiBiosEntry
{
    DmiEntryHeader                  header;
    u8                              vendorStringId;
    u8                              biosVersionStringId;
    u16                             biosSegment;
    u8                              biosReleaseDateStringId;
    u8                              biosSize;
    DmiBiosCharacteristicsFlags     biosCharacteristics;
    DmiBiosCharacteristicsExtension biosCharacteristicsExtension;
    u8                              systemBiosMajorRelease;
    u8                              systemBiosMinorRelease;
    u8                              embeddedControllerFirmwareMajorRelease;
    u8                              embeddedControllerFirmwareMinorRelease;
    DmiBiosExtendedRomSize          extendedBiosSize;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
