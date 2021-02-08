// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863575_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863575_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863575: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110030 = 0x0E110030,
    SUBDEVICE_1014021D = 0x1014021D,
    SUBDEVICE_104D80E7 = 0x104D80E7
};



inline const char8* enumToString(PciSubDevice80863575 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863575::NONE:               return "NONE";
        case PciSubDevice80863575::SUBDEVICE_0E110030: return "SUBDEVICE_0E110030";
        case PciSubDevice80863575::SUBDEVICE_1014021D: return "SUBDEVICE_1014021D";
        case PciSubDevice80863575::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863575 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863575 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863575::SUBDEVICE_0E110030: return "Evo N600c";
        case PciSubDevice80863575::SUBDEVICE_1014021D: return "ThinkPad A/T/X Series";
        case PciSubDevice80863575::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863575_H
