// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREC80_PCIDEVICEEC80_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREC80_PCIDEVICEEC80_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceEC80: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_EC00 = 0xEC00
};



inline const char8* enumToString(PciDeviceEC80 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceEC80::NONE:        return "NONE";
        case PciDeviceEC80::DEVICE_EC00: return "DEVICE_EC00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceEC80 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceEC80 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceEC80::DEVICE_EC00: return "F5D6000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREC80_PCIDEVICEEC80_H
