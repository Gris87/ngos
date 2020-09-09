// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2014_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2014_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A2014: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10CF1057 = 0x10CF1057,
    SUBDEVICE_122D4050 = 0x122D4050,
    SUBDEVICE_122D4055 = 0x122D4055
};



inline const char8* enumToString(PciSubDevice127A2014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2014::NONE:               return "NONE";
        case PciSubDevice127A2014::SUBDEVICE_10CF1057: return "SUBDEVICE_10CF1057";
        case PciSubDevice127A2014::SUBDEVICE_122D4050: return "SUBDEVICE_122D4050";
        case PciSubDevice127A2014::SUBDEVICE_122D4055: return "SUBDEVICE_122D4055";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A2014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A2014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2014::SUBDEVICE_10CF1057: return "Fujitsu Citicorp III";
        case PciSubDevice127A2014::SUBDEVICE_122D4050: return "MSP3880-U";
        case PciSubDevice127A2014::SUBDEVICE_122D4055: return "MSP3880-W";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2014_H
