// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE005E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE005E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE005E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280225 = 0x10280225,
    SUBDEVICE_1043815A = 0x1043815A,
    SUBDEVICE_10DE005E = 0x10DE005E,
    SUBDEVICE_10F12865 = 0x10F12865,
    SUBDEVICE_10F12891 = 0x10F12891,
    SUBDEVICE_14585000 = 0x14585000,
    SUBDEVICE_14627100 = 0x14627100,
    SUBDEVICE_14627125 = 0x14627125,
    SUBDEVICE_147B1C1A = 0x147B1C1A,
    SUBDEVICE_15653402 = 0x15653402
};



inline const char8* enumToString(PciSubDevice10DE005E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE005E::NONE:               return "NONE";
        case PciSubDevice10DE005E::SUBDEVICE_10280225: return "SUBDEVICE_10280225";
        case PciSubDevice10DE005E::SUBDEVICE_1043815A: return "SUBDEVICE_1043815A";
        case PciSubDevice10DE005E::SUBDEVICE_10DE005E: return "SUBDEVICE_10DE005E";
        case PciSubDevice10DE005E::SUBDEVICE_10F12865: return "SUBDEVICE_10F12865";
        case PciSubDevice10DE005E::SUBDEVICE_10F12891: return "SUBDEVICE_10F12891";
        case PciSubDevice10DE005E::SUBDEVICE_14585000: return "SUBDEVICE_14585000";
        case PciSubDevice10DE005E::SUBDEVICE_14627100: return "SUBDEVICE_14627100";
        case PciSubDevice10DE005E::SUBDEVICE_14627125: return "SUBDEVICE_14627125";
        case PciSubDevice10DE005E::SUBDEVICE_147B1C1A: return "SUBDEVICE_147B1C1A";
        case PciSubDevice10DE005E::SUBDEVICE_15653402: return "SUBDEVICE_15653402";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE005E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE005E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE005E::SUBDEVICE_10280225: return "PowerEdge T105 Memory Controller";
        case PciSubDevice10DE005E::SUBDEVICE_1043815A: return "A8N Series Mainboard";
        case PciSubDevice10DE005E::SUBDEVICE_10DE005E: return "ECS Elitegroup NFORCE3-A939 motherboard.";
        case PciSubDevice10DE005E::SUBDEVICE_10F12865: return "Tomcat K8E (S2865)";
        case PciSubDevice10DE005E::SUBDEVICE_10F12891: return "Thunder K8SRE Mainboard";
        case PciSubDevice10DE005E::SUBDEVICE_14585000: return "GA-K8N Ultra-9 Mainboard";
        case PciSubDevice10DE005E::SUBDEVICE_14627100: return "K8N Diamond Mainboard";
        case PciSubDevice10DE005E::SUBDEVICE_14627125: return "K8N Neo4-F Mainboard";
        case PciSubDevice10DE005E::SUBDEVICE_147B1C1A: return "KN8-Ultra Mainboard";
        case PciSubDevice10DE005E::SUBDEVICE_15653402: return "NF4 AM2L Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE005E_H
