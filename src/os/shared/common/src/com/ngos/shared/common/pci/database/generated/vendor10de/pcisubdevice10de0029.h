// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0029_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0029_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0029: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430200 = 0x10430200,
    SUBDEVICE_10430201 = 0x10430201,
    SUBDEVICE_10430205 = 0x10430205,
    SUBDEVICE_10480C2E = 0x10480C2E,
    SUBDEVICE_10480C2F = 0x10480C2F,
    SUBDEVICE_10480C30 = 0x10480C30,
    SUBDEVICE_11021021 = 0x11021021,
    SUBDEVICE_11021029 = 0x11021029,
    SUBDEVICE_1102102F = 0x1102102F,
    SUBDEVICE_14AF5820 = 0x14AF5820,
    SUBDEVICE_48434F34 = 0x48434F34
};



inline const char8* enumToString(PciSubDevice10DE0029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0029::NONE:               return "NONE";
        case PciSubDevice10DE0029::SUBDEVICE_10430200: return "SUBDEVICE_10430200";
        case PciSubDevice10DE0029::SUBDEVICE_10430201: return "SUBDEVICE_10430201";
        case PciSubDevice10DE0029::SUBDEVICE_10430205: return "SUBDEVICE_10430205";
        case PciSubDevice10DE0029::SUBDEVICE_10480C2E: return "SUBDEVICE_10480C2E";
        case PciSubDevice10DE0029::SUBDEVICE_10480C2F: return "SUBDEVICE_10480C2F";
        case PciSubDevice10DE0029::SUBDEVICE_10480C30: return "SUBDEVICE_10480C30";
        case PciSubDevice10DE0029::SUBDEVICE_11021021: return "SUBDEVICE_11021021";
        case PciSubDevice10DE0029::SUBDEVICE_11021029: return "SUBDEVICE_11021029";
        case PciSubDevice10DE0029::SUBDEVICE_1102102F: return "SUBDEVICE_1102102F";
        case PciSubDevice10DE0029::SUBDEVICE_14AF5820: return "SUBDEVICE_14AF5820";
        case PciSubDevice10DE0029::SUBDEVICE_48434F34: return "SUBDEVICE_48434F34";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0029::SUBDEVICE_10430200: return "AGP-V3800 Deluxe";
        case PciSubDevice10DE0029::SUBDEVICE_10430201: return "AGP-V3800 Ultra SDRAM";
        case PciSubDevice10DE0029::SUBDEVICE_10430205: return "PCI-V3800 Ultra";
        case PciSubDevice10DE0029::SUBDEVICE_10480C2E: return "Erazor III Ultra";
        case PciSubDevice10DE0029::SUBDEVICE_10480C2F: return "Erazor III Ultra";
        case PciSubDevice10DE0029::SUBDEVICE_10480C30: return "Erazor III Ultra";
        case PciSubDevice10DE0029::SUBDEVICE_11021021: return "3D Blaster RIVA TNT2 Ultra";
        case PciSubDevice10DE0029::SUBDEVICE_11021029: return "3D Blaster RIVA TNT2 Ultra";
        case PciSubDevice10DE0029::SUBDEVICE_1102102F: return "3D Blaster RIVA TNT2 Ultra";
        case PciSubDevice10DE0029::SUBDEVICE_14AF5820: return "Maxi Gamer Xentor 32";
        case PciSubDevice10DE0029::SUBDEVICE_48434F34: return "Dynamite";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0029_H
