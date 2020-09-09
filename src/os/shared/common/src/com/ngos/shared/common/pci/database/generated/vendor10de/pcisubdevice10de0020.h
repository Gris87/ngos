// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0020: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430200 = 0x10430200,
    SUBDEVICE_10480C18 = 0x10480C18,
    SUBDEVICE_10480C19 = 0x10480C19,
    SUBDEVICE_10480C1B = 0x10480C1B,
    SUBDEVICE_10480C1C = 0x10480C1C,
    SUBDEVICE_10920550 = 0x10920550,
    SUBDEVICE_10920552 = 0x10920552,
    SUBDEVICE_10924804 = 0x10924804,
    SUBDEVICE_10924808 = 0x10924808,
    SUBDEVICE_10924810 = 0x10924810,
    SUBDEVICE_10924812 = 0x10924812,
    SUBDEVICE_10924815 = 0x10924815,
    SUBDEVICE_10924820 = 0x10924820,
    SUBDEVICE_10924822 = 0x10924822,
    SUBDEVICE_10924904 = 0x10924904,
    SUBDEVICE_10924914 = 0x10924914,
    SUBDEVICE_10928225 = 0x10928225,
    SUBDEVICE_10B4273D = 0x10B4273D,
    SUBDEVICE_10B4273E = 0x10B4273E,
    SUBDEVICE_10B42740 = 0x10B42740,
    SUBDEVICE_10DE0020 = 0x10DE0020,
    SUBDEVICE_11021015 = 0x11021015,
    SUBDEVICE_11021016 = 0x11021016
};



inline const char8* enumToString(PciSubDevice10DE0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0020::NONE:               return "NONE";
        case PciSubDevice10DE0020::SUBDEVICE_10430200: return "SUBDEVICE_10430200";
        case PciSubDevice10DE0020::SUBDEVICE_10480C18: return "SUBDEVICE_10480C18";
        case PciSubDevice10DE0020::SUBDEVICE_10480C19: return "SUBDEVICE_10480C19";
        case PciSubDevice10DE0020::SUBDEVICE_10480C1B: return "SUBDEVICE_10480C1B";
        case PciSubDevice10DE0020::SUBDEVICE_10480C1C: return "SUBDEVICE_10480C1C";
        case PciSubDevice10DE0020::SUBDEVICE_10920550: return "SUBDEVICE_10920550";
        case PciSubDevice10DE0020::SUBDEVICE_10920552: return "SUBDEVICE_10920552";
        case PciSubDevice10DE0020::SUBDEVICE_10924804: return "SUBDEVICE_10924804";
        case PciSubDevice10DE0020::SUBDEVICE_10924808: return "SUBDEVICE_10924808";
        case PciSubDevice10DE0020::SUBDEVICE_10924810: return "SUBDEVICE_10924810";
        case PciSubDevice10DE0020::SUBDEVICE_10924812: return "SUBDEVICE_10924812";
        case PciSubDevice10DE0020::SUBDEVICE_10924815: return "SUBDEVICE_10924815";
        case PciSubDevice10DE0020::SUBDEVICE_10924820: return "SUBDEVICE_10924820";
        case PciSubDevice10DE0020::SUBDEVICE_10924822: return "SUBDEVICE_10924822";
        case PciSubDevice10DE0020::SUBDEVICE_10924904: return "SUBDEVICE_10924904";
        case PciSubDevice10DE0020::SUBDEVICE_10924914: return "SUBDEVICE_10924914";
        case PciSubDevice10DE0020::SUBDEVICE_10928225: return "SUBDEVICE_10928225";
        case PciSubDevice10DE0020::SUBDEVICE_10B4273D: return "SUBDEVICE_10B4273D";
        case PciSubDevice10DE0020::SUBDEVICE_10B4273E: return "SUBDEVICE_10B4273E";
        case PciSubDevice10DE0020::SUBDEVICE_10B42740: return "SUBDEVICE_10B42740";
        case PciSubDevice10DE0020::SUBDEVICE_10DE0020: return "SUBDEVICE_10DE0020";
        case PciSubDevice10DE0020::SUBDEVICE_11021015: return "SUBDEVICE_11021015";
        case PciSubDevice10DE0020::SUBDEVICE_11021016: return "SUBDEVICE_11021016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0020::SUBDEVICE_10430200: return "V3400 TNT";
        case PciSubDevice10DE0020::SUBDEVICE_10480C18: return "Erazor II SGRAM";
        case PciSubDevice10DE0020::SUBDEVICE_10480C19: return "Erazor II";
        case PciSubDevice10DE0020::SUBDEVICE_10480C1B: return "Erazor II";
        case PciSubDevice10DE0020::SUBDEVICE_10480C1C: return "Erazor II";
        case PciSubDevice10DE0020::SUBDEVICE_10920550: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10920552: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924804: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924808: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924810: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924812: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924815: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924820: return "Viper V550 with TV out";
        case PciSubDevice10DE0020::SUBDEVICE_10924822: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924904: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10924914: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10928225: return "Viper V550";
        case PciSubDevice10DE0020::SUBDEVICE_10B4273D: return "Velocity 4400";
        case PciSubDevice10DE0020::SUBDEVICE_10B4273E: return "Velocity 4400";
        case PciSubDevice10DE0020::SUBDEVICE_10B42740: return "Velocity 4400";
        case PciSubDevice10DE0020::SUBDEVICE_10DE0020: return "Riva TNT";
        case PciSubDevice10DE0020::SUBDEVICE_11021015: return "Graphics Blaster CT6710";
        case PciSubDevice10DE0020::SUBDEVICE_11021016: return "Graphics Blaster RIVA TNT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0020_H
