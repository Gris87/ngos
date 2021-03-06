// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC93010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC93010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1FC93010: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00003002 = 0x00003002,
    SUBDEVICE_00003004 = 0x00003004,
    SUBDEVICE_00003008 = 0x00003008
};



inline const char8* enumToString(PciSubDevice1FC93010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC93010::NONE:               return "NONE";
        case PciSubDevice1FC93010::SUBDEVICE_00003002: return "SUBDEVICE_00003002";
        case PciSubDevice1FC93010::SUBDEVICE_00003004: return "SUBDEVICE_00003004";
        case PciSubDevice1FC93010::SUBDEVICE_00003008: return "SUBDEVICE_00003008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1FC93010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1FC93010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC93010::SUBDEVICE_00003002: return "10-Giga TOE Single Port XFP SmartNIC";
        case PciSubDevice1FC93010::SUBDEVICE_00003004: return "10-Giga TOE Single Port SFP+ SmartNIC";
        case PciSubDevice1FC93010::SUBDEVICE_00003008: return "10-Giga TOE Single Port CX4 SmartNIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC93010_H
