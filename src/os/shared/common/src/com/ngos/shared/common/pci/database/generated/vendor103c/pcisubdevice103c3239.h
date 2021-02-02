// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3239_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3239_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C3239: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C21BD = 0x103C21BD,
    SUBDEVICE_103C21BE = 0x103C21BE,
    SUBDEVICE_103C21BF = 0x103C21BF,
    SUBDEVICE_103C21C0 = 0x103C21C0,
    SUBDEVICE_103C21C1 = 0x103C21C1,
    SUBDEVICE_103C21C2 = 0x103C21C2,
    SUBDEVICE_103C21C3 = 0x103C21C3,
    SUBDEVICE_103C21C4 = 0x103C21C4,
    SUBDEVICE_103C21C5 = 0x103C21C5,
    SUBDEVICE_103C21C6 = 0x103C21C6,
    SUBDEVICE_103C21C7 = 0x103C21C7,
    SUBDEVICE_103C21C8 = 0x103C21C8,
    SUBDEVICE_103C21C9 = 0x103C21C9,
    SUBDEVICE_103C21CA = 0x103C21CA,
    SUBDEVICE_103C21CB = 0x103C21CB,
    SUBDEVICE_103C21CC = 0x103C21CC,
    SUBDEVICE_103C21CD = 0x103C21CD,
    SUBDEVICE_103C21CE = 0x103C21CE
};



inline const char8* enumToString(PciSubDevice103C3239 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3239::NONE:               return "NONE";
        case PciSubDevice103C3239::SUBDEVICE_103C21BD: return "SUBDEVICE_103C21BD";
        case PciSubDevice103C3239::SUBDEVICE_103C21BE: return "SUBDEVICE_103C21BE";
        case PciSubDevice103C3239::SUBDEVICE_103C21BF: return "SUBDEVICE_103C21BF";
        case PciSubDevice103C3239::SUBDEVICE_103C21C0: return "SUBDEVICE_103C21C0";
        case PciSubDevice103C3239::SUBDEVICE_103C21C1: return "SUBDEVICE_103C21C1";
        case PciSubDevice103C3239::SUBDEVICE_103C21C2: return "SUBDEVICE_103C21C2";
        case PciSubDevice103C3239::SUBDEVICE_103C21C3: return "SUBDEVICE_103C21C3";
        case PciSubDevice103C3239::SUBDEVICE_103C21C4: return "SUBDEVICE_103C21C4";
        case PciSubDevice103C3239::SUBDEVICE_103C21C5: return "SUBDEVICE_103C21C5";
        case PciSubDevice103C3239::SUBDEVICE_103C21C6: return "SUBDEVICE_103C21C6";
        case PciSubDevice103C3239::SUBDEVICE_103C21C7: return "SUBDEVICE_103C21C7";
        case PciSubDevice103C3239::SUBDEVICE_103C21C8: return "SUBDEVICE_103C21C8";
        case PciSubDevice103C3239::SUBDEVICE_103C21C9: return "SUBDEVICE_103C21C9";
        case PciSubDevice103C3239::SUBDEVICE_103C21CA: return "SUBDEVICE_103C21CA";
        case PciSubDevice103C3239::SUBDEVICE_103C21CB: return "SUBDEVICE_103C21CB";
        case PciSubDevice103C3239::SUBDEVICE_103C21CC: return "SUBDEVICE_103C21CC";
        case PciSubDevice103C3239::SUBDEVICE_103C21CD: return "SUBDEVICE_103C21CD";
        case PciSubDevice103C3239::SUBDEVICE_103C21CE: return "SUBDEVICE_103C21CE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C3239 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C3239 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3239::SUBDEVICE_103C21BD: return "P244br";
        case PciSubDevice103C3239::SUBDEVICE_103C21BE: return "P741m";
        case PciSubDevice103C3239::SUBDEVICE_103C21BF: return "H240ar";
        case PciSubDevice103C3239::SUBDEVICE_103C21C0: return "P440ar";
        case PciSubDevice103C3239::SUBDEVICE_103C21C1: return "P840ar";
        case PciSubDevice103C3239::SUBDEVICE_103C21C2: return "P440";
        case PciSubDevice103C3239::SUBDEVICE_103C21C3: return "P441";
        case PciSubDevice103C3239::SUBDEVICE_103C21C4: return "Smart Array";
        case PciSubDevice103C3239::SUBDEVICE_103C21C5: return "P841";
        case PciSubDevice103C3239::SUBDEVICE_103C21C6: return "H244br";
        case PciSubDevice103C3239::SUBDEVICE_103C21C7: return "H240";
        case PciSubDevice103C3239::SUBDEVICE_103C21C8: return "H241";
        case PciSubDevice103C3239::SUBDEVICE_103C21C9: return "Smart Array";
        case PciSubDevice103C3239::SUBDEVICE_103C21CA: return "P246br";
        case PciSubDevice103C3239::SUBDEVICE_103C21CB: return "P840";
        case PciSubDevice103C3239::SUBDEVICE_103C21CC: return "Smart Array";
        case PciSubDevice103C3239::SUBDEVICE_103C21CD: return "P240nr";
        case PciSubDevice103C3239::SUBDEVICE_103C21CE: return "H240nr";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3239_H
