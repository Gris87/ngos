// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCIDEVICE1319_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCIDEVICE1319_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1319/pcisubdevice13190801.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1319/pcisubdevice13190802.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1319: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0801 = 0x0801,
    DEVICE_0802 = 0x0802,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001
};



inline const char8* enumToString(PciDevice1319 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1319::NONE:        return "NONE";
        case PciDevice1319::DEVICE_0801: return "DEVICE_0801";
        case PciDevice1319::DEVICE_0802: return "DEVICE_0802";
        case PciDevice1319::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1319::DEVICE_1001: return "DEVICE_1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1319 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1319 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1319::DEVICE_0801: return "Xwave QS3000A [FM801]";
        case PciDevice1319::DEVICE_0802: return "Xwave QS3000A [FM801 game port]";
        case PciDevice1319::DEVICE_1000: return "FM801 PCI Audio";
        case PciDevice1319::DEVICE_1001: return "FM801 PCI Joystick";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1319 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1319::DEVICE_0801: return enumToHumanString((PciSubDevice13190801)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1319::DEVICE_0802: return enumToHumanString((PciSubDevice13190802)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1319::DEVICE_1000: return "Unknown device";
        case PciDevice1319::DEVICE_1001: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCIDEVICE1319_H
