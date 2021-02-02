// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCISUBDEVICE13FE1600_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCISUBDEVICE13FE1600_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13FE1600: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_16010002 = 0x16010002,
    SUBDEVICE_16020002 = 0x16020002,
    SUBDEVICE_16120004 = 0x16120004
};



inline const char8* enumToString(PciSubDevice13FE1600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13FE1600::NONE:               return "NONE";
        case PciSubDevice13FE1600::SUBDEVICE_16010002: return "SUBDEVICE_16010002";
        case PciSubDevice13FE1600::SUBDEVICE_16020002: return "SUBDEVICE_16020002";
        case PciSubDevice13FE1600::SUBDEVICE_16120004: return "SUBDEVICE_16120004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13FE1600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13FE1600 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13FE1600::SUBDEVICE_16010002: return "PCI-1601 2-port unisolated RS-422/485";
        case PciSubDevice13FE1600::SUBDEVICE_16020002: return "PCI-1602 2-port isolated RS-422/485";
        case PciSubDevice13FE1600::SUBDEVICE_16120004: return "PCI-1612 4-port RS-232/422/485";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCISUBDEVICE13FE1600_H
