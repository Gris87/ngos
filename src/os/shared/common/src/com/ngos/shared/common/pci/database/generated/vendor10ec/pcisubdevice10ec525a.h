// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC525A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC525A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC525A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102806D6 = 0x102806D6,
    SUBDEVICE_102806DC = 0x102806DC,
    SUBDEVICE_102806E4 = 0x102806E4,
    SUBDEVICE_102806E6 = 0x102806E6,
    SUBDEVICE_17AA224F = 0x17AA224F
};



inline const char8* enumToString(PciSubDevice10EC525A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC525A::NONE:               return "NONE";
        case PciSubDevice10EC525A::SUBDEVICE_102806D6: return "SUBDEVICE_102806D6";
        case PciSubDevice10EC525A::SUBDEVICE_102806DC: return "SUBDEVICE_102806DC";
        case PciSubDevice10EC525A::SUBDEVICE_102806E4: return "SUBDEVICE_102806E4";
        case PciSubDevice10EC525A::SUBDEVICE_102806E6: return "SUBDEVICE_102806E6";
        case PciSubDevice10EC525A::SUBDEVICE_17AA224F: return "SUBDEVICE_17AA224F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC525A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC525A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC525A::SUBDEVICE_102806D6: return "Latitude 7275 tablet";
        case PciSubDevice10EC525A::SUBDEVICE_102806DC: return "Latitude E7470";
        case PciSubDevice10EC525A::SUBDEVICE_102806E4: return "XPS 15 9550";
        case PciSubDevice10EC525A::SUBDEVICE_102806E6: return "Latitude 11 5175 2-in-1";
        case PciSubDevice10EC525A::SUBDEVICE_17AA224F: return "ThinkPad X1 Carbon 5th Gen";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC525A_H
