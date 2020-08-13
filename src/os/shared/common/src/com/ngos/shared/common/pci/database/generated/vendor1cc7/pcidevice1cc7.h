// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC7_PCIDEVICE1CC7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC7_PCIDEVICE1CC7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CC7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200,
    DEVICE_0250 = 0x0250
};



inline const char8* enumToString(PciDevice1CC7 device1CC7) // TEST: NO
{
    // COMMON_LT((" | device1CC7 = %u", device1CC7)); // Commented to avoid bad looking logs



    switch (device1CC7)
    {
        case PciDevice1CC7::NONE:        return "NONE";
        case PciDevice1CC7::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1CC7::DEVICE_0250: return "DEVICE_0250";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CC7 device1CC7) // TEST: NO
{
    // COMMON_LT((" | device1CC7 = %u", device1CC7)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CC7, enumToString(device1CC7));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CC7 device1CC7) // TEST: NO
{
    // COMMON_LT((" | device1CC7 = %u", device1CC7)); // Commented to avoid bad looking logs



    switch (device1CC7)
    {
        case PciDevice1CC7::DEVICE_0200: return "RMS-200";
        case PciDevice1CC7::DEVICE_0250: return "RMS-250";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC7_PCIDEVICE1CC7_H
