// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0050_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0050_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0050: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043815A = 0x1043815A,
    SUBDEVICE_10F12865 = 0x10F12865,
    SUBDEVICE_14580C11 = 0x14580C11,
    SUBDEVICE_14627100 = 0x14627100,
    SUBDEVICE_14627125 = 0x14627125,
    SUBDEVICE_147B1C1A = 0x147B1C1A,
    SUBDEVICE_15653402 = 0x15653402
};



inline const char8* enumToString(PciSubDevice10DE0050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0050::NONE:               return "NONE";
        case PciSubDevice10DE0050::SUBDEVICE_1043815A: return "SUBDEVICE_1043815A";
        case PciSubDevice10DE0050::SUBDEVICE_10F12865: return "SUBDEVICE_10F12865";
        case PciSubDevice10DE0050::SUBDEVICE_14580C11: return "SUBDEVICE_14580C11";
        case PciSubDevice10DE0050::SUBDEVICE_14627100: return "SUBDEVICE_14627100";
        case PciSubDevice10DE0050::SUBDEVICE_14627125: return "SUBDEVICE_14627125";
        case PciSubDevice10DE0050::SUBDEVICE_147B1C1A: return "SUBDEVICE_147B1C1A";
        case PciSubDevice10DE0050::SUBDEVICE_15653402: return "SUBDEVICE_15653402";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0050::SUBDEVICE_1043815A: return "K8N4/A8N Series Mainboard";
        case PciSubDevice10DE0050::SUBDEVICE_10F12865: return "Tomcat K8E (S2865)";
        case PciSubDevice10DE0050::SUBDEVICE_14580C11: return "GA-K8N Ultra-9 Mainboard";
        case PciSubDevice10DE0050::SUBDEVICE_14627100: return "MSI K8N Diamond";
        case PciSubDevice10DE0050::SUBDEVICE_14627125: return "K8N Neo4-F mainboard";
        case PciSubDevice10DE0050::SUBDEVICE_147B1C1A: return "KN8-Ultra Mainboard";
        case PciSubDevice10DE0050::SUBDEVICE_15653402: return "NF4 AM2L Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0050_H
