// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086103D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086103D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086103D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140522 = 0x10140522,
    SUBDEVICE_10282002 = 0x10282002,
    SUBDEVICE_8086103D = 0x8086103D
};



inline const char8* enumToString(PciSubDevice8086103D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086103D::NONE:               return "NONE";
        case PciSubDevice8086103D::SUBDEVICE_10140522: return "SUBDEVICE_10140522";
        case PciSubDevice8086103D::SUBDEVICE_10282002: return "SUBDEVICE_10282002";
        case PciSubDevice8086103D::SUBDEVICE_8086103D: return "SUBDEVICE_8086103D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086103D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086103D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086103D::SUBDEVICE_10140522: return "ThinkPad R40";
        case PciSubDevice8086103D::SUBDEVICE_10282002: return "Latitude D500";
        case PciSubDevice8086103D::SUBDEVICE_8086103D: return "82562EZ 10/100 Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086103D_H
