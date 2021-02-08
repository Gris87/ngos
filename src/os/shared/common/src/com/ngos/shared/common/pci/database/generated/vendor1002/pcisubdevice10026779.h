// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026779_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026779_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026779: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190016 = 0x10190016,
    SUBDEVICE_10190017 = 0x10190017,
    SUBDEVICE_10190018 = 0x10190018,
    SUBDEVICE_10282120 = 0x10282120,
    SUBDEVICE_103C2128 = 0x103C2128,
    SUBDEVICE_103C2AEE = 0x103C2AEE,
    SUBDEVICE_10926450 = 0x10926450,
    SUBDEVICE_14622125 = 0x14622125,
    SUBDEVICE_14622346 = 0x14622346,
    SUBDEVICE_14622490 = 0x14622490,
    SUBDEVICE_14622494 = 0x14622494,
    SUBDEVICE_14622496 = 0x14622496,
    SUBDEVICE_148C7450 = 0x148C7450,
    SUBDEVICE_148C8450 = 0x148C8450,
    SUBDEVICE_15457470 = 0x15457470,
    SUBDEVICE_16423A65 = 0x16423A65,
    SUBDEVICE_16423A66 = 0x16423A66,
    SUBDEVICE_16423A75 = 0x16423A75,
    SUBDEVICE_16423A76 = 0x16423A76,
    SUBDEVICE_16823200 = 0x16823200,
    SUBDEVICE_174B7450 = 0x174B7450,
    SUBDEVICE_174BE127 = 0x174BE127,
    SUBDEVICE_174BE153 = 0x174BE153,
    SUBDEVICE_174BE164 = 0x174BE164,
    SUBDEVICE_174BE180 = 0x174BE180,
    SUBDEVICE_174BE201 = 0x174BE201,
    SUBDEVICE_17AF8450 = 0x17AF8450,
    SUBDEVICE_1B0A9096 = 0x1B0A9096,
    SUBDEVICE_1B0A9097 = 0x1B0A9097,
    SUBDEVICE_1B0A90A8 = 0x1B0A90A8,
    SUBDEVICE_1B0A90B1 = 0x1B0A90B1,
    SUBDEVICE_1B0A90B3 = 0x1B0A90B3,
    SUBDEVICE_1B0A90BB = 0x1B0A90BB
};



inline const char8* enumToString(PciSubDevice10026779 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026779::NONE:               return "NONE";
        case PciSubDevice10026779::SUBDEVICE_10190016: return "SUBDEVICE_10190016";
        case PciSubDevice10026779::SUBDEVICE_10190017: return "SUBDEVICE_10190017";
        case PciSubDevice10026779::SUBDEVICE_10190018: return "SUBDEVICE_10190018";
        case PciSubDevice10026779::SUBDEVICE_10282120: return "SUBDEVICE_10282120";
        case PciSubDevice10026779::SUBDEVICE_103C2128: return "SUBDEVICE_103C2128";
        case PciSubDevice10026779::SUBDEVICE_103C2AEE: return "SUBDEVICE_103C2AEE";
        case PciSubDevice10026779::SUBDEVICE_10926450: return "SUBDEVICE_10926450";
        case PciSubDevice10026779::SUBDEVICE_14622125: return "SUBDEVICE_14622125";
        case PciSubDevice10026779::SUBDEVICE_14622346: return "SUBDEVICE_14622346";
        case PciSubDevice10026779::SUBDEVICE_14622490: return "SUBDEVICE_14622490";
        case PciSubDevice10026779::SUBDEVICE_14622494: return "SUBDEVICE_14622494";
        case PciSubDevice10026779::SUBDEVICE_14622496: return "SUBDEVICE_14622496";
        case PciSubDevice10026779::SUBDEVICE_148C7450: return "SUBDEVICE_148C7450";
        case PciSubDevice10026779::SUBDEVICE_148C8450: return "SUBDEVICE_148C8450";
        case PciSubDevice10026779::SUBDEVICE_15457470: return "SUBDEVICE_15457470";
        case PciSubDevice10026779::SUBDEVICE_16423A65: return "SUBDEVICE_16423A65";
        case PciSubDevice10026779::SUBDEVICE_16423A66: return "SUBDEVICE_16423A66";
        case PciSubDevice10026779::SUBDEVICE_16423A75: return "SUBDEVICE_16423A75";
        case PciSubDevice10026779::SUBDEVICE_16423A76: return "SUBDEVICE_16423A76";
        case PciSubDevice10026779::SUBDEVICE_16823200: return "SUBDEVICE_16823200";
        case PciSubDevice10026779::SUBDEVICE_174B7450: return "SUBDEVICE_174B7450";
        case PciSubDevice10026779::SUBDEVICE_174BE127: return "SUBDEVICE_174BE127";
        case PciSubDevice10026779::SUBDEVICE_174BE153: return "SUBDEVICE_174BE153";
        case PciSubDevice10026779::SUBDEVICE_174BE164: return "SUBDEVICE_174BE164";
        case PciSubDevice10026779::SUBDEVICE_174BE180: return "SUBDEVICE_174BE180";
        case PciSubDevice10026779::SUBDEVICE_174BE201: return "SUBDEVICE_174BE201";
        case PciSubDevice10026779::SUBDEVICE_17AF8450: return "SUBDEVICE_17AF8450";
        case PciSubDevice10026779::SUBDEVICE_1B0A9096: return "SUBDEVICE_1B0A9096";
        case PciSubDevice10026779::SUBDEVICE_1B0A9097: return "SUBDEVICE_1B0A9097";
        case PciSubDevice10026779::SUBDEVICE_1B0A90A8: return "SUBDEVICE_1B0A90A8";
        case PciSubDevice10026779::SUBDEVICE_1B0A90B1: return "SUBDEVICE_1B0A90B1";
        case PciSubDevice10026779::SUBDEVICE_1B0A90B3: return "SUBDEVICE_1B0A90B3";
        case PciSubDevice10026779::SUBDEVICE_1B0A90BB: return "SUBDEVICE_1B0A90BB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026779 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026779 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026779::SUBDEVICE_10190016: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_10190017: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_10190018: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_10282120: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_103C2128: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_103C2AEE: return "Radeon HD 7450A";
        case PciSubDevice10026779::SUBDEVICE_10926450: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_14622125: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_14622346: return "Radeon HD 7450";
        case PciSubDevice10026779::SUBDEVICE_14622490: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_14622494: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_14622496: return "Radeon HD 7450";
        case PciSubDevice10026779::SUBDEVICE_148C7450: return "Radeon HD 7450";
        case PciSubDevice10026779::SUBDEVICE_148C8450: return "Radeon HD 8450 OEM";
        case PciSubDevice10026779::SUBDEVICE_15457470: return "Radeon HD 7470";
        case PciSubDevice10026779::SUBDEVICE_16423A65: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_16423A66: return "Radeon HD 7450";
        case PciSubDevice10026779::SUBDEVICE_16423A75: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_16423A76: return "Radeon HD 7450";
        case PciSubDevice10026779::SUBDEVICE_16823200: return "Radeon HD 7450";
        case PciSubDevice10026779::SUBDEVICE_174B7450: return "Radeon HD 7450";
        case PciSubDevice10026779::SUBDEVICE_174BE127: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_174BE153: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_174BE164: return "Radeon HD 6450 1 GB DDR3";
        case PciSubDevice10026779::SUBDEVICE_174BE180: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_174BE201: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_17AF8450: return "Radeon HD 8450 OEM";
        case PciSubDevice10026779::SUBDEVICE_1B0A9096: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_1B0A9097: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_1B0A90A8: return "Radeon HD 6450A";
        case PciSubDevice10026779::SUBDEVICE_1B0A90B1: return "Radeon HD 6450";
        case PciSubDevice10026779::SUBDEVICE_1B0A90B3: return "Radeon HD 7450A";
        case PciSubDevice10026779::SUBDEVICE_1B0A90BB: return "Radeon HD 7450A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026779_H
