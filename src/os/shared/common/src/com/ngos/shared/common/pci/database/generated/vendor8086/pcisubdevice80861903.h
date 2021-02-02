// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861903_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861903_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861903: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102806D6 = 0x102806D6,
    SUBDEVICE_102806DC = 0x102806DC,
    SUBDEVICE_102806E4 = 0x102806E4,
    SUBDEVICE_102806E6 = 0x102806E6,
    SUBDEVICE_103C825B = 0x103C825B,
    SUBDEVICE_17AA225D = 0x17AA225D
};



inline const char8* enumToString(PciSubDevice80861903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861903::NONE:               return "NONE";
        case PciSubDevice80861903::SUBDEVICE_102806D6: return "SUBDEVICE_102806D6";
        case PciSubDevice80861903::SUBDEVICE_102806DC: return "SUBDEVICE_102806DC";
        case PciSubDevice80861903::SUBDEVICE_102806E4: return "SUBDEVICE_102806E4";
        case PciSubDevice80861903::SUBDEVICE_102806E6: return "SUBDEVICE_102806E6";
        case PciSubDevice80861903::SUBDEVICE_103C825B: return "SUBDEVICE_103C825B";
        case PciSubDevice80861903::SUBDEVICE_17AA225D: return "SUBDEVICE_17AA225D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861903 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861903::SUBDEVICE_102806D6: return "Latitude 7275 tablet";
        case PciSubDevice80861903::SUBDEVICE_102806DC: return "Latitude E7470";
        case PciSubDevice80861903::SUBDEVICE_102806E4: return "XPS 15 9550";
        case PciSubDevice80861903::SUBDEVICE_102806E6: return "Latitude 11 5175 2-in-1";
        case PciSubDevice80861903::SUBDEVICE_103C825B: return "OMEN-17-w001nv";
        case PciSubDevice80861903::SUBDEVICE_17AA225D: return "ThinkPad T480";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861903_H
