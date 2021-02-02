// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D9_PCIDEVICE12D9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D9_PCIDEVICE12D9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor12d9/pcisubdevice12d91078.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12D9: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_1078 = 0x1078
};



inline const char8* enumToString(PciDevice12D9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D9::NONE:        return "NONE";
        case PciDevice12D9::DEVICE_0002: return "DEVICE_0002";
        case PciDevice12D9::DEVICE_0004: return "DEVICE_0004";
        case PciDevice12D9::DEVICE_0005: return "DEVICE_0005";
        case PciDevice12D9::DEVICE_1078: return "DEVICE_1078";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12D9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12D9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D9::DEVICE_0002: return "PCI Prosody";
        case PciDevice12D9::DEVICE_0004: return "cPCI Prosody";
        case PciDevice12D9::DEVICE_0005: return "Aculab E1/T1 PCI card";
        case PciDevice12D9::DEVICE_1078: return "Prosody X class e1000 device";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice12D9 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D9::DEVICE_0002: return "Unknown device";
        case PciDevice12D9::DEVICE_0004: return "Unknown device";
        case PciDevice12D9::DEVICE_0005: return "Unknown device";
        case PciDevice12D9::DEVICE_1078: return enumToHumanString((PciSubDevice12D91078)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D9_PCIDEVICE12D9_H
