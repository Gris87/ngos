// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAAAA_PCIDEVICEAAAA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAAAA_PCIDEVICEAAAA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceAAAA: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDeviceAAAA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceAAAA::NONE:        return "NONE";
        case PciDeviceAAAA::DEVICE_0001: return "DEVICE_0001";
        case PciDeviceAAAA::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceAAAA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceAAAA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceAAAA::DEVICE_0001: return "H1 PCIe over fiber optic host controller";
        case PciDeviceAAAA::DEVICE_0002: return "R1BP1 PCIe over fiber optic expansion chassis";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAAAA_PCIDEVICEAAAA_H
