// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862485_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862485_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862485: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10135959 = 0x10135959,
    SUBDEVICE_10140222 = 0x10140222,
    SUBDEVICE_10140508 = 0x10140508,
    SUBDEVICE_1014051C = 0x1014051C,
    SUBDEVICE_10431583 = 0x10431583,
    SUBDEVICE_10431623 = 0x10431623,
    SUBDEVICE_10431643 = 0x10431643,
    SUBDEVICE_104D80E7 = 0x104D80E7,
    SUBDEVICE_144DC006 = 0x144DC006
};



inline const char8* enumToString(PciSubDevice80862485 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862485::NONE:               return "NONE";
        case PciSubDevice80862485::SUBDEVICE_10135959: return "SUBDEVICE_10135959";
        case PciSubDevice80862485::SUBDEVICE_10140222: return "SUBDEVICE_10140222";
        case PciSubDevice80862485::SUBDEVICE_10140508: return "SUBDEVICE_10140508";
        case PciSubDevice80862485::SUBDEVICE_1014051C: return "SUBDEVICE_1014051C";
        case PciSubDevice80862485::SUBDEVICE_10431583: return "SUBDEVICE_10431583";
        case PciSubDevice80862485::SUBDEVICE_10431623: return "SUBDEVICE_10431623";
        case PciSubDevice80862485::SUBDEVICE_10431643: return "SUBDEVICE_10431643";
        case PciSubDevice80862485::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";
        case PciSubDevice80862485::SUBDEVICE_144DC006: return "SUBDEVICE_144DC006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862485 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862485 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862485::SUBDEVICE_10135959: return "Crystal WMD Audio Codec";
        case PciSubDevice80862485::SUBDEVICE_10140222: return "ThinkPad A30/A30p/T23";
        case PciSubDevice80862485::SUBDEVICE_10140508: return "ThinkPad T30";
        case PciSubDevice80862485::SUBDEVICE_1014051C: return "ThinkPad A/T/X Series";
        case PciSubDevice80862485::SUBDEVICE_10431583: return "L3C (SPDIF)";
        case PciSubDevice80862485::SUBDEVICE_10431623: return "L2B (no SPDIF)";
        case PciSubDevice80862485::SUBDEVICE_10431643: return "L3F";
        case PciSubDevice80862485::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";
        case PciSubDevice80862485::SUBDEVICE_144DC006: return "vpr Matrix 170B4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862485_H
