#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsextension.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsize.h>
#include <macro/constants.h>



struct DmiBiosEntry
{
    u64 romSize()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (biosRomSize + 1) * 64 * KB;
    }



    DmiEntryHeader                  header;
    u8                              vendorStringId;
    u8                              biosVersionStringId;
    u16                             biosStartingAddressSegment;
    u8                              biosReleaseDateStringId;
    u8                              biosRomSize;
    DmiBiosCharacteristicsFlags     biosCharacteristics;
    DmiBiosCharacteristicsExtension biosCharacteristicsExtension;
    u8                              systemBiosMajorRelease;
    u8                              systemBiosMinorRelease;
    u8                              embeddedControllerFirmwareMajorRelease;
    u8                              embeddedControllerFirmwareMinorRelease;
    DmiBiosExtendedRomSize          extendedBiosRomSize;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
