// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808665F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808665F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808665F0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020F = 0x1028020F,
    SUBDEVICE_10280210 = 0x10280210
};



inline const char8* enumToString(PciSubDevice808665F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808665F0::NONE:               return "NONE";
        case PciSubDevice808665F0::SUBDEVICE_1028020F: return "SUBDEVICE_1028020F";
        case PciSubDevice808665F0::SUBDEVICE_10280210: return "SUBDEVICE_10280210";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808665F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808665F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808665F0::SUBDEVICE_1028020F: return "PowerEdge R300";
        case PciSubDevice808665F0::SUBDEVICE_10280210: return "PowerEdge T300";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808665F0_H
