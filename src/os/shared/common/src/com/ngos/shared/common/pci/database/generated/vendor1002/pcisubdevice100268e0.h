// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268E0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280404 = 0x10280404,
    SUBDEVICE_10280414 = 0x10280414,
    SUBDEVICE_10280434 = 0x10280434,
    SUBDEVICE_103C1433 = 0x103C1433,
    SUBDEVICE_103C1434 = 0x103C1434,
    SUBDEVICE_103C1469 = 0x103C1469,
    SUBDEVICE_103C146B = 0x103C146B,
    SUBDEVICE_103C1486 = 0x103C1486,
    SUBDEVICE_103C1622 = 0x103C1622,
    SUBDEVICE_103C1623 = 0x103C1623,
    SUBDEVICE_103CEEEE = 0x103CEEEE,
    SUBDEVICE_104D9076 = 0x104D9076,
    SUBDEVICE_1682304E = 0x1682304E,
    SUBDEVICE_16826000 = 0x16826000,
    SUBDEVICE_17AA9E52 = 0x17AA9E52,
    SUBDEVICE_17AA9E53 = 0x17AA9E53
};



inline const char8* enumToString(PciSubDevice100268E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268E0::NONE:               return "NONE";
        case PciSubDevice100268E0::SUBDEVICE_10280404: return "SUBDEVICE_10280404";
        case PciSubDevice100268E0::SUBDEVICE_10280414: return "SUBDEVICE_10280414";
        case PciSubDevice100268E0::SUBDEVICE_10280434: return "SUBDEVICE_10280434";
        case PciSubDevice100268E0::SUBDEVICE_103C1433: return "SUBDEVICE_103C1433";
        case PciSubDevice100268E0::SUBDEVICE_103C1434: return "SUBDEVICE_103C1434";
        case PciSubDevice100268E0::SUBDEVICE_103C1469: return "SUBDEVICE_103C1469";
        case PciSubDevice100268E0::SUBDEVICE_103C146B: return "SUBDEVICE_103C146B";
        case PciSubDevice100268E0::SUBDEVICE_103C1486: return "SUBDEVICE_103C1486";
        case PciSubDevice100268E0::SUBDEVICE_103C1622: return "SUBDEVICE_103C1622";
        case PciSubDevice100268E0::SUBDEVICE_103C1623: return "SUBDEVICE_103C1623";
        case PciSubDevice100268E0::SUBDEVICE_103CEEEE: return "SUBDEVICE_103CEEEE";
        case PciSubDevice100268E0::SUBDEVICE_104D9076: return "SUBDEVICE_104D9076";
        case PciSubDevice100268E0::SUBDEVICE_1682304E: return "SUBDEVICE_1682304E";
        case PciSubDevice100268E0::SUBDEVICE_16826000: return "SUBDEVICE_16826000";
        case PciSubDevice100268E0::SUBDEVICE_17AA9E52: return "SUBDEVICE_17AA9E52";
        case PciSubDevice100268E0::SUBDEVICE_17AA9E53: return "SUBDEVICE_17AA9E53";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268E0::SUBDEVICE_10280404: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_10280414: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_10280434: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_103C1433: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_103C1434: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_103C1469: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_103C146B: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_103C1486: return "TouchSmart tm2-2050er discrete GPU (Mobility Radeon HD 5450)";
        case PciSubDevice100268E0::SUBDEVICE_103C1622: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_103C1623: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_103CEEEE: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_104D9076: return "Mobility Radeon HD 5450";
        case PciSubDevice100268E0::SUBDEVICE_1682304E: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E0::SUBDEVICE_16826000: return "Caicos [Radeon HD 5450]";
        case PciSubDevice100268E0::SUBDEVICE_17AA9E52: return "FirePro M3800";
        case PciSubDevice100268E0::SUBDEVICE_17AA9E53: return "FirePro M3800";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E0_H
