// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C803B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_104D8212 = 0x104D8212,
    SUBDEVICE_104D902D = 0x104D902D
};



inline const char8* enumToString(PciSubDevice104C803B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C803B::NONE:               return "NONE";
        case PciSubDevice104C803B::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice104C803B::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice104C803B::SUBDEVICE_104D8212: return "SUBDEVICE_104D8212";
        case PciSubDevice104C803B::SUBDEVICE_104D902D: return "SUBDEVICE_104D902D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C803B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C803B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C803B::SUBDEVICE_103C309F: return "nx9420";
        case PciSubDevice104C803B::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice104C803B::SUBDEVICE_104D8212: return "VAIO VGN-N21E";
        case PciSubDevice104C803B::SUBDEVICE_104D902D: return "VAIO VGN-NR120E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803B_H
