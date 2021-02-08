// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D65_PCIDEVICE1D65_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D65_PCIDEVICE1D65_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D65: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_04DE = 0x04DE
};



inline const char8* enumToString(PciDevice1D65 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D65::NONE:        return "NONE";
        case PciDevice1D65::DEVICE_04DE: return "DEVICE_04DE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D65 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D65 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D65::DEVICE_04DE: return "Taurus/McKinley";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D65_PCIDEVICE1D65_H
