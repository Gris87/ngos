// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050050_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050050_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050050: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_9005F500 = 0x9005F500,
    SUBDEVICE_9005FFFF = 0x9005FFFF
};



inline const char8* enumToString(PciSubDevice90050050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050050::NONE:               return "NONE";
        case PciSubDevice90050050::SUBDEVICE_9005F500: return "SUBDEVICE_9005F500";
        case PciSubDevice90050050::SUBDEVICE_9005FFFF: return "SUBDEVICE_9005FFFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050050::SUBDEVICE_9005F500: return "AHA-3950U2B";
        case PciSubDevice90050050::SUBDEVICE_9005FFFF: return "AHA-3950U2B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050050_H
