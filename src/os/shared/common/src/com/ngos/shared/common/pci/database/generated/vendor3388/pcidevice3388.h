// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCIDEVICE3388_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCIDEVICE3388_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3388/pcisubdevice33880021.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3388/pcisubdevice33888011.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3388/pcisubdevice33888012.h>
#include <com/ngos/shared/common/pci/database/generated/vendor3388/pcisubdevice33888013.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice3388: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0026 = 0x0026,
    DEVICE_1014 = 0x1014,
    DEVICE_1018 = 0x1018,
    DEVICE_1019 = 0x1019,
    DEVICE_101A = 0x101A,
    DEVICE_101B = 0x101B,
    DEVICE_8011 = 0x8011,
    DEVICE_8012 = 0x8012,
    DEVICE_8013 = 0x8013,
    DEVICE_A103 = 0xA103
};



inline const char8* enumToString(PciDevice3388 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3388::NONE:        return "NONE";
        case PciDevice3388::DEVICE_0013: return "DEVICE_0013";
        case PciDevice3388::DEVICE_0014: return "DEVICE_0014";
        case PciDevice3388::DEVICE_0020: return "DEVICE_0020";
        case PciDevice3388::DEVICE_0021: return "DEVICE_0021";
        case PciDevice3388::DEVICE_0022: return "DEVICE_0022";
        case PciDevice3388::DEVICE_0026: return "DEVICE_0026";
        case PciDevice3388::DEVICE_1014: return "DEVICE_1014";
        case PciDevice3388::DEVICE_1018: return "DEVICE_1018";
        case PciDevice3388::DEVICE_1019: return "DEVICE_1019";
        case PciDevice3388::DEVICE_101A: return "DEVICE_101A";
        case PciDevice3388::DEVICE_101B: return "DEVICE_101B";
        case PciDevice3388::DEVICE_8011: return "DEVICE_8011";
        case PciDevice3388::DEVICE_8012: return "DEVICE_8012";
        case PciDevice3388::DEVICE_8013: return "DEVICE_8013";
        case PciDevice3388::DEVICE_A103: return "DEVICE_A103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice3388 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice3388 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3388::DEVICE_0013: return "HiNT HC4 PCI to ISDN bridge, Multimedia audio controller";
        case PciDevice3388::DEVICE_0014: return "HiNT HC4 PCI to ISDN bridge, Network controller";
        case PciDevice3388::DEVICE_0020: return "HB6 Universal PCI-PCI bridge (transparent mode)";
        case PciDevice3388::DEVICE_0021: return "HB6 Universal PCI-PCI bridge (non-transparent mode)";
        case PciDevice3388::DEVICE_0022: return "HiNT HB4 PCI-PCI Bridge (PCI6150)";
        case PciDevice3388::DEVICE_0026: return "HB2 PCI-PCI Bridge";
        case PciDevice3388::DEVICE_1014: return "AudioTrak Maya";
        case PciDevice3388::DEVICE_1018: return "Audiotrak INCA88";
        case PciDevice3388::DEVICE_1019: return "Miditrak 2120";
        case PciDevice3388::DEVICE_101A: return "E.Band [AudioTrak Inca88]";
        case PciDevice3388::DEVICE_101B: return "E.Band [AudioTrak Inca88]";
        case PciDevice3388::DEVICE_8011: return "VXPro II Chipset";
        case PciDevice3388::DEVICE_8012: return "VXPro II Chipset";
        case PciDevice3388::DEVICE_8013: return "VXPro II IDE";
        case PciDevice3388::DEVICE_A103: return "Blackmagic Design DeckLink HD Pro";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice3388 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3388::DEVICE_0013: return "Unknown device";
        case PciDevice3388::DEVICE_0014: return "Unknown device";
        case PciDevice3388::DEVICE_0020: return "Unknown device";
        case PciDevice3388::DEVICE_0021: return enumToHumanString((PciSubDevice33880021)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3388::DEVICE_0022: return "Unknown device";
        case PciDevice3388::DEVICE_0026: return "Unknown device";
        case PciDevice3388::DEVICE_1014: return "Unknown device";
        case PciDevice3388::DEVICE_1018: return "Unknown device";
        case PciDevice3388::DEVICE_1019: return "Unknown device";
        case PciDevice3388::DEVICE_101A: return "Unknown device";
        case PciDevice3388::DEVICE_101B: return "Unknown device";
        case PciDevice3388::DEVICE_8011: return enumToHumanString((PciSubDevice33888011)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3388::DEVICE_8012: return enumToHumanString((PciSubDevice33888012)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3388::DEVICE_8013: return enumToHumanString((PciSubDevice33888013)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice3388::DEVICE_A103: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3388_PCIDEVICE3388_H
