// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026759_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026759_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026759: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3130 = 0x103C3130,
    SUBDEVICE_10430403 = 0x10430403,
    SUBDEVICE_14622500 = 0x14622500,
    SUBDEVICE_14622509 = 0x14622509,
    SUBDEVICE_148C7570 = 0x148C7570,
    SUBDEVICE_16423A67 = 0x16423A67,
    SUBDEVICE_16823280 = 0x16823280,
    SUBDEVICE_16823530 = 0x16823530,
    SUBDEVICE_174B7570 = 0x174B7570,
    SUBDEVICE_174BE142 = 0x174BE142,
    SUBDEVICE_174BE181 = 0x174BE181,
    SUBDEVICE_1B0A908F = 0x1B0A908F,
    SUBDEVICE_1B0A9090 = 0x1B0A9090,
    SUBDEVICE_1B0A9091 = 0x1B0A9091,
    SUBDEVICE_1B0A9092 = 0x1B0A9092,
    SUBDEVICE_1B0A909E = 0x1B0A909E,
    SUBDEVICE_1B0A90B5 = 0x1B0A90B5,
    SUBDEVICE_1B0A90B6 = 0x1B0A90B6
};



inline const char8* enumToString(PciSubDevice10026759 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026759::NONE:               return "NONE";
        case PciSubDevice10026759::SUBDEVICE_103C3130: return "SUBDEVICE_103C3130";
        case PciSubDevice10026759::SUBDEVICE_10430403: return "SUBDEVICE_10430403";
        case PciSubDevice10026759::SUBDEVICE_14622500: return "SUBDEVICE_14622500";
        case PciSubDevice10026759::SUBDEVICE_14622509: return "SUBDEVICE_14622509";
        case PciSubDevice10026759::SUBDEVICE_148C7570: return "SUBDEVICE_148C7570";
        case PciSubDevice10026759::SUBDEVICE_16423A67: return "SUBDEVICE_16423A67";
        case PciSubDevice10026759::SUBDEVICE_16823280: return "SUBDEVICE_16823280";
        case PciSubDevice10026759::SUBDEVICE_16823530: return "SUBDEVICE_16823530";
        case PciSubDevice10026759::SUBDEVICE_174B7570: return "SUBDEVICE_174B7570";
        case PciSubDevice10026759::SUBDEVICE_174BE142: return "SUBDEVICE_174BE142";
        case PciSubDevice10026759::SUBDEVICE_174BE181: return "SUBDEVICE_174BE181";
        case PciSubDevice10026759::SUBDEVICE_1B0A908F: return "SUBDEVICE_1B0A908F";
        case PciSubDevice10026759::SUBDEVICE_1B0A9090: return "SUBDEVICE_1B0A9090";
        case PciSubDevice10026759::SUBDEVICE_1B0A9091: return "SUBDEVICE_1B0A9091";
        case PciSubDevice10026759::SUBDEVICE_1B0A9092: return "SUBDEVICE_1B0A9092";
        case PciSubDevice10026759::SUBDEVICE_1B0A909E: return "SUBDEVICE_1B0A909E";
        case PciSubDevice10026759::SUBDEVICE_1B0A90B5: return "SUBDEVICE_1B0A90B5";
        case PciSubDevice10026759::SUBDEVICE_1B0A90B6: return "SUBDEVICE_1B0A90B6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026759 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026759 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026759::SUBDEVICE_103C3130: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_10430403: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_14622500: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_14622509: return "Radeon HD 7570";
        case PciSubDevice10026759::SUBDEVICE_148C7570: return "Radeon HD 7570";
        case PciSubDevice10026759::SUBDEVICE_16423A67: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_16823280: return "Radeon HD 7570";
        case PciSubDevice10026759::SUBDEVICE_16823530: return "Radeon HD 8550";
        case PciSubDevice10026759::SUBDEVICE_174B7570: return "Radeon HD 7570";
        case PciSubDevice10026759::SUBDEVICE_174BE142: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_174BE181: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_1B0A908F: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_1B0A9090: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_1B0A9091: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_1B0A9092: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_1B0A909E: return "Radeon HD 6570";
        case PciSubDevice10026759::SUBDEVICE_1B0A90B5: return "Radeon HD 7570";
        case PciSubDevice10026759::SUBDEVICE_1B0A90B6: return "Radeon HD 7570";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026759_H
