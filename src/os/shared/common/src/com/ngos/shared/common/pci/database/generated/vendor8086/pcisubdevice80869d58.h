// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D58_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D58_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80869D58: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025115F = 0x1025115F,
    SUBDEVICE_17AA2247 = 0x17AA2247,
    SUBDEVICE_17AA224F = 0x17AA224F
};



inline const char8* enumToString(PciSubDevice80869D58 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D58::NONE:               return "NONE";
        case PciSubDevice80869D58::SUBDEVICE_1025115F: return "SUBDEVICE_1025115F";
        case PciSubDevice80869D58::SUBDEVICE_17AA2247: return "SUBDEVICE_17AA2247";
        case PciSubDevice80869D58::SUBDEVICE_17AA224F: return "SUBDEVICE_17AA224F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80869D58 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80869D58 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D58::SUBDEVICE_1025115F: return "Acer Aspire E5-575G";
        case PciSubDevice80869D58::SUBDEVICE_17AA2247: return "ThinkPad T570";
        case PciSubDevice80869D58::SUBDEVICE_17AA224F: return "ThinkPad X1 Carbon 5th Gen";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D58_H
