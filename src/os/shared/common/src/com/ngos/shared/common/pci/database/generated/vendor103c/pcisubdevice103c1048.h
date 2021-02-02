// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1048_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1048_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C1048: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1049 = 0x103C1049,
    SUBDEVICE_103C104A = 0x103C104A,
    SUBDEVICE_103C104B = 0x103C104B,
    SUBDEVICE_103C1223 = 0x103C1223,
    SUBDEVICE_103C1226 = 0x103C1226,
    SUBDEVICE_103C1227 = 0x103C1227,
    SUBDEVICE_103C1282 = 0x103C1282,
    SUBDEVICE_103C1301 = 0x103C1301
};



inline const char8* enumToString(PciSubDevice103C1048 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C1048::NONE:               return "NONE";
        case PciSubDevice103C1048::SUBDEVICE_103C1049: return "SUBDEVICE_103C1049";
        case PciSubDevice103C1048::SUBDEVICE_103C104A: return "SUBDEVICE_103C104A";
        case PciSubDevice103C1048::SUBDEVICE_103C104B: return "SUBDEVICE_103C104B";
        case PciSubDevice103C1048::SUBDEVICE_103C1223: return "SUBDEVICE_103C1223";
        case PciSubDevice103C1048::SUBDEVICE_103C1226: return "SUBDEVICE_103C1226";
        case PciSubDevice103C1048::SUBDEVICE_103C1227: return "SUBDEVICE_103C1227";
        case PciSubDevice103C1048::SUBDEVICE_103C1282: return "SUBDEVICE_103C1282";
        case PciSubDevice103C1048::SUBDEVICE_103C1301: return "SUBDEVICE_103C1301";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C1048 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C1048 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C1048::SUBDEVICE_103C1049: return "Tosca Console";
        case PciSubDevice103C1048::SUBDEVICE_103C104A: return "Tosca Secondary";
        case PciSubDevice103C1048::SUBDEVICE_103C104B: return "Maestro SP2";
        case PciSubDevice103C1048::SUBDEVICE_103C1223: return "Superdome Console";
        case PciSubDevice103C1048::SUBDEVICE_103C1226: return "Keystone SP2";
        case PciSubDevice103C1048::SUBDEVICE_103C1227: return "Powerbar SP2";
        case PciSubDevice103C1048::SUBDEVICE_103C1282: return "Everest SP2";
        case PciSubDevice103C1048::SUBDEVICE_103C1301: return "Diva RMP3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C1048_H
