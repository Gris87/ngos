// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90058017_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90058017_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90058017: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050044 = 0x90050044,
    SUBDEVICE_90050045 = 0x90050045
};



inline const char8* enumToString(PciSubDevice90058017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90058017::NONE:               return "NONE";
        case PciSubDevice90058017::SUBDEVICE_90050044: return "SUBDEVICE_90050044";
        case PciSubDevice90058017::SUBDEVICE_90050045: return "SUBDEVICE_90050045";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90058017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90058017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90058017::SUBDEVICE_90050044: return "ASC-29320ALP PCIx U320";
        case PciSubDevice90058017::SUBDEVICE_90050045: return "ASC-29320LPE PCIe U320";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90058017_H
