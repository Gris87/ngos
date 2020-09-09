// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC93014_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC93014_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1FC93014: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00003003 = 0x00003003,
    SUBDEVICE_00003005 = 0x00003005,
    SUBDEVICE_00003014 = 0x00003014
};



inline const char8* enumToString(PciSubDevice1FC93014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC93014::NONE:               return "NONE";
        case PciSubDevice1FC93014::SUBDEVICE_00003003: return "SUBDEVICE_00003003";
        case PciSubDevice1FC93014::SUBDEVICE_00003005: return "SUBDEVICE_00003005";
        case PciSubDevice1FC93014::SUBDEVICE_00003014: return "SUBDEVICE_00003014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1FC93014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1FC93014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC93014::SUBDEVICE_00003003: return "10-Giga TOE Dual Port XFP Low Profile SmartNIC";
        case PciSubDevice1FC93014::SUBDEVICE_00003005: return "10-Giga TOE Dual Port SFP+ Low Profile SmartNIC";
        case PciSubDevice1FC93014::SUBDEVICE_00003014: return "10-Giga TOE Dual Port CX4 Low Profile SmartNIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC93014_H
