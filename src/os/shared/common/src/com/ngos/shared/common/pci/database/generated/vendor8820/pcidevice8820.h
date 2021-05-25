// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8820_PCIDEVICE8820_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8820_PCIDEVICE8820_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice8820: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2724 = 0x2724
};



inline const char8* enumToString(PciDevice8820 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8820::NONE:        return "NONE";
        case PciDevice8820::DEVICE_2724: return "DEVICE_2724";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice8820 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice8820 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8820::DEVICE_2724: return "Mako Front Side Motor Controller [cPCI]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8820_PCIDEVICE8820_H
