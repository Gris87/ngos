// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1004: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_38420784 = 0x38420784,
    SUBDEVICE_38421784 = 0x38421784,
    SUBDEVICE_38421788 = 0x38421788
};



inline const char8* enumToString(PciSubDevice10DE1004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1004::NONE:               return "NONE";
        case PciSubDevice10DE1004::SUBDEVICE_38420784: return "SUBDEVICE_38420784";
        case PciSubDevice10DE1004::SUBDEVICE_38421784: return "SUBDEVICE_38421784";
        case PciSubDevice10DE1004::SUBDEVICE_38421788: return "SUBDEVICE_38421788";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1004::SUBDEVICE_38420784: return "GK110B [GeForce GTX 780 SC w/ ACX Cooler]";
        case PciSubDevice10DE1004::SUBDEVICE_38421784: return "GK110B [GeForce GTX 780 Dual FTW w/ ACX Cooler]";
        case PciSubDevice10DE1004::SUBDEVICE_38421788: return "GK110B [GeForce GTX 780 Dual Classified w/ ACX Cooler]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1004_H
