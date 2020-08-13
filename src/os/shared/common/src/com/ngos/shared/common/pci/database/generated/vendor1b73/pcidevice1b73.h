// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B73_PCIDEVICE1B73_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B73_PCIDEVICE1B73_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B73: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1009 = 0x1009,
    DEVICE_1100 = 0x1100
};



inline const char8* enumToString(PciDevice1B73 device1B73) // TEST: NO
{
    // COMMON_LT((" | device1B73 = %u", device1B73)); // Commented to avoid bad looking logs



    switch (device1B73)
    {
        case PciDevice1B73::NONE:        return "NONE";
        case PciDevice1B73::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1B73::DEVICE_1009: return "DEVICE_1009";
        case PciDevice1B73::DEVICE_1100: return "DEVICE_1100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B73 device1B73) // TEST: NO
{
    // COMMON_LT((" | device1B73 = %u", device1B73)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B73, enumToString(device1B73));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B73 device1B73) // TEST: NO
{
    // COMMON_LT((" | device1B73 = %u", device1B73)); // Commented to avoid bad looking logs



    switch (device1B73)
    {
        case PciDevice1B73::DEVICE_1000: return "FL1000G USB 3.0 Host Controller";
        case PciDevice1B73::DEVICE_1009: return "FL1009 USB 3.0 Host Controller";
        case PciDevice1B73::DEVICE_1100: return "FL1100 USB 3.0 Host Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B73_PCIDEVICE1B73_H
