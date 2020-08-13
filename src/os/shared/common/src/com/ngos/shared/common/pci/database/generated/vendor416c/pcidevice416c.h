// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR416C_PCIDEVICE416C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR416C_PCIDEVICE416C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice416C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDevice416C device416C) // TEST: NO
{
    // COMMON_LT((" | device416C = %u", device416C)); // Commented to avoid bad looking logs



    switch (device416C)
    {
        case PciDevice416C::NONE:        return "NONE";
        case PciDevice416C::DEVICE_0100: return "DEVICE_0100";
        case PciDevice416C::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice416C device416C) // TEST: NO
{
    // COMMON_LT((" | device416C = %u", device416C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device416C, enumToString(device416C));

    return res;
}



inline const char8* enumToHumanString(PciDevice416C device416C) // TEST: NO
{
    // COMMON_LT((" | device416C = %u", device416C)); // Commented to avoid bad looking logs



    switch (device416C)
    {
        case PciDevice416C::DEVICE_0100: return "AladdinCARD";
        case PciDevice416C::DEVICE_0200: return "CPC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR416C_PCIDEVICE416C_H
