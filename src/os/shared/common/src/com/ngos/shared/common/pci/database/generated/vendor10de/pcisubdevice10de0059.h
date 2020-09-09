// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0059_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0059_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0059: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043812A = 0x1043812A,
    SUBDEVICE_10F12865 = 0x10F12865,
    SUBDEVICE_14627585 = 0x14627585,
    SUBDEVICE_147B1C1A = 0x147B1C1A,
    SUBDEVICE_15658211 = 0x15658211
};



inline const char8* enumToString(PciSubDevice10DE0059 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0059::NONE:               return "NONE";
        case PciSubDevice10DE0059::SUBDEVICE_1043812A: return "SUBDEVICE_1043812A";
        case PciSubDevice10DE0059::SUBDEVICE_10F12865: return "SUBDEVICE_10F12865";
        case PciSubDevice10DE0059::SUBDEVICE_14627585: return "SUBDEVICE_14627585";
        case PciSubDevice10DE0059::SUBDEVICE_147B1C1A: return "SUBDEVICE_147B1C1A";
        case PciSubDevice10DE0059::SUBDEVICE_15658211: return "SUBDEVICE_15658211";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0059 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0059 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0059::SUBDEVICE_1043812A: return "K8N4/A8N Series Mainboard";
        case PciSubDevice10DE0059::SUBDEVICE_10F12865: return "Tomcat K8E (S2865)";
        case PciSubDevice10DE0059::SUBDEVICE_14627585: return "K8N Neo4-F mainboard";
        case PciSubDevice10DE0059::SUBDEVICE_147B1C1A: return "KN8-Ultra Mainboard";
        case PciSubDevice10DE0059::SUBDEVICE_15658211: return "NF4 AM2L Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0059_H
