// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1287_PCIDEVICE1287_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1287_PCIDEVICE1287_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1287: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_001E = 0x001E,
    DEVICE_001F = 0x001F
};



inline const char8* enumToString(PciDevice1287 device1287) // TEST: NO
{
    // COMMON_LT((" | device1287 = %u", device1287)); // Commented to avoid bad looking logs



    switch (device1287)
    {
        case PciDevice1287::NONE:        return "NONE";
        case PciDevice1287::DEVICE_001E: return "DEVICE_001E";
        case PciDevice1287::DEVICE_001F: return "DEVICE_001F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1287 device1287) // TEST: NO
{
    // COMMON_LT((" | device1287 = %u", device1287)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1287, enumToString(device1287));

    return res;
}



inline const char8* enumToHumanString(PciDevice1287 device1287) // TEST: NO
{
    // COMMON_LT((" | device1287 = %u", device1287)); // Commented to avoid bad looking logs



    switch (device1287)
    {
        case PciDevice1287::DEVICE_001E: return "LS220D DVD Decoder";
        case PciDevice1287::DEVICE_001F: return "LS220C DVD Decoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1287_PCIDEVICE1287_H