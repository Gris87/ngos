// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862723_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862723_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862723: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1A561654 = 0x1A561654,
    SUBDEVICE_80860084 = 0x80860084
};



inline const char8* enumToString(PciSubDevice80862723 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862723::NONE:               return "NONE";
        case PciSubDevice80862723::SUBDEVICE_1A561654: return "SUBDEVICE_1A561654";
        case PciSubDevice80862723::SUBDEVICE_80860084: return "SUBDEVICE_80860084";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862723 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862723 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862723::SUBDEVICE_1A561654: return "Killer™ Wi-Fi 6 AX1650x (AX200NGW)";
        case PciSubDevice80862723::SUBDEVICE_80860084: return "Wi-Fi 6 AX200NGW";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862723_H
