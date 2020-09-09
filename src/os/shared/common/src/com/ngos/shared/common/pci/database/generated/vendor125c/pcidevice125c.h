// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125C_PCIDEVICE125C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125C_PCIDEVICE125C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice125C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0640 = 0x0640
};



inline const char8* enumToString(PciDevice125C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice125C::NONE:        return "NONE";
        case PciDevice125C::DEVICE_0101: return "DEVICE_0101";
        case PciDevice125C::DEVICE_0640: return "DEVICE_0640";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice125C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice125C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice125C::DEVICE_0101: return "Saturn 4520P";
        case PciDevice125C::DEVICE_0640: return "Aries 16000P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125C_PCIDEVICE125C_H
