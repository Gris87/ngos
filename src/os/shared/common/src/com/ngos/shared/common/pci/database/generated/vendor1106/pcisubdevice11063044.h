// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063044_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063044_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063044: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00100001 = 0x00100001,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_103C2A20 = 0x103C2A20,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_1043808A = 0x1043808A,
    SUBDEVICE_104381FE = 0x104381FE,
    SUBDEVICE_14581000 = 0x14581000,
    SUBDEVICE_1462207D = 0x1462207D,
    SUBDEVICE_1462217D = 0x1462217D,
    SUBDEVICE_1462590D = 0x1462590D,
    SUBDEVICE_1462702D = 0x1462702D,
    SUBDEVICE_1462971D = 0x1462971D
};



inline const char8* enumToString(PciSubDevice11063044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063044::NONE:               return "NONE";
        case PciSubDevice11063044::SUBDEVICE_00100001: return "SUBDEVICE_00100001";
        case PciSubDevice11063044::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice11063044::SUBDEVICE_103C2A20: return "SUBDEVICE_103C2A20";
        case PciSubDevice11063044::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice11063044::SUBDEVICE_1043808A: return "SUBDEVICE_1043808A";
        case PciSubDevice11063044::SUBDEVICE_104381FE: return "SUBDEVICE_104381FE";
        case PciSubDevice11063044::SUBDEVICE_14581000: return "SUBDEVICE_14581000";
        case PciSubDevice11063044::SUBDEVICE_1462207D: return "SUBDEVICE_1462207D";
        case PciSubDevice11063044::SUBDEVICE_1462217D: return "SUBDEVICE_1462217D";
        case PciSubDevice11063044::SUBDEVICE_1462590D: return "SUBDEVICE_1462590D";
        case PciSubDevice11063044::SUBDEVICE_1462702D: return "SUBDEVICE_1462702D";
        case PciSubDevice11063044::SUBDEVICE_1462971D: return "SUBDEVICE_1462971D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063044::SUBDEVICE_00100001: return "IEEE 1394 4port DCST 1394-3+1B";
        case PciSubDevice11063044::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice11063044::SUBDEVICE_103C2A20: return "Pavilion t3030.de Desktop PC";
        case PciSubDevice11063044::SUBDEVICE_103C2A3B: return "Media Center PC m7590n";
        case PciSubDevice11063044::SUBDEVICE_1043808A: return "A8V/A8N/P4P800/P5SD2 series motherboard";
        case PciSubDevice11063044::SUBDEVICE_104381FE: return "Motherboard";
        case PciSubDevice11063044::SUBDEVICE_14581000: return "GA-7VT600-1394 Motherboard";
        case PciSubDevice11063044::SUBDEVICE_1462207D: return "K8NGM2 series motherboard";
        case PciSubDevice11063044::SUBDEVICE_1462217D: return "Aspire L250";
        case PciSubDevice11063044::SUBDEVICE_1462590D: return "KT6 Delta-FIS2R (MS-6590)";
        case PciSubDevice11063044::SUBDEVICE_1462702D: return "K8T NEO 2 motherboard";
        case PciSubDevice11063044::SUBDEVICE_1462971D: return "MS-6917";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063044_H
