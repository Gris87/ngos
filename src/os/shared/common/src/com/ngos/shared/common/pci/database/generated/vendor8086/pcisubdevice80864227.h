// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864227_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864227_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864227: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861010 = 0x80861010,
    SUBDEVICE_80861011 = 0x80861011,
    SUBDEVICE_80861014 = 0x80861014
};



inline const char8* enumToString(PciSubDevice80864227 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864227::NONE:               return "NONE";
        case PciSubDevice80864227::SUBDEVICE_80861010: return "SUBDEVICE_80861010";
        case PciSubDevice80864227::SUBDEVICE_80861011: return "SUBDEVICE_80861011";
        case PciSubDevice80864227::SUBDEVICE_80861014: return "SUBDEVICE_80861014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864227 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864227 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864227::SUBDEVICE_80861010: return "ThinkPad R60e";
        case PciSubDevice80864227::SUBDEVICE_80861011: return "ThinkPad T60/R60e/X60s/R61";
        case PciSubDevice80864227::SUBDEVICE_80861014: return "PRO/Wireless 3945BG Network Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864227_H
