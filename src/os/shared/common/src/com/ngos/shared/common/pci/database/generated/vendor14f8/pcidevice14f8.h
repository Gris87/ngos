// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F8_PCIDEVICE14F8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F8_PCIDEVICE14F8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14F8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2077 = 0x2077
};



inline const char8* enumToString(PciDevice14F8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14F8::NONE:        return "NONE";
        case PciDevice14F8::DEVICE_2077: return "DEVICE_2077";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14F8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14F8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14F8::DEVICE_2077: return "TP-240 dual span E1 VoIP PCI card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F8_PCIDEVICE14F8_H
