// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808606F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808606F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808606F0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860034 = 0x80860034,
    SUBDEVICE_80860074 = 0x80860074,
    SUBDEVICE_808602A4 = 0x808602A4
};



inline const char8* enumToString(PciSubDevice808606F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808606F0::NONE:               return "NONE";
        case PciSubDevice808606F0::SUBDEVICE_80860034: return "SUBDEVICE_80860034";
        case PciSubDevice808606F0::SUBDEVICE_80860074: return "SUBDEVICE_80860074";
        case PciSubDevice808606F0::SUBDEVICE_808602A4: return "SUBDEVICE_808602A4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808606F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808606F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808606F0::SUBDEVICE_80860034: return "Wireless-AC 9560";
        case PciSubDevice808606F0::SUBDEVICE_80860074: return "Wi-Fi 6 AX201 160MHz";
        case PciSubDevice808606F0::SUBDEVICE_808602A4: return "Wireless-AC 9462";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808606F0_H
