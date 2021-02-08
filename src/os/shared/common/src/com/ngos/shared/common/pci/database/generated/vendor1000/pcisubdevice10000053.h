// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000053_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000053_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000053: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009350 = 0x10009350,
    SUBDEVICE_10009351 = 0x10009351
};



inline const char8* enumToString(PciSubDevice10000053 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000053::NONE:               return "NONE";
        case PciSubDevice10000053::SUBDEVICE_10009350: return "SUBDEVICE_10009350";
        case PciSubDevice10000053::SUBDEVICE_10009351: return "SUBDEVICE_10009351";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000053 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000053 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000053::SUBDEVICE_10009350: return "MegaRAID SAS 9341-16i";
        case PciSubDevice10000053::SUBDEVICE_10009351: return "MegaRAID SAS 9341-24i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000053_H
