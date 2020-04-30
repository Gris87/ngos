#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsbiosreservedflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibioscharacteristicssystemreservedflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibiosextendedromsize.h>
#include <common/src/bits64/dmi/entry/lib/dmibiosromsize.h>



#define DMI_BIOS_BIOS_ROM_SIZE_NEED_TO_EXTEND                             0xFF
#define DMI_BIOS_SYSTEM_BIOS_MAJOR_RELEASE_NOT_AVAILABLE                  0xFF
#define DMI_BIOS_SYSTEM_BIOS_MINOR_RELEASE_NOT_AVAILABLE                  0xFF
#define DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MAJOR_RELEASE_NOT_AVAILABLE 0xFF
#define DMI_BIOS_EMBEDDED_CONTROLLER_FIRMWARE_MINOR_RELEASE_NOT_AVAILABLE 0xFF



struct DmiBiosEntry
{
    DmiEntryHeader              header;
    DmiStringId                 vendor;
    DmiStringId                 biosVersion;
    u16                         biosStartingAddressSegment;
    DmiStringId                 biosReleaseDate;
    DmiBiosRomSize              biosRomSize;
    DmiBiosCharacteristicsFlags biosCharacteristics;
} __attribute__((packed));



struct DmiBiosEntryV21: public DmiBiosEntry
{
    DmiBiosCharacteristicsBiosReservedFlags biosCharacteristicsExtensionBiosReserved;
} __attribute__((packed));



struct DmiBiosEntryV23: public DmiBiosEntryV21
{
    DmiBiosCharacteristicsSystemReservedFlags biosCharacteristicsExtensionSystemReserved;
} __attribute__((packed));



struct DmiBiosEntryV24: public DmiBiosEntryV23
{
    u8 systemBiosMajorRelease;
    u8 systemBiosMinorRelease;
    u8 embeddedControllerFirmwareMajorRelease;
    u8 embeddedControllerFirmwareMinorRelease;
} __attribute__((packed));



struct DmiBiosEntryV31: public DmiBiosEntryV24
{
    DmiBiosExtendedRomSize extendedBiosRomSize;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
