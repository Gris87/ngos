// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608AF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608AF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808608AF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861015 = 0x80861015,
    SUBDEVICE_80861017 = 0x80861017
};



inline const char8* enumToString(PciSubDevice808608AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608AF::NONE:               return "NONE";
        case PciSubDevice808608AF::SUBDEVICE_80861015: return "SUBDEVICE_80861015";
        case PciSubDevice808608AF::SUBDEVICE_80861017: return "SUBDEVICE_80861017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808608AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808608AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608AF::SUBDEVICE_80861015: return "Centrino Wireless-N 100 BGN";
        case PciSubDevice808608AF::SUBDEVICE_80861017: return "Centrino Wireless-N 100 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608AF_H
