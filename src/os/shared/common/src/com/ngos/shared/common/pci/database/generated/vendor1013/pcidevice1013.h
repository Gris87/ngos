// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCIDEVICE1013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCIDEVICE1013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1013/pcisubdevice101300b8.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1013/pcisubdevice101300bc.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1013/pcisubdevice101300d6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1013/pcisubdevice10136001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1013/pcisubdevice10136003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1013/pcisubdevice10136005.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1013: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0038 = 0x0038,
    DEVICE_0040 = 0x0040,
    DEVICE_004C = 0x004C,
    DEVICE_00A0 = 0x00A0,
    DEVICE_00A2 = 0x00A2,
    DEVICE_00A4 = 0x00A4,
    DEVICE_00A8 = 0x00A8,
    DEVICE_00AC = 0x00AC,
    DEVICE_00B0 = 0x00B0,
    DEVICE_00B8 = 0x00B8,
    DEVICE_00BC = 0x00BC,
    DEVICE_00D0 = 0x00D0,
    DEVICE_00D2 = 0x00D2,
    DEVICE_00D4 = 0x00D4,
    DEVICE_00D5 = 0x00D5,
    DEVICE_00D6 = 0x00D6,
    DEVICE_00E8 = 0x00E8,
    DEVICE_1100 = 0x1100,
    DEVICE_1110 = 0x1110,
    DEVICE_1112 = 0x1112,
    DEVICE_1113 = 0x1113,
    DEVICE_1200 = 0x1200,
    DEVICE_1202 = 0x1202,
    DEVICE_1204 = 0x1204,
    DEVICE_4000 = 0x4000,
    DEVICE_4400 = 0x4400,
    DEVICE_6001 = 0x6001,
    DEVICE_6003 = 0x6003,
    DEVICE_6004 = 0x6004,
    DEVICE_6005 = 0x6005
};



inline const char8* enumToString(PciDevice1013 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1013::NONE:        return "NONE";
        case PciDevice1013::DEVICE_0038: return "DEVICE_0038";
        case PciDevice1013::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1013::DEVICE_004C: return "DEVICE_004C";
        case PciDevice1013::DEVICE_00A0: return "DEVICE_00A0";
        case PciDevice1013::DEVICE_00A2: return "DEVICE_00A2";
        case PciDevice1013::DEVICE_00A4: return "DEVICE_00A4";
        case PciDevice1013::DEVICE_00A8: return "DEVICE_00A8";
        case PciDevice1013::DEVICE_00AC: return "DEVICE_00AC";
        case PciDevice1013::DEVICE_00B0: return "DEVICE_00B0";
        case PciDevice1013::DEVICE_00B8: return "DEVICE_00B8";
        case PciDevice1013::DEVICE_00BC: return "DEVICE_00BC";
        case PciDevice1013::DEVICE_00D0: return "DEVICE_00D0";
        case PciDevice1013::DEVICE_00D2: return "DEVICE_00D2";
        case PciDevice1013::DEVICE_00D4: return "DEVICE_00D4";
        case PciDevice1013::DEVICE_00D5: return "DEVICE_00D5";
        case PciDevice1013::DEVICE_00D6: return "DEVICE_00D6";
        case PciDevice1013::DEVICE_00E8: return "DEVICE_00E8";
        case PciDevice1013::DEVICE_1100: return "DEVICE_1100";
        case PciDevice1013::DEVICE_1110: return "DEVICE_1110";
        case PciDevice1013::DEVICE_1112: return "DEVICE_1112";
        case PciDevice1013::DEVICE_1113: return "DEVICE_1113";
        case PciDevice1013::DEVICE_1200: return "DEVICE_1200";
        case PciDevice1013::DEVICE_1202: return "DEVICE_1202";
        case PciDevice1013::DEVICE_1204: return "DEVICE_1204";
        case PciDevice1013::DEVICE_4000: return "DEVICE_4000";
        case PciDevice1013::DEVICE_4400: return "DEVICE_4400";
        case PciDevice1013::DEVICE_6001: return "DEVICE_6001";
        case PciDevice1013::DEVICE_6003: return "DEVICE_6003";
        case PciDevice1013::DEVICE_6004: return "DEVICE_6004";
        case PciDevice1013::DEVICE_6005: return "DEVICE_6005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1013 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1013 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1013::DEVICE_0038: return "GD 7548";
        case PciDevice1013::DEVICE_0040: return "GD 7555 Flat Panel GUI Accelerator";
        case PciDevice1013::DEVICE_004C: return "GD 7556 Video/Graphics LCD/CRT Ctrlr";
        case PciDevice1013::DEVICE_00A0: return "GD 5430/40 [Alpine]";
        case PciDevice1013::DEVICE_00A2: return "GD 5432 [Alpine]";
        case PciDevice1013::DEVICE_00A4: return "GD 5434-4 [Alpine]";
        case PciDevice1013::DEVICE_00A8: return "GD 5434-8 [Alpine]";
        case PciDevice1013::DEVICE_00AC: return "GD 5436 [Alpine]";
        case PciDevice1013::DEVICE_00B0: return "GD 5440";
        case PciDevice1013::DEVICE_00B8: return "GD 5446";
        case PciDevice1013::DEVICE_00BC: return "GD 5480";
        case PciDevice1013::DEVICE_00D0: return "GD 5462";
        case PciDevice1013::DEVICE_00D2: return "GD 5462 [Laguna I]";
        case PciDevice1013::DEVICE_00D4: return "GD 5464 [Laguna]";
        case PciDevice1013::DEVICE_00D5: return "GD 5464 BD [Laguna]";
        case PciDevice1013::DEVICE_00D6: return "GD 5465 [Laguna]";
        case PciDevice1013::DEVICE_00E8: return "GD 5436U";
        case PciDevice1013::DEVICE_1100: return "CL 6729";
        case PciDevice1013::DEVICE_1110: return "PD 6832 PCMCIA/CardBus Ctrlr";
        case PciDevice1013::DEVICE_1112: return "PD 6834 PCMCIA/CardBus Ctrlr";
        case PciDevice1013::DEVICE_1113: return "PD 6833 PCMCIA/CardBus Ctrlr";
        case PciDevice1013::DEVICE_1200: return "GD 7542 [Nordic]";
        case PciDevice1013::DEVICE_1202: return "GD 7543 [Viking]";
        case PciDevice1013::DEVICE_1204: return "GD 7541 [Nordic Light]";
        case PciDevice1013::DEVICE_4000: return "MD 5620 [CLM Data Fax Voice]";
        case PciDevice1013::DEVICE_4400: return "CD 4400";
        case PciDevice1013::DEVICE_6001: return "CS 4610/11 [CrystalClear SoundFusion Audio Accelerator]";
        case PciDevice1013::DEVICE_6003: return "CS 4614/22/24/30 [CrystalClear SoundFusion Audio Accelerator]";
        case PciDevice1013::DEVICE_6004: return "CS 4614/22/24 [CrystalClear SoundFusion Audio Accelerator]";
        case PciDevice1013::DEVICE_6005: return "Crystal CS4281 PCI Audio";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1013 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1013::DEVICE_0038: return "Unknown device";
        case PciDevice1013::DEVICE_0040: return "Unknown device";
        case PciDevice1013::DEVICE_004C: return "Unknown device";
        case PciDevice1013::DEVICE_00A0: return "Unknown device";
        case PciDevice1013::DEVICE_00A2: return "Unknown device";
        case PciDevice1013::DEVICE_00A4: return "Unknown device";
        case PciDevice1013::DEVICE_00A8: return "Unknown device";
        case PciDevice1013::DEVICE_00AC: return "Unknown device";
        case PciDevice1013::DEVICE_00B0: return "Unknown device";
        case PciDevice1013::DEVICE_00B8: return enumToHumanString((PciSubDevice101300B8)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1013::DEVICE_00BC: return enumToHumanString((PciSubDevice101300BC)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1013::DEVICE_00D0: return "Unknown device";
        case PciDevice1013::DEVICE_00D2: return "Unknown device";
        case PciDevice1013::DEVICE_00D4: return "Unknown device";
        case PciDevice1013::DEVICE_00D5: return "Unknown device";
        case PciDevice1013::DEVICE_00D6: return enumToHumanString((PciSubDevice101300D6)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1013::DEVICE_00E8: return "Unknown device";
        case PciDevice1013::DEVICE_1100: return "Unknown device";
        case PciDevice1013::DEVICE_1110: return "Unknown device";
        case PciDevice1013::DEVICE_1112: return "Unknown device";
        case PciDevice1013::DEVICE_1113: return "Unknown device";
        case PciDevice1013::DEVICE_1200: return "Unknown device";
        case PciDevice1013::DEVICE_1202: return "Unknown device";
        case PciDevice1013::DEVICE_1204: return "Unknown device";
        case PciDevice1013::DEVICE_4000: return "Unknown device";
        case PciDevice1013::DEVICE_4400: return "Unknown device";
        case PciDevice1013::DEVICE_6001: return enumToHumanString((PciSubDevice10136001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1013::DEVICE_6003: return enumToHumanString((PciSubDevice10136003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1013::DEVICE_6004: return "Unknown device";
        case PciDevice1013::DEVICE_6005: return enumToHumanString((PciSubDevice10136005)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCIDEVICE1013_H
