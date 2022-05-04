// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D69_PCIDEVICE1D69_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D69_PCIDEVICE1D69_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D69: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2432 = 0x2432,
    DEVICE_2440 = 0x2440
};



inline const char8* enumToString(PciDevice1D69 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D69::NONE:        return "NONE";
        case PciDevice1D69::DEVICE_2432: return "DEVICE_2432";
        case PciDevice1D69::DEVICE_2440: return "DEVICE_2440";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D69 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D69 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D69::DEVICE_2432: return "CL2432";
        case PciDevice1D69::DEVICE_2440: return "CL2440";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D69_PCIDEVICE1D69_H
