// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862448_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862448_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862448: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040A = 0x1028040A,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_103C30C1 = 0x103C30C1,
    SUBDEVICE_10431017 = 0x10431017,
    SUBDEVICE_104D902D = 0x104D902D,
    SUBDEVICE_105B0D7C = 0x105B0D7C,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_144DC06A = 0x144DC06A,
    SUBDEVICE_144DC072 = 0x144DC072,
    SUBDEVICE_14585000 = 0x14585000,
    SUBDEVICE_17341055 = 0x17341055,
    SUBDEVICE_17AA2013 = 0x17AA2013,
    SUBDEVICE_17AA20AE = 0x17AA20AE,
    SUBDEVICE_17C010D2 = 0x17C010D2,
    SUBDEVICE_17C04083 = 0x17C04083,
    SUBDEVICE_8086544B = 0x8086544B,
    SUBDEVICE_E4BFCC47 = 0xE4BFCC47
};



inline const char8* enumToString(PciSubDevice80862448 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862448::NONE:               return "NONE";
        case PciSubDevice80862448::SUBDEVICE_1028040A: return "SUBDEVICE_1028040A";
        case PciSubDevice80862448::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice80862448::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice80862448::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice80862448::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice80862448::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice80862448::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice80862448::SUBDEVICE_103C30C1: return "SUBDEVICE_103C30C1";
        case PciSubDevice80862448::SUBDEVICE_10431017: return "SUBDEVICE_10431017";
        case PciSubDevice80862448::SUBDEVICE_104D902D: return "SUBDEVICE_104D902D";
        case PciSubDevice80862448::SUBDEVICE_105B0D7C: return "SUBDEVICE_105B0D7C";
        case PciSubDevice80862448::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice80862448::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice80862448::SUBDEVICE_144DC06A: return "SUBDEVICE_144DC06A";
        case PciSubDevice80862448::SUBDEVICE_144DC072: return "SUBDEVICE_144DC072";
        case PciSubDevice80862448::SUBDEVICE_14585000: return "SUBDEVICE_14585000";
        case PciSubDevice80862448::SUBDEVICE_17341055: return "SUBDEVICE_17341055";
        case PciSubDevice80862448::SUBDEVICE_17AA2013: return "SUBDEVICE_17AA2013";
        case PciSubDevice80862448::SUBDEVICE_17AA20AE: return "SUBDEVICE_17AA20AE";
        case PciSubDevice80862448::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";
        case PciSubDevice80862448::SUBDEVICE_17C04083: return "SUBDEVICE_17C04083";
        case PciSubDevice80862448::SUBDEVICE_8086544B: return "SUBDEVICE_8086544B";
        case PciSubDevice80862448::SUBDEVICE_E4BFCC47: return "SUBDEVICE_E4BFCC47";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862448 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862448 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862448::SUBDEVICE_1028040A: return "Latitude E6410";
        case PciSubDevice80862448::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice80862448::SUBDEVICE_103C0934: return "Compaq nw8240 Mobile Workstation";
        case PciSubDevice80862448::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice80862448::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice80862448::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice80862448::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice80862448::SUBDEVICE_103C30C1: return "Compaq 6910p";
        case PciSubDevice80862448::SUBDEVICE_10431017: return "X58LE";
        case PciSubDevice80862448::SUBDEVICE_104D902D: return "VAIO VGN-NR120E";
        case PciSubDevice80862448::SUBDEVICE_105B0D7C: return "D270S/D250S Motherboard";
        case PciSubDevice80862448::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice80862448::SUBDEVICE_144DC00C: return "P30 notebook";
        case PciSubDevice80862448::SUBDEVICE_144DC06A: return "R730 Laptop";
        case PciSubDevice80862448::SUBDEVICE_144DC072: return "Notebook N150P";
        case PciSubDevice80862448::SUBDEVICE_14585000: return "GA-D525TUD";
        case PciSubDevice80862448::SUBDEVICE_17341055: return "Amilo M1420";
        case PciSubDevice80862448::SUBDEVICE_17AA2013: return "ThinkPad R60e";
        case PciSubDevice80862448::SUBDEVICE_17AA20AE: return "ThinkPad T61/R61";
        case PciSubDevice80862448::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";
        case PciSubDevice80862448::SUBDEVICE_17C04083: return "Medion WIM 2210 Notebook PC [MD96850]";
        case PciSubDevice80862448::SUBDEVICE_8086544B: return "Desktop Board D425KT";
        case PciSubDevice80862448::SUBDEVICE_E4BFCC47: return "CCG-RUMBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862448_H
