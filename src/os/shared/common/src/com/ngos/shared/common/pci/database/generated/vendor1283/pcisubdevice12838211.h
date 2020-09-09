// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCISUBDEVICE12838211_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCISUBDEVICE12838211_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12838211: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438138 = 0x10438138
};



inline const char8* enumToString(PciSubDevice12838211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12838211::NONE:               return "NONE";
        case PciSubDevice12838211::SUBDEVICE_10438138: return "SUBDEVICE_10438138";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12838211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12838211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12838211::SUBDEVICE_10438138: return "P5GD1-VW Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1283_PCISUBDEVICE12838211_H
