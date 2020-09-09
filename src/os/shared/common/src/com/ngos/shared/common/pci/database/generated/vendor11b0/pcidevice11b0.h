// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B0_PCIDEVICE11B0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B0_PCIDEVICE11B0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11B0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0292 = 0x0292,
    DEVICE_0960 = 0x0960,
    DEVICE_880A = 0x880A,
    DEVICE_C960 = 0xC960
};



inline const char8* enumToString(PciDevice11B0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11B0::NONE:        return "NONE";
        case PciDevice11B0::DEVICE_0002: return "DEVICE_0002";
        case PciDevice11B0::DEVICE_0292: return "DEVICE_0292";
        case PciDevice11B0::DEVICE_0960: return "DEVICE_0960";
        case PciDevice11B0::DEVICE_880A: return "DEVICE_880A";
        case PciDevice11B0::DEVICE_C960: return "DEVICE_C960";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11B0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11B0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11B0::DEVICE_0002: return "V300PSC";
        case PciDevice11B0::DEVICE_0292: return "V292PBC [Am29030/40 Bridge]";
        case PciDevice11B0::DEVICE_0960: return "V96xPBC";
        case PciDevice11B0::DEVICE_880A: return "Deltacast Delta-HD-22";
        case PciDevice11B0::DEVICE_C960: return "V96DPC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11B0_PCIDEVICE11B0_H
