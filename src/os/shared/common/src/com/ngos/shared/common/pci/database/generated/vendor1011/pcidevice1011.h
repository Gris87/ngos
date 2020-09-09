// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCIDEVICE1011_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCIDEVICE1011_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcisubdevice10110009.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcisubdevice1011000f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcisubdevice10110014.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcisubdevice10110019.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcisubdevice10110034.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcisubdevice10110046.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1011/pcisubdevice10111065.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1011: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0004 = 0x0004,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000D = 0x000D,
    DEVICE_000F = 0x000F,
    DEVICE_0014 = 0x0014,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_0018 = 0x0018,
    DEVICE_0019 = 0x0019,
    DEVICE_001A = 0x001A,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0024 = 0x0024,
    DEVICE_0025 = 0x0025,
    DEVICE_0026 = 0x0026,
    DEVICE_0034 = 0x0034,
    DEVICE_0045 = 0x0045,
    DEVICE_0046 = 0x0046,
    DEVICE_1065 = 0x1065
};



inline const char8* enumToString(PciDevice1011 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1011::NONE:        return "NONE";
        case PciDevice1011::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1011::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1011::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1011::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1011::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1011::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1011::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1011::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1011::DEVICE_000F: return "DEVICE_000F";
        case PciDevice1011::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1011::DEVICE_0016: return "DEVICE_0016";
        case PciDevice1011::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1011::DEVICE_0018: return "DEVICE_0018";
        case PciDevice1011::DEVICE_0019: return "DEVICE_0019";
        case PciDevice1011::DEVICE_001A: return "DEVICE_001A";
        case PciDevice1011::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1011::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1011::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1011::DEVICE_0024: return "DEVICE_0024";
        case PciDevice1011::DEVICE_0025: return "DEVICE_0025";
        case PciDevice1011::DEVICE_0026: return "DEVICE_0026";
        case PciDevice1011::DEVICE_0034: return "DEVICE_0034";
        case PciDevice1011::DEVICE_0045: return "DEVICE_0045";
        case PciDevice1011::DEVICE_0046: return "DEVICE_0046";
        case PciDevice1011::DEVICE_1065: return "DEVICE_1065";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1011 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1011 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1011::DEVICE_0001: return "DECchip 21050";
        case PciDevice1011::DEVICE_0002: return "DECchip 21040 [Tulip]";
        case PciDevice1011::DEVICE_0004: return "DECchip 21030 [TGA]";
        case PciDevice1011::DEVICE_0007: return "NVRAM [Zephyr NVRAM]";
        case PciDevice1011::DEVICE_0008: return "KZPSA [KZPSA]";
        case PciDevice1011::DEVICE_0009: return "DECchip 21140 [FasterNet]";
        case PciDevice1011::DEVICE_000A: return "21230 Video Codec";
        case PciDevice1011::DEVICE_000D: return "PBXGB [TGA2]";
        case PciDevice1011::DEVICE_000F: return "DEFPA FDDI PCI-to-PDQ Interface Chip [PFI]";
        case PciDevice1011::DEVICE_0014: return "DECchip 21041 [Tulip Pass 3]";
        case PciDevice1011::DEVICE_0016: return "DGLPB [OPPO]";
        case PciDevice1011::DEVICE_0017: return "PV-PCI Graphics Controller (ZLXp-L)";
        case PciDevice1011::DEVICE_0018: return "Memory Channel interface";
        case PciDevice1011::DEVICE_0019: return "DECchip 21142/43";
        case PciDevice1011::DEVICE_001A: return "Farallon PN9000SX Gigabit Ethernet";
        case PciDevice1011::DEVICE_0021: return "DECchip 21052";
        case PciDevice1011::DEVICE_0022: return "DECchip 21150";
        case PciDevice1011::DEVICE_0023: return "DECchip 21150";
        case PciDevice1011::DEVICE_0024: return "DECchip 21152";
        case PciDevice1011::DEVICE_0025: return "DECchip 21153";
        case PciDevice1011::DEVICE_0026: return "DECchip 21154";
        case PciDevice1011::DEVICE_0034: return "56k Modem Cardbus";
        case PciDevice1011::DEVICE_0045: return "DECchip 21553";
        case PciDevice1011::DEVICE_0046: return "DECchip 21554";
        case PciDevice1011::DEVICE_1065: return "StrongARM DC21285";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1011 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1011::DEVICE_0001: return "Unknown device";
        case PciDevice1011::DEVICE_0002: return "Unknown device";
        case PciDevice1011::DEVICE_0004: return "Unknown device";
        case PciDevice1011::DEVICE_0007: return "Unknown device";
        case PciDevice1011::DEVICE_0008: return "Unknown device";
        case PciDevice1011::DEVICE_0009: return enumToHumanString((PciSubDevice10110009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1011::DEVICE_000A: return "Unknown device";
        case PciDevice1011::DEVICE_000D: return "Unknown device";
        case PciDevice1011::DEVICE_000F: return enumToHumanString((PciSubDevice1011000F)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1011::DEVICE_0014: return enumToHumanString((PciSubDevice10110014)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1011::DEVICE_0016: return "Unknown device";
        case PciDevice1011::DEVICE_0017: return "Unknown device";
        case PciDevice1011::DEVICE_0018: return "Unknown device";
        case PciDevice1011::DEVICE_0019: return enumToHumanString((PciSubDevice10110019)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1011::DEVICE_001A: return "Unknown device";
        case PciDevice1011::DEVICE_0021: return "Unknown device";
        case PciDevice1011::DEVICE_0022: return "Unknown device";
        case PciDevice1011::DEVICE_0023: return "Unknown device";
        case PciDevice1011::DEVICE_0024: return "Unknown device";
        case PciDevice1011::DEVICE_0025: return "Unknown device";
        case PciDevice1011::DEVICE_0026: return "Unknown device";
        case PciDevice1011::DEVICE_0034: return enumToHumanString((PciSubDevice10110034)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1011::DEVICE_0045: return "Unknown device";
        case PciDevice1011::DEVICE_0046: return enumToHumanString((PciSubDevice10110046)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1011::DEVICE_1065: return enumToHumanString((PciSubDevice10111065)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCIDEVICE1011_H
