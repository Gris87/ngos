// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026758_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026758_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026758: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280B0E = 0x10280B0E,
    SUBDEVICE_103C6882 = 0x103C6882,
    SUBDEVICE_1462250A = 0x1462250A,
    SUBDEVICE_148C7670 = 0x148C7670,
    SUBDEVICE_15457670 = 0x15457670,
    SUBDEVICE_16823300 = 0x16823300,
    SUBDEVICE_174B7670 = 0x174B7670,
    SUBDEVICE_174BE181 = 0x174BE181,
    SUBDEVICE_17872309 = 0x17872309
};



inline const char8* enumToString(PciSubDevice10026758 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026758::NONE:               return "NONE";
        case PciSubDevice10026758::SUBDEVICE_10280B0E: return "SUBDEVICE_10280B0E";
        case PciSubDevice10026758::SUBDEVICE_103C6882: return "SUBDEVICE_103C6882";
        case PciSubDevice10026758::SUBDEVICE_1462250A: return "SUBDEVICE_1462250A";
        case PciSubDevice10026758::SUBDEVICE_148C7670: return "SUBDEVICE_148C7670";
        case PciSubDevice10026758::SUBDEVICE_15457670: return "SUBDEVICE_15457670";
        case PciSubDevice10026758::SUBDEVICE_16823300: return "SUBDEVICE_16823300";
        case PciSubDevice10026758::SUBDEVICE_174B7670: return "SUBDEVICE_174B7670";
        case PciSubDevice10026758::SUBDEVICE_174BE181: return "SUBDEVICE_174BE181";
        case PciSubDevice10026758::SUBDEVICE_17872309: return "SUBDEVICE_17872309";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026758 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026758 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026758::SUBDEVICE_10280B0E: return "Radeon HD 6670";
        case PciSubDevice10026758::SUBDEVICE_103C6882: return "Radeon HD 6670";
        case PciSubDevice10026758::SUBDEVICE_1462250A: return "Radeon HD 7670";
        case PciSubDevice10026758::SUBDEVICE_148C7670: return "Radeon HD 7670";
        case PciSubDevice10026758::SUBDEVICE_15457670: return "Radeon HD 7670";
        case PciSubDevice10026758::SUBDEVICE_16823300: return "Radeon HD 7670";
        case PciSubDevice10026758::SUBDEVICE_174B7670: return "Radeon HD 7670";
        case PciSubDevice10026758::SUBDEVICE_174BE181: return "Radeon HD 6670";
        case PciSubDevice10026758::SUBDEVICE_17872309: return "Radeon HD 6670";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026758_H
