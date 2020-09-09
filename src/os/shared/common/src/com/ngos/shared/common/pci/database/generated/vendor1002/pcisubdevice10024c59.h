// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C59_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C59_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024C59: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B111 = 0x0E11B111,
    SUBDEVICE_10140235 = 0x10140235,
    SUBDEVICE_10140239 = 0x10140239,
    SUBDEVICE_103C0025 = 0x103C0025,
    SUBDEVICE_104D80E7 = 0x104D80E7,
    SUBDEVICE_104D8140 = 0x104D8140,
    SUBDEVICE_15091930 = 0x15091930
};



inline const char8* enumToString(PciSubDevice10024C59 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C59::NONE:               return "NONE";
        case PciSubDevice10024C59::SUBDEVICE_0E11B111: return "SUBDEVICE_0E11B111";
        case PciSubDevice10024C59::SUBDEVICE_10140235: return "SUBDEVICE_10140235";
        case PciSubDevice10024C59::SUBDEVICE_10140239: return "SUBDEVICE_10140239";
        case PciSubDevice10024C59::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";
        case PciSubDevice10024C59::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";
        case PciSubDevice10024C59::SUBDEVICE_104D8140: return "SUBDEVICE_104D8140";
        case PciSubDevice10024C59::SUBDEVICE_15091930: return "SUBDEVICE_15091930";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024C59 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024C59 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C59::SUBDEVICE_0E11B111: return "Evo N600c";
        case PciSubDevice10024C59::SUBDEVICE_10140235: return "ThinkPad A30/A30p (2652/2653)";
        case PciSubDevice10024C59::SUBDEVICE_10140239: return "ThinkPad X22/X23/X24";
        case PciSubDevice10024C59::SUBDEVICE_103C0025: return "XE4500 Notebook";
        case PciSubDevice10024C59::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";
        case PciSubDevice10024C59::SUBDEVICE_104D8140: return "PCG-Z1SP laptop";
        case PciSubDevice10024C59::SUBDEVICE_15091930: return "Medion MD9703";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C59_H
