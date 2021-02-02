// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCIDEVICE1409_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCIDEVICE1409_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1409/pcisubdevice14097168.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1409/pcisubdevice14097268.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1409: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7168 = 0x7168,
    DEVICE_7268 = 0x7268
};



inline const char8* enumToString(PciDevice1409 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1409::NONE:        return "NONE";
        case PciDevice1409::DEVICE_7168: return "DEVICE_7168";
        case PciDevice1409::DEVICE_7268: return "DEVICE_7268";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1409 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1409 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1409::DEVICE_7168: return "PCI2S550 (Dual 16550 UART)";
        case PciDevice1409::DEVICE_7268: return "SUN1888 (Dual IEEE1284 parallel port)";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1409 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1409::DEVICE_7168: return enumToHumanString((PciSubDevice14097168)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1409::DEVICE_7268: return enumToHumanString((PciSubDevice14097268)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCIDEVICE1409_H
