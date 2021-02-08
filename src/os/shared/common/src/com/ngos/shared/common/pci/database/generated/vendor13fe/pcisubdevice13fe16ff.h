// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCISUBDEVICE13FE16FF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCISUBDEVICE13FE16FF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13FE16FF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_16010000 = 0x16010000,
    SUBDEVICE_16020000 = 0x16020000,
    SUBDEVICE_16120000 = 0x16120000
};



inline const char8* enumToString(PciSubDevice13FE16FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13FE16FF::NONE:               return "NONE";
        case PciSubDevice13FE16FF::SUBDEVICE_16010000: return "SUBDEVICE_16010000";
        case PciSubDevice13FE16FF::SUBDEVICE_16020000: return "SUBDEVICE_16020000";
        case PciSubDevice13FE16FF::SUBDEVICE_16120000: return "SUBDEVICE_16120000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13FE16FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13FE16FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13FE16FF::SUBDEVICE_16010000: return "PCI-1601 2-port unisolated RS-422/485 PCI communications card";
        case PciSubDevice13FE16FF::SUBDEVICE_16020000: return "PCI-1602 2-port isolated RS-422/485";
        case PciSubDevice13FE16FF::SUBDEVICE_16120000: return "PCI-1612 4-port RS-232/422/485";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13FE_PCISUBDEVICE13FE16FF_H
