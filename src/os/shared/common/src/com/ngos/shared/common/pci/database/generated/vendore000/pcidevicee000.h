// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE000_PCIDEVICEE000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE000_PCIDEVICEE000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceE000: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E000 = 0xE000
};



inline const char8* enumToString(PciDeviceE000 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceE000::NONE:        return "NONE";
        case PciDeviceE000::DEVICE_E000: return "DEVICE_E000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceE000 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceE000 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceE000::DEVICE_E000: return "W89C940";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE000_PCIDEVICEE000_H
