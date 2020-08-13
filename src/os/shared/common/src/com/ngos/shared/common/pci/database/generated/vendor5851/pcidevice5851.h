// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5851_PCIDEVICE5851_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5851_PCIDEVICE5851_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5851: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8008 = 0x8008,
    DEVICE_8016 = 0x8016,
    DEVICE_8032 = 0x8032
};



inline const char8* enumToString(PciDevice5851 device5851) // TEST: NO
{
    // COMMON_LT((" | device5851 = %u", device5851)); // Commented to avoid bad looking logs



    switch (device5851)
    {
        case PciDevice5851::NONE:        return "NONE";
        case PciDevice5851::DEVICE_8008: return "DEVICE_8008";
        case PciDevice5851::DEVICE_8016: return "DEVICE_8016";
        case PciDevice5851::DEVICE_8032: return "DEVICE_8032";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5851 device5851) // TEST: NO
{
    // COMMON_LT((" | device5851 = %u", device5851)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5851, enumToString(device5851));

    return res;
}



inline const char8* enumToHumanString(PciDevice5851 device5851) // TEST: NO
{
    // COMMON_LT((" | device5851 = %u", device5851)); // Commented to avoid bad looking logs



    switch (device5851)
    {
        case PciDevice5851::DEVICE_8008: return "tDVR8008 8-port video capture card";
        case PciDevice5851::DEVICE_8016: return "tDVR8016 16-chan video capture card";
        case PciDevice5851::DEVICE_8032: return "tDVR8032 32-chan video capture card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5851_PCIDEVICE5851_H
