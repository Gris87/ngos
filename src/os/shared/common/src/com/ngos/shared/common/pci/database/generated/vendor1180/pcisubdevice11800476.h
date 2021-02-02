// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800476_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800476_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11800476: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140185 = 0x10140185,
    SUBDEVICE_10140555 = 0x10140555,
    SUBDEVICE_1014056C = 0x1014056C,
    SUBDEVICE_1028014F = 0x1028014F,
    SUBDEVICE_10280188 = 0x10280188,
    SUBDEVICE_103C30C0 = 0x103C30C0,
    SUBDEVICE_103C30C1 = 0x103C30C1,
    SUBDEVICE_10431017 = 0x10431017,
    SUBDEVICE_10431237 = 0x10431237,
    SUBDEVICE_10431967 = 0x10431967,
    SUBDEVICE_10431987 = 0x10431987,
    SUBDEVICE_104D80DF = 0x104D80DF,
    SUBDEVICE_104D80E7 = 0x104D80E7,
    SUBDEVICE_104D814E = 0x104D814E,
    SUBDEVICE_10F78338 = 0x10F78338,
    SUBDEVICE_144DC005 = 0x144DC005,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_14EF0220 = 0x14EF0220,
    SUBDEVICE_17AA201C = 0x17AA201C,
    SUBDEVICE_17AA20C4 = 0x17AA20C4,
    SUBDEVICE_17AA20C6 = 0x17AA20C6
};



inline const char8* enumToString(PciSubDevice11800476 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800476::NONE:               return "NONE";
        case PciSubDevice11800476::SUBDEVICE_10140185: return "SUBDEVICE_10140185";
        case PciSubDevice11800476::SUBDEVICE_10140555: return "SUBDEVICE_10140555";
        case PciSubDevice11800476::SUBDEVICE_1014056C: return "SUBDEVICE_1014056C";
        case PciSubDevice11800476::SUBDEVICE_1028014F: return "SUBDEVICE_1028014F";
        case PciSubDevice11800476::SUBDEVICE_10280188: return "SUBDEVICE_10280188";
        case PciSubDevice11800476::SUBDEVICE_103C30C0: return "SUBDEVICE_103C30C0";
        case PciSubDevice11800476::SUBDEVICE_103C30C1: return "SUBDEVICE_103C30C1";
        case PciSubDevice11800476::SUBDEVICE_10431017: return "SUBDEVICE_10431017";
        case PciSubDevice11800476::SUBDEVICE_10431237: return "SUBDEVICE_10431237";
        case PciSubDevice11800476::SUBDEVICE_10431967: return "SUBDEVICE_10431967";
        case PciSubDevice11800476::SUBDEVICE_10431987: return "SUBDEVICE_10431987";
        case PciSubDevice11800476::SUBDEVICE_104D80DF: return "SUBDEVICE_104D80DF";
        case PciSubDevice11800476::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";
        case PciSubDevice11800476::SUBDEVICE_104D814E: return "SUBDEVICE_104D814E";
        case PciSubDevice11800476::SUBDEVICE_10F78338: return "SUBDEVICE_10F78338";
        case PciSubDevice11800476::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";
        case PciSubDevice11800476::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice11800476::SUBDEVICE_14EF0220: return "SUBDEVICE_14EF0220";
        case PciSubDevice11800476::SUBDEVICE_17AA201C: return "SUBDEVICE_17AA201C";
        case PciSubDevice11800476::SUBDEVICE_17AA20C4: return "SUBDEVICE_17AA20C4";
        case PciSubDevice11800476::SUBDEVICE_17AA20C6: return "SUBDEVICE_17AA20C6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11800476 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11800476 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800476::SUBDEVICE_10140185: return "ThinkPad A/T/X Series";
        case PciSubDevice11800476::SUBDEVICE_10140555: return "ThinkPad X41";
        case PciSubDevice11800476::SUBDEVICE_1014056C: return "ThinkPad Z60t";
        case PciSubDevice11800476::SUBDEVICE_1028014F: return "Latitude X300 laptop";
        case PciSubDevice11800476::SUBDEVICE_10280188: return "Inspiron 6000 laptop";
        case PciSubDevice11800476::SUBDEVICE_103C30C0: return "Compaq 6710b";
        case PciSubDevice11800476::SUBDEVICE_103C30C1: return "Compaq 6910p";
        case PciSubDevice11800476::SUBDEVICE_10431017: return "X58LE";
        case PciSubDevice11800476::SUBDEVICE_10431237: return "A6J-Q008";
        case PciSubDevice11800476::SUBDEVICE_10431967: return "V6800V";
        case PciSubDevice11800476::SUBDEVICE_10431987: return "A4K and Z81K notebooks, possibly others ( mid-2005 machines )";
        case PciSubDevice11800476::SUBDEVICE_104D80DF: return "Vaio PCG-FX403";
        case PciSubDevice11800476::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";
        case PciSubDevice11800476::SUBDEVICE_104D814E: return "VAIO GRZ390Z";
        case PciSubDevice11800476::SUBDEVICE_10F78338: return "Panasonic CF-Y5 laptop";
        case PciSubDevice11800476::SUBDEVICE_144DC005: return "X10 Laptop";
        case PciSubDevice11800476::SUBDEVICE_144DC00C: return "P30/P35 notebook";
        case PciSubDevice11800476::SUBDEVICE_14EF0220: return "PCD-RP-220S";
        case PciSubDevice11800476::SUBDEVICE_17AA201C: return "ThinkPad X60/X60s";
        case PciSubDevice11800476::SUBDEVICE_17AA20C4: return "ThinkPad T61/R61";
        case PciSubDevice11800476::SUBDEVICE_17AA20C6: return "ThinkPad R61/T400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800476_H
