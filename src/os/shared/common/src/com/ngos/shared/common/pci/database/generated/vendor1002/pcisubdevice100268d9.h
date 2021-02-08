// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268D9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268D9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268D9: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C6870 = 0x103C6870,
    SUBDEVICE_103C6872 = 0x103C6872,
    SUBDEVICE_104303CE = 0x104303CE,
    SUBDEVICE_14622151 = 0x14622151,
    SUBDEVICE_14622240 = 0x14622240,
    SUBDEVICE_148C3000 = 0x148C3000,
    SUBDEVICE_148C3001 = 0x148C3001,
    SUBDEVICE_15455550 = 0x15455550,
    SUBDEVICE_15457570 = 0x15457570,
    SUBDEVICE_16423985 = 0x16423985,
    SUBDEVICE_16423996 = 0x16423996,
    SUBDEVICE_174B3000 = 0x174B3000,
    SUBDEVICE_174B6510 = 0x174B6510,
    SUBDEVICE_174B6610 = 0x174B6610,
    SUBDEVICE_174BE142 = 0x174BE142,
    SUBDEVICE_17873000 = 0x17873000,
    SUBDEVICE_17AF3000 = 0x17AF3000,
    SUBDEVICE_17AF3010 = 0x17AF3010
};



inline const char8* enumToString(PciSubDevice100268D9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268D9::NONE:               return "NONE";
        case PciSubDevice100268D9::SUBDEVICE_103C6870: return "SUBDEVICE_103C6870";
        case PciSubDevice100268D9::SUBDEVICE_103C6872: return "SUBDEVICE_103C6872";
        case PciSubDevice100268D9::SUBDEVICE_104303CE: return "SUBDEVICE_104303CE";
        case PciSubDevice100268D9::SUBDEVICE_14622151: return "SUBDEVICE_14622151";
        case PciSubDevice100268D9::SUBDEVICE_14622240: return "SUBDEVICE_14622240";
        case PciSubDevice100268D9::SUBDEVICE_148C3000: return "SUBDEVICE_148C3000";
        case PciSubDevice100268D9::SUBDEVICE_148C3001: return "SUBDEVICE_148C3001";
        case PciSubDevice100268D9::SUBDEVICE_15455550: return "SUBDEVICE_15455550";
        case PciSubDevice100268D9::SUBDEVICE_15457570: return "SUBDEVICE_15457570";
        case PciSubDevice100268D9::SUBDEVICE_16423985: return "SUBDEVICE_16423985";
        case PciSubDevice100268D9::SUBDEVICE_16423996: return "SUBDEVICE_16423996";
        case PciSubDevice100268D9::SUBDEVICE_174B3000: return "SUBDEVICE_174B3000";
        case PciSubDevice100268D9::SUBDEVICE_174B6510: return "SUBDEVICE_174B6510";
        case PciSubDevice100268D9::SUBDEVICE_174B6610: return "SUBDEVICE_174B6610";
        case PciSubDevice100268D9::SUBDEVICE_174BE142: return "SUBDEVICE_174BE142";
        case PciSubDevice100268D9::SUBDEVICE_17873000: return "SUBDEVICE_17873000";
        case PciSubDevice100268D9::SUBDEVICE_17AF3000: return "SUBDEVICE_17AF3000";
        case PciSubDevice100268D9::SUBDEVICE_17AF3010: return "SUBDEVICE_17AF3010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268D9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268D9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268D9::SUBDEVICE_103C6870: return "Radeon HD 5570";
        case PciSubDevice100268D9::SUBDEVICE_103C6872: return "Radeon HD 5570";
        case PciSubDevice100268D9::SUBDEVICE_104303CE: return "Radeon HD 5550";
        case PciSubDevice100268D9::SUBDEVICE_14622151: return "Radeon HD 5570";
        case PciSubDevice100268D9::SUBDEVICE_14622240: return "Radeon HD 5570";
        case PciSubDevice100268D9::SUBDEVICE_148C3000: return "Radeon HD 6510";
        case PciSubDevice100268D9::SUBDEVICE_148C3001: return "Radeon HD 6610";
        case PciSubDevice100268D9::SUBDEVICE_15455550: return "Radeon HD 5550";
        case PciSubDevice100268D9::SUBDEVICE_15457570: return "Radeon HD 7570";
        case PciSubDevice100268D9::SUBDEVICE_16423985: return "Radeon HD 5570";
        case PciSubDevice100268D9::SUBDEVICE_16423996: return "Radeon HD 5570";
        case PciSubDevice100268D9::SUBDEVICE_174B3000: return "Radeon HD 6510";
        case PciSubDevice100268D9::SUBDEVICE_174B6510: return "Radeon HD 6510";
        case PciSubDevice100268D9::SUBDEVICE_174B6610: return "Radeon HD 6610";
        case PciSubDevice100268D9::SUBDEVICE_174BE142: return "Radeon HD 5570";
        case PciSubDevice100268D9::SUBDEVICE_17873000: return "Radeon HD 6510";
        case PciSubDevice100268D9::SUBDEVICE_17AF3000: return "Radeon HD 6510";
        case PciSubDevice100268D9::SUBDEVICE_17AF3010: return "Radeon HD 5630";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268D9_H
