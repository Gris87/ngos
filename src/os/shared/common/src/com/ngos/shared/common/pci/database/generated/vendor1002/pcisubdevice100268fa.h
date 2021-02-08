// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268FA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268FA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268FA: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190019 = 0x10190019,
    SUBDEVICE_10190021 = 0x10190021,
    SUBDEVICE_10190022 = 0x10190022,
    SUBDEVICE_10190026 = 0x10190026,
    SUBDEVICE_103C2ADF = 0x103C2ADF,
    SUBDEVICE_103C2AE8 = 0x103C2AE8,
    SUBDEVICE_10438350 = 0x10438350,
    SUBDEVICE_14622128 = 0x14622128,
    SUBDEVICE_14622184 = 0x14622184,
    SUBDEVICE_14622186 = 0x14622186,
    SUBDEVICE_14622495 = 0x14622495,
    SUBDEVICE_1462B490 = 0x1462B490,
    SUBDEVICE_16423985 = 0x16423985,
    SUBDEVICE_174B3510 = 0x174B3510,
    SUBDEVICE_174B3521 = 0x174B3521,
    SUBDEVICE_174B3522 = 0x174B3522,
    SUBDEVICE_174B7350 = 0x174B7350,
    SUBDEVICE_174B8153 = 0x174B8153,
    SUBDEVICE_174BE127 = 0x174BE127,
    SUBDEVICE_174BE153 = 0x174BE153,
    SUBDEVICE_174BE180 = 0x174BE180,
    SUBDEVICE_17AF3015 = 0x17AF3015
};



inline const char8* enumToString(PciSubDevice100268FA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268FA::NONE:               return "NONE";
        case PciSubDevice100268FA::SUBDEVICE_10190019: return "SUBDEVICE_10190019";
        case PciSubDevice100268FA::SUBDEVICE_10190021: return "SUBDEVICE_10190021";
        case PciSubDevice100268FA::SUBDEVICE_10190022: return "SUBDEVICE_10190022";
        case PciSubDevice100268FA::SUBDEVICE_10190026: return "SUBDEVICE_10190026";
        case PciSubDevice100268FA::SUBDEVICE_103C2ADF: return "SUBDEVICE_103C2ADF";
        case PciSubDevice100268FA::SUBDEVICE_103C2AE8: return "SUBDEVICE_103C2AE8";
        case PciSubDevice100268FA::SUBDEVICE_10438350: return "SUBDEVICE_10438350";
        case PciSubDevice100268FA::SUBDEVICE_14622128: return "SUBDEVICE_14622128";
        case PciSubDevice100268FA::SUBDEVICE_14622184: return "SUBDEVICE_14622184";
        case PciSubDevice100268FA::SUBDEVICE_14622186: return "SUBDEVICE_14622186";
        case PciSubDevice100268FA::SUBDEVICE_14622495: return "SUBDEVICE_14622495";
        case PciSubDevice100268FA::SUBDEVICE_1462B490: return "SUBDEVICE_1462B490";
        case PciSubDevice100268FA::SUBDEVICE_16423985: return "SUBDEVICE_16423985";
        case PciSubDevice100268FA::SUBDEVICE_174B3510: return "SUBDEVICE_174B3510";
        case PciSubDevice100268FA::SUBDEVICE_174B3521: return "SUBDEVICE_174B3521";
        case PciSubDevice100268FA::SUBDEVICE_174B3522: return "SUBDEVICE_174B3522";
        case PciSubDevice100268FA::SUBDEVICE_174B7350: return "SUBDEVICE_174B7350";
        case PciSubDevice100268FA::SUBDEVICE_174B8153: return "SUBDEVICE_174B8153";
        case PciSubDevice100268FA::SUBDEVICE_174BE127: return "SUBDEVICE_174BE127";
        case PciSubDevice100268FA::SUBDEVICE_174BE153: return "SUBDEVICE_174BE153";
        case PciSubDevice100268FA::SUBDEVICE_174BE180: return "SUBDEVICE_174BE180";
        case PciSubDevice100268FA::SUBDEVICE_17AF3015: return "SUBDEVICE_17AF3015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268FA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268FA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268FA::SUBDEVICE_10190019: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_10190021: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_10190022: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_10190026: return "Radeon HD 8350";
        case PciSubDevice100268FA::SUBDEVICE_103C2ADF: return "Radeon HD 7350A";
        case PciSubDevice100268FA::SUBDEVICE_103C2AE8: return "Radeon HD 7350A";
        case PciSubDevice100268FA::SUBDEVICE_10438350: return "Radeon HD 8350";
        case PciSubDevice100268FA::SUBDEVICE_14622128: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_14622184: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_14622186: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_14622495: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_1462B490: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_16423985: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_174B3510: return "Radeon HD 8350";
        case PciSubDevice100268FA::SUBDEVICE_174B3521: return "Radeon R5 220";
        case PciSubDevice100268FA::SUBDEVICE_174B3522: return "Radeon R5 220";
        case PciSubDevice100268FA::SUBDEVICE_174B7350: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_174B8153: return "Radeon HD 8350";
        case PciSubDevice100268FA::SUBDEVICE_174BE127: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_174BE153: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_174BE180: return "Radeon HD 7350";
        case PciSubDevice100268FA::SUBDEVICE_17AF3015: return "Radeon HD 7350";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268FA_H
