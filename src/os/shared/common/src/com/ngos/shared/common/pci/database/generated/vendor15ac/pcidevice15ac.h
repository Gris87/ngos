// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AC_PCIDEVICE15AC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AC_PCIDEVICE15AC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15AC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6893 = 0x6893
};



inline const char8* enumToString(PciDevice15AC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15AC::NONE:        return "NONE";
        case PciDevice15AC::DEVICE_6893: return "DEVICE_6893";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15AC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice15AC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15AC::DEVICE_6893: return "3U OpenVPX Multi-function I/O Board [Model 68C3]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15AC_PCIDEVICE15AC_H
