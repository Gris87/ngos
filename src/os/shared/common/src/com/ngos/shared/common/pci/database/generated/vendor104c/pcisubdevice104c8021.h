// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8021_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8021_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8021: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104D80DF = 0x104D80DF,
    SUBDEVICE_104D80E7 = 0x104D80E7
};



inline const char8* enumToString(PciSubDevice104C8021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8021::NONE:               return "NONE";
        case PciSubDevice104C8021::SUBDEVICE_104D80DF: return "SUBDEVICE_104D80DF";
        case PciSubDevice104C8021::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8021::SUBDEVICE_104D80DF: return "Vaio PCG-FX403";
        case PciSubDevice104C8021::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8021_H
