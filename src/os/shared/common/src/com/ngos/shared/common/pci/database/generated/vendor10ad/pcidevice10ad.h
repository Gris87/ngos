// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10AD_PCIDEVICE10AD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10AD_PCIDEVICE10AD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10AD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0003 = 0x0003,
    DEVICE_0005 = 0x0005,
    DEVICE_0103 = 0x0103,
    DEVICE_0105 = 0x0105,
    DEVICE_0565 = 0x0565
};



inline const char8* enumToString(PciDevice10AD device10AD) // TEST: NO
{
    // COMMON_LT((" | device10AD = %u", device10AD)); // Commented to avoid bad looking logs



    switch (device10AD)
    {
        case PciDevice10AD::NONE:        return "NONE";
        case PciDevice10AD::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10AD::DEVICE_0003: return "DEVICE_0003";
        case PciDevice10AD::DEVICE_0005: return "DEVICE_0005";
        case PciDevice10AD::DEVICE_0103: return "DEVICE_0103";
        case PciDevice10AD::DEVICE_0105: return "DEVICE_0105";
        case PciDevice10AD::DEVICE_0565: return "DEVICE_0565";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10AD device10AD) // TEST: NO
{
    // COMMON_LT((" | device10AD = %u", device10AD)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10AD, enumToString(device10AD));

    return res;
}



inline const char8* enumToHumanString(PciDevice10AD device10AD) // TEST: NO
{
    // COMMON_LT((" | device10AD = %u", device10AD)); // Commented to avoid bad looking logs



    switch (device10AD)
    {
        case PciDevice10AD::DEVICE_0001: return "W83769F";
        case PciDevice10AD::DEVICE_0003: return "SL82C103";
        case PciDevice10AD::DEVICE_0005: return "SL82C105";
        case PciDevice10AD::DEVICE_0103: return "SL82c103";
        case PciDevice10AD::DEVICE_0105: return "SL82c105";
        case PciDevice10AD::DEVICE_0565: return "W83C553F/W83C554F";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10AD_PCIDEVICE10AD_H
