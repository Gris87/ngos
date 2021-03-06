// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140096_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140096_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10140096: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140097 = 0x10140097,
    SUBDEVICE_10140098 = 0x10140098,
    SUBDEVICE_10140099 = 0x10140099
};



inline const char8* enumToString(PciSubDevice10140096 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140096::NONE:               return "NONE";
        case PciSubDevice10140096::SUBDEVICE_10140097: return "SUBDEVICE_10140097";
        case PciSubDevice10140096::SUBDEVICE_10140098: return "SUBDEVICE_10140098";
        case PciSubDevice10140096::SUBDEVICE_10140099: return "SUBDEVICE_10140099";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10140096 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10140096 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140096::SUBDEVICE_10140097: return "iSeries 2778 DASD IOA";
        case PciSubDevice10140096::SUBDEVICE_10140098: return "iSeries 2763 DASD IOA";
        case PciSubDevice10140096::SUBDEVICE_10140099: return "iSeries 2748 DASD IOA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140096_H
