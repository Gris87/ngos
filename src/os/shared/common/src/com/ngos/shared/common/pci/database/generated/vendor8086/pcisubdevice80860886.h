// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860886_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860886_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860886: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861315 = 0x80861315,
    SUBDEVICE_80861317 = 0x80861317
};



inline const char8* enumToString(PciSubDevice80860886 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860886::NONE:               return "NONE";
        case PciSubDevice80860886::SUBDEVICE_80861315: return "SUBDEVICE_80861315";
        case PciSubDevice80860886::SUBDEVICE_80861317: return "SUBDEVICE_80861317";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860886 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860886 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860886::SUBDEVICE_80861315: return "Centrino Wireless-N + WiMAX 6150 BGN";
        case PciSubDevice80860886::SUBDEVICE_80861317: return "Centrino Wireless-N + WiMAX 6150 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860886_H
