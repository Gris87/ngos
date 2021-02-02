// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862590_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862590_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862590: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140575 = 0x10140575,
    SUBDEVICE_10280182 = 0x10280182,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_104382D9 = 0x104382D9,
    SUBDEVICE_104D81B7 = 0x104D81B7,
    SUBDEVICE_A30481B7 = 0xA30481B7,
    SUBDEVICE_E4BF0CCD = 0xE4BF0CCD,
    SUBDEVICE_E4BF0CD3 = 0xE4BF0CD3,
    SUBDEVICE_E4BF58B1 = 0xE4BF58B1
};



inline const char8* enumToString(PciSubDevice80862590 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862590::NONE:               return "NONE";
        case PciSubDevice80862590::SUBDEVICE_10140575: return "SUBDEVICE_10140575";
        case PciSubDevice80862590::SUBDEVICE_10280182: return "SUBDEVICE_10280182";
        case PciSubDevice80862590::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice80862590::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice80862590::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice80862590::SUBDEVICE_104382D9: return "SUBDEVICE_104382D9";
        case PciSubDevice80862590::SUBDEVICE_104D81B7: return "SUBDEVICE_104D81B7";
        case PciSubDevice80862590::SUBDEVICE_A30481B7: return "SUBDEVICE_A30481B7";
        case PciSubDevice80862590::SUBDEVICE_E4BF0CCD: return "SUBDEVICE_E4BF0CCD";
        case PciSubDevice80862590::SUBDEVICE_E4BF0CD3: return "SUBDEVICE_E4BF0CD3";
        case PciSubDevice80862590::SUBDEVICE_E4BF58B1: return "SUBDEVICE_E4BF58B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862590 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862590 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862590::SUBDEVICE_10140575: return "ThinkPad X41 / Z60t";
        case PciSubDevice80862590::SUBDEVICE_10280182: return "Latitude C610";
        case PciSubDevice80862590::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice80862590::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice80862590::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice80862590::SUBDEVICE_104382D9: return "Asus Eee PC 900";
        case PciSubDevice80862590::SUBDEVICE_104D81B7: return "Vaio VGN-S3XP";
        case PciSubDevice80862590::SUBDEVICE_A30481B7: return "Vaio VGN-S3XP";
        case PciSubDevice80862590::SUBDEVICE_E4BF0CCD: return "CCD-CALYPSO";
        case PciSubDevice80862590::SUBDEVICE_E4BF0CD3: return "CD3-JIVE";
        case PciSubDevice80862590::SUBDEVICE_E4BF58B1: return "XB1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862590_H
