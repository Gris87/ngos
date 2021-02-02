// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063058_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063058_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063058: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110097 = 0x0E110097,
    SUBDEVICE_0E11B194 = 0x0E11B194,
    SUBDEVICE_10190985 = 0x10190985,
    SUBDEVICE_10190987 = 0x10190987,
    SUBDEVICE_103C1251 = 0x103C1251,
    SUBDEVICE_10431106 = 0x10431106,
    SUBDEVICE_11064511 = 0x11064511,
    SUBDEVICE_1106AA03 = 0x1106AA03,
    SUBDEVICE_11D45348 = 0x11D45348,
    SUBDEVICE_14587600 = 0x14587600,
    SUBDEVICE_14623091 = 0x14623091,
    SUBDEVICE_14623092 = 0x14623092,
    SUBDEVICE_14623300 = 0x14623300,
    SUBDEVICE_14623400 = 0x14623400,
    SUBDEVICE_15DD7609 = 0x15DD7609
};



inline const char8* enumToString(PciSubDevice11063058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063058::NONE:               return "NONE";
        case PciSubDevice11063058::SUBDEVICE_0E110097: return "SUBDEVICE_0E110097";
        case PciSubDevice11063058::SUBDEVICE_0E11B194: return "SUBDEVICE_0E11B194";
        case PciSubDevice11063058::SUBDEVICE_10190985: return "SUBDEVICE_10190985";
        case PciSubDevice11063058::SUBDEVICE_10190987: return "SUBDEVICE_10190987";
        case PciSubDevice11063058::SUBDEVICE_103C1251: return "SUBDEVICE_103C1251";
        case PciSubDevice11063058::SUBDEVICE_10431106: return "SUBDEVICE_10431106";
        case PciSubDevice11063058::SUBDEVICE_11064511: return "SUBDEVICE_11064511";
        case PciSubDevice11063058::SUBDEVICE_1106AA03: return "SUBDEVICE_1106AA03";
        case PciSubDevice11063058::SUBDEVICE_11D45348: return "SUBDEVICE_11D45348";
        case PciSubDevice11063058::SUBDEVICE_14587600: return "SUBDEVICE_14587600";
        case PciSubDevice11063058::SUBDEVICE_14623091: return "SUBDEVICE_14623091";
        case PciSubDevice11063058::SUBDEVICE_14623092: return "SUBDEVICE_14623092";
        case PciSubDevice11063058::SUBDEVICE_14623300: return "SUBDEVICE_14623300";
        case PciSubDevice11063058::SUBDEVICE_14623400: return "SUBDEVICE_14623400";
        case PciSubDevice11063058::SUBDEVICE_15DD7609: return "SUBDEVICE_15DD7609";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063058::SUBDEVICE_0E110097: return "SoundMax Digital Integrated Audio";
        case PciSubDevice11063058::SUBDEVICE_0E11B194: return "Soundmax integrated digital audio";
        case PciSubDevice11063058::SUBDEVICE_10190985: return "P6VXA Motherboard";
        case PciSubDevice11063058::SUBDEVICE_10190987: return "K7VZA Motherboard";
        case PciSubDevice11063058::SUBDEVICE_103C1251: return "D9840-60001 [Brio BA410 Motherboard]";
        case PciSubDevice11063058::SUBDEVICE_10431106: return "A7V133/A7V133-C Mainboard";
        case PciSubDevice11063058::SUBDEVICE_11064511: return "Onboard Audio on EP7KXA";
        case PciSubDevice11063058::SUBDEVICE_1106AA03: return "VT1612A AC'97 Audio Controller";
        case PciSubDevice11063058::SUBDEVICE_11D45348: return "AD1881A audio";
        case PciSubDevice11063058::SUBDEVICE_14587600: return "Onboard Audio";
        case PciSubDevice11063058::SUBDEVICE_14623091: return "MS-6309 Onboard Audio";
        case PciSubDevice11063058::SUBDEVICE_14623092: return "MS-6309 v2.x Mainboard (VIA VT1611A codec)";
        case PciSubDevice11063058::SUBDEVICE_14623300: return "MS-6330 Onboard Audio";
        case PciSubDevice11063058::SUBDEVICE_14623400: return "MS-6340 (VT8363) motherboard";
        case PciSubDevice11063058::SUBDEVICE_15DD7609: return "Onboard Audio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063058_H
