// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863403_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863403_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863403: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280236 = 0x10280236,
    SUBDEVICE_10280287 = 0x10280287,
    SUBDEVICE_1028028C = 0x1028028C,
    SUBDEVICE_1028028D = 0x1028028D,
    SUBDEVICE_103C330B = 0x103C330B
};



inline const char8* enumToString(PciSubDevice80863403 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863403::NONE:               return "NONE";
        case PciSubDevice80863403::SUBDEVICE_10280236: return "SUBDEVICE_10280236";
        case PciSubDevice80863403::SUBDEVICE_10280287: return "SUBDEVICE_10280287";
        case PciSubDevice80863403::SUBDEVICE_1028028C: return "SUBDEVICE_1028028C";
        case PciSubDevice80863403::SUBDEVICE_1028028D: return "SUBDEVICE_1028028D";
        case PciSubDevice80863403::SUBDEVICE_103C330B: return "SUBDEVICE_103C330B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863403 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863403 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863403::SUBDEVICE_10280236: return "PowerEdge R610 I/O Hub to ESI Port";
        case PciSubDevice80863403::SUBDEVICE_10280287: return "PowerEdge M610 I/O Hub to ESI Port";
        case PciSubDevice80863403::SUBDEVICE_1028028C: return "PowerEdge R410 I/O Hub to ESI Port";
        case PciSubDevice80863403::SUBDEVICE_1028028D: return "PowerEdge T410 I/O Hub to ESI Port";
        case PciSubDevice80863403::SUBDEVICE_103C330B: return "ProLiant ML150 G6 Server";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863403_H
