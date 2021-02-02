// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BA1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BA1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1BA1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14581651 = 0x14581651,
    SUBDEVICE_146211E8 = 0x146211E8,
    SUBDEVICE_146211E9 = 0x146211E9,
    SUBDEVICE_15589501 = 0x15589501
};



inline const char8* enumToString(PciSubDevice10DE1BA1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1BA1::NONE:               return "NONE";
        case PciSubDevice10DE1BA1::SUBDEVICE_14581651: return "SUBDEVICE_14581651";
        case PciSubDevice10DE1BA1::SUBDEVICE_146211E8: return "SUBDEVICE_146211E8";
        case PciSubDevice10DE1BA1::SUBDEVICE_146211E9: return "SUBDEVICE_146211E9";
        case PciSubDevice10DE1BA1::SUBDEVICE_15589501: return "SUBDEVICE_15589501";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1BA1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1BA1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1BA1::SUBDEVICE_14581651: return "GeForce GTX 1070 Max-Q";
        case PciSubDevice10DE1BA1::SUBDEVICE_146211E8: return "GeForce GTX 1070 Max-Q";
        case PciSubDevice10DE1BA1::SUBDEVICE_146211E9: return "GeForce GTX 1070 Max-Q";
        case PciSubDevice10DE1BA1::SUBDEVICE_15589501: return "GeForce GTX 1070 Max-Q";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BA1_H
