// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8C4A_PCIDEVICE8C4A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8C4A_PCIDEVICE8C4A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice8C4A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1980 = 0x1980
};



inline const char8* enumToString(PciDevice8C4A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8C4A::NONE:        return "NONE";
        case PciDevice8C4A::DEVICE_1980: return "DEVICE_1980";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice8C4A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice8C4A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8C4A::DEVICE_1980: return "W89C940 misprogrammed [ne2k]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8C4A_PCIDEVICE8C4A_H
