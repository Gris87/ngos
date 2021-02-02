// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCIDEVICE1004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCIDEVICE1004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1004/pcisubdevice10040304.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1004/pcisubdevice10040305.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1004/pcisubdevice10040306.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1004/pcisubdevice10040307.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1004: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_0104 = 0x0104,
    DEVICE_0105 = 0x0105,
    DEVICE_0200 = 0x0200,
    DEVICE_0280 = 0x0280,
    DEVICE_0304 = 0x0304,
    DEVICE_0305 = 0x0305,
    DEVICE_0306 = 0x0306,
    DEVICE_0307 = 0x0307,
    DEVICE_0308 = 0x0308,
    DEVICE_0702 = 0x0702,
    DEVICE_0703 = 0x0703
};



inline const char8* enumToString(PciDevice1004 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1004::NONE:        return "NONE";
        case PciDevice1004::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1004::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1004::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1004::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1004::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1004::DEVICE_000C: return "DEVICE_000C";
        case PciDevice1004::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1004::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1004::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1004::DEVICE_0103: return "DEVICE_0103";
        case PciDevice1004::DEVICE_0104: return "DEVICE_0104";
        case PciDevice1004::DEVICE_0105: return "DEVICE_0105";
        case PciDevice1004::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1004::DEVICE_0280: return "DEVICE_0280";
        case PciDevice1004::DEVICE_0304: return "DEVICE_0304";
        case PciDevice1004::DEVICE_0305: return "DEVICE_0305";
        case PciDevice1004::DEVICE_0306: return "DEVICE_0306";
        case PciDevice1004::DEVICE_0307: return "DEVICE_0307";
        case PciDevice1004::DEVICE_0308: return "DEVICE_0308";
        case PciDevice1004::DEVICE_0702: return "DEVICE_0702";
        case PciDevice1004::DEVICE_0703: return "DEVICE_0703";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1004 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1004 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1004::DEVICE_0005: return "82C592-FC1";
        case PciDevice1004::DEVICE_0006: return "82C593-FC1";
        case PciDevice1004::DEVICE_0007: return "82C594-AFC2";
        case PciDevice1004::DEVICE_0008: return "82C596/7 [Wildcat]";
        case PciDevice1004::DEVICE_0009: return "82C597-AFC2";
        case PciDevice1004::DEVICE_000C: return "82C541 [Lynx]";
        case PciDevice1004::DEVICE_000D: return "82C543 [Lynx]";
        case PciDevice1004::DEVICE_0101: return "82C532";
        case PciDevice1004::DEVICE_0102: return "82C534 [Eagle]";
        case PciDevice1004::DEVICE_0103: return "82C538";
        case PciDevice1004::DEVICE_0104: return "82C535";
        case PciDevice1004::DEVICE_0105: return "82C147";
        case PciDevice1004::DEVICE_0200: return "82C975";
        case PciDevice1004::DEVICE_0280: return "82C925";
        case PciDevice1004::DEVICE_0304: return "QSound ThunderBird PCI Audio";
        case PciDevice1004::DEVICE_0305: return "QSound ThunderBird PCI Audio Gameport";
        case PciDevice1004::DEVICE_0306: return "QSound ThunderBird PCI Audio Support Registers";
        case PciDevice1004::DEVICE_0307: return "SAA7785 ThunderBird PCI Audio";
        case PciDevice1004::DEVICE_0308: return "SAA7785 ThunderBird PCI Audio Gameport";
        case PciDevice1004::DEVICE_0702: return "VAS96011 [Golden Gate II]";
        case PciDevice1004::DEVICE_0703: return "Tollgate";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1004 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1004::DEVICE_0005: return "Unknown device";
        case PciDevice1004::DEVICE_0006: return "Unknown device";
        case PciDevice1004::DEVICE_0007: return "Unknown device";
        case PciDevice1004::DEVICE_0008: return "Unknown device";
        case PciDevice1004::DEVICE_0009: return "Unknown device";
        case PciDevice1004::DEVICE_000C: return "Unknown device";
        case PciDevice1004::DEVICE_000D: return "Unknown device";
        case PciDevice1004::DEVICE_0101: return "Unknown device";
        case PciDevice1004::DEVICE_0102: return "Unknown device";
        case PciDevice1004::DEVICE_0103: return "Unknown device";
        case PciDevice1004::DEVICE_0104: return "Unknown device";
        case PciDevice1004::DEVICE_0105: return "Unknown device";
        case PciDevice1004::DEVICE_0200: return "Unknown device";
        case PciDevice1004::DEVICE_0280: return "Unknown device";
        case PciDevice1004::DEVICE_0304: return enumToHumanString((PciSubDevice10040304)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1004::DEVICE_0305: return enumToHumanString((PciSubDevice10040305)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1004::DEVICE_0306: return enumToHumanString((PciSubDevice10040306)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1004::DEVICE_0307: return enumToHumanString((PciSubDevice10040307)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1004::DEVICE_0308: return "Unknown device";
        case PciDevice1004::DEVICE_0702: return "Unknown device";
        case PciDevice1004::DEVICE_0703: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1004_PCIDEVICE1004_H
