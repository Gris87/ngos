// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7063_PCIDEVICE7063_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7063_PCIDEVICE7063_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice7063: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2000 = 0x2000,
    DEVICE_3000 = 0x3000,
    DEVICE_5500 = 0x5500
};



inline const char8* enumToString(PciDevice7063 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice7063::NONE:        return "NONE";
        case PciDevice7063::DEVICE_2000: return "DEVICE_2000";
        case PciDevice7063::DEVICE_3000: return "DEVICE_3000";
        case PciDevice7063::DEVICE_5500: return "DEVICE_5500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice7063 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice7063 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice7063::DEVICE_2000: return "HD-2000";
        case PciDevice7063::DEVICE_3000: return "HD-3000";
        case PciDevice7063::DEVICE_5500: return "HD5500 HDTV";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR7063_PCIDEVICE7063_H
