// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608AE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608AE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808608AE: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861005 = 0x80861005,
    SUBDEVICE_80861007 = 0x80861007,
    SUBDEVICE_80861025 = 0x80861025,
    SUBDEVICE_80861027 = 0x80861027
};



inline const char8* enumToString(PciSubDevice808608AE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608AE::NONE:               return "NONE";
        case PciSubDevice808608AE::SUBDEVICE_80861005: return "SUBDEVICE_80861005";
        case PciSubDevice808608AE::SUBDEVICE_80861007: return "SUBDEVICE_80861007";
        case PciSubDevice808608AE::SUBDEVICE_80861025: return "SUBDEVICE_80861025";
        case PciSubDevice808608AE::SUBDEVICE_80861027: return "SUBDEVICE_80861027";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808608AE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808608AE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808608AE::SUBDEVICE_80861005: return "Centrino Wireless-N 100 BGN";
        case PciSubDevice808608AE::SUBDEVICE_80861007: return "Centrino Wireless-N 100 BG";
        case PciSubDevice808608AE::SUBDEVICE_80861025: return "Centrino Wireless-N 100 BGN";
        case PciSubDevice808608AE::SUBDEVICE_80861027: return "Centrino Wireless-N 100 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808608AE_H
