// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0295_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0295_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0295: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438225 = 0x10438225,
    SUBDEVICE_107D2A68 = 0x107D2A68,
    SUBDEVICE_14620663 = 0x14620663
};



inline const char8* enumToString(PciSubDevice10DE0295 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0295::NONE:               return "NONE";
        case PciSubDevice10DE0295::SUBDEVICE_10438225: return "SUBDEVICE_10438225";
        case PciSubDevice10DE0295::SUBDEVICE_107D2A68: return "SUBDEVICE_107D2A68";
        case PciSubDevice10DE0295::SUBDEVICE_14620663: return "SUBDEVICE_14620663";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0295 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0295 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0295::SUBDEVICE_10438225: return "GeForce 7950 GT";
        case PciSubDevice10DE0295::SUBDEVICE_107D2A68: return "WinFast PX7950GT TDH";
        case PciSubDevice10DE0295::SUBDEVICE_14620663: return "NX7950GT-VT2D512EZ-HD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0295_H
