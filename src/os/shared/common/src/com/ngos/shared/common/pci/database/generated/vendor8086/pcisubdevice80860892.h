// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860892_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860892_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860892: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860062 = 0x80860062,
    SUBDEVICE_80860462 = 0x80860462
};



inline const char8* enumToString(PciSubDevice80860892 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860892::NONE:               return "NONE";
        case PciSubDevice80860892::SUBDEVICE_80860062: return "SUBDEVICE_80860062";
        case PciSubDevice80860892::SUBDEVICE_80860462: return "SUBDEVICE_80860462";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860892 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860892 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860892::SUBDEVICE_80860062: return "Centrino Wireless-N 135 BGN";
        case PciSubDevice80860892::SUBDEVICE_80860462: return "Centrino Wireless-N 135 BGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860892_H
