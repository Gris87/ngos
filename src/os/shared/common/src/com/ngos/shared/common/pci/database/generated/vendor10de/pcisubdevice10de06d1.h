// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE06D1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE06D1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE06D1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE0771 = 0x10DE0771,
    SUBDEVICE_10DE0772 = 0x10DE0772
};



inline const char8* enumToString(PciSubDevice10DE06D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE06D1::NONE:               return "NONE";
        case PciSubDevice10DE06D1::SUBDEVICE_10DE0771: return "SUBDEVICE_10DE0771";
        case PciSubDevice10DE06D1::SUBDEVICE_10DE0772: return "SUBDEVICE_10DE0772";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE06D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE06D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE06D1::SUBDEVICE_10DE0771: return "Tesla C2050";
        case PciSubDevice10DE06D1::SUBDEVICE_10DE0772: return "Tesla C2070";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE06D1_H
