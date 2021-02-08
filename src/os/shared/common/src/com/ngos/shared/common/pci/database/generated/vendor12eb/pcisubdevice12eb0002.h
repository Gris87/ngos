// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12EB0002: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104D8049 = 0x104D8049,
    SUBDEVICE_104D807B = 0x104D807B,
    SUBDEVICE_10923000 = 0x10923000,
    SUBDEVICE_10923001 = 0x10923001,
    SUBDEVICE_10923002 = 0x10923002,
    SUBDEVICE_10923003 = 0x10923003,
    SUBDEVICE_10923004 = 0x10923004,
    SUBDEVICE_12EB0002 = 0x12EB0002,
    SUBDEVICE_12EB0088 = 0x12EB0088,
    SUBDEVICE_144D3510 = 0x144D3510,
    SUBDEVICE_50533356 = 0x50533356
};



inline const char8* enumToString(PciSubDevice12EB0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB0002::NONE:               return "NONE";
        case PciSubDevice12EB0002::SUBDEVICE_104D8049: return "SUBDEVICE_104D8049";
        case PciSubDevice12EB0002::SUBDEVICE_104D807B: return "SUBDEVICE_104D807B";
        case PciSubDevice12EB0002::SUBDEVICE_10923000: return "SUBDEVICE_10923000";
        case PciSubDevice12EB0002::SUBDEVICE_10923001: return "SUBDEVICE_10923001";
        case PciSubDevice12EB0002::SUBDEVICE_10923002: return "SUBDEVICE_10923002";
        case PciSubDevice12EB0002::SUBDEVICE_10923003: return "SUBDEVICE_10923003";
        case PciSubDevice12EB0002::SUBDEVICE_10923004: return "SUBDEVICE_10923004";
        case PciSubDevice12EB0002::SUBDEVICE_12EB0002: return "SUBDEVICE_12EB0002";
        case PciSubDevice12EB0002::SUBDEVICE_12EB0088: return "SUBDEVICE_12EB0088";
        case PciSubDevice12EB0002::SUBDEVICE_144D3510: return "SUBDEVICE_144D3510";
        case PciSubDevice12EB0002::SUBDEVICE_50533356: return "SUBDEVICE_50533356";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12EB0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12EB0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB0002::SUBDEVICE_104D8049: return "Au8830 Vortex 3D Digital Audio Processor";
        case PciSubDevice12EB0002::SUBDEVICE_104D807B: return "Au8830 Vortex 3D Digital Audio Processor";
        case PciSubDevice12EB0002::SUBDEVICE_10923000: return "Monster Sound II";
        case PciSubDevice12EB0002::SUBDEVICE_10923001: return "Monster Sound II";
        case PciSubDevice12EB0002::SUBDEVICE_10923002: return "Monster Sound II";
        case PciSubDevice12EB0002::SUBDEVICE_10923003: return "Monster Sound II";
        case PciSubDevice12EB0002::SUBDEVICE_10923004: return "Monster Sound II";
        case PciSubDevice12EB0002::SUBDEVICE_12EB0002: return "Au8830 Vortex 3D Digital Audio Processor";
        case PciSubDevice12EB0002::SUBDEVICE_12EB0088: return "Au8830 Vortex 3D Digital Audio Processor";
        case PciSubDevice12EB0002::SUBDEVICE_144D3510: return "Au8830 Vortex 3D Digital Audio Processor";
        case PciSubDevice12EB0002::SUBDEVICE_50533356: return "Montego II";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0002_H
