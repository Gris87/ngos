// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B4_PCIDEVICE10B4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B4_PCIDEVICE10B4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1B1D = 0x1B1D
};



inline const char8* enumToString(PciDevice10B4 device10B4) // TEST: NO
{
    // COMMON_LT((" | device10B4 = %u", device10B4)); // Commented to avoid bad looking logs



    switch (device10B4)
    {
        case PciDevice10B4::NONE:        return "NONE";
        case PciDevice10B4::DEVICE_1B1D: return "DEVICE_1B1D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B4 device10B4) // TEST: NO
{
    // COMMON_LT((" | device10B4 = %u", device10B4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10B4, enumToString(device10B4));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B4 device10B4) // TEST: NO
{
    // COMMON_LT((" | device10B4 = %u", device10B4)); // Commented to avoid bad looking logs



    switch (device10B4)
    {
        case PciDevice10B4::DEVICE_1B1D: return "Velocity 128 3D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B4_PCIDEVICE10B4_H
