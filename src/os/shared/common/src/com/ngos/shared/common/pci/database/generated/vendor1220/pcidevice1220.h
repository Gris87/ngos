// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1220_PCIDEVICE1220_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1220_PCIDEVICE1220_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1220: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1220 = 0x1220
};



inline const char8* enumToString(PciDevice1220 device1220) // TEST: NO
{
    // COMMON_LT((" | device1220 = %u", device1220)); // Commented to avoid bad looking logs



    switch (device1220)
    {
        case PciDevice1220::NONE:        return "NONE";
        case PciDevice1220::DEVICE_1220: return "DEVICE_1220";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1220 device1220) // TEST: NO
{
    // COMMON_LT((" | device1220 = %u", device1220)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1220, enumToString(device1220));

    return res;
}



inline const char8* enumToHumanString(PciDevice1220 device1220) // TEST: NO
{
    // COMMON_LT((" | device1220 = %u", device1220)); // Commented to avoid bad looking logs



    switch (device1220)
    {
        case PciDevice1220::DEVICE_1220: return "AMCC 5933 TMS320C80 DSP/Imaging board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1220_PCIDEVICE1220_H
