#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicsbiosreservedflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicsflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibioscharacteristicssystemreservedflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibiosextendedromsize.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibiosromsize.h>



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
    bad_uint16                         biosStartingAddressSegment;
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
    bad_uint8 systemBiosMajorRelease;
    bad_uint8 systemBiosMinorRelease;
    bad_uint8 embeddedControllerFirmwareMajorRelease;
    bad_uint8 embeddedControllerFirmwareMinorRelease;
} __attribute__((packed));



struct DmiBiosEntryV31: public DmiBiosEntryV24
{
    DmiBiosExtendedRomSize extendedBiosRomSize;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBIOSENTRY_H
