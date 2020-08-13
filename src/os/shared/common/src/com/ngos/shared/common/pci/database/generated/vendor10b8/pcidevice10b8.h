// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCIDEVICE10B8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCIDEVICE10B8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_A011 = 0xA011,
    DEVICE_B106 = 0xB106
};



inline const char8* enumToString(PciDevice10B8 device10B8) // TEST: NO
{
    // COMMON_LT((" | device10B8 = %u", device10B8)); // Commented to avoid bad looking logs



    switch (device10B8)
    {
        case PciDevice10B8::NONE:        return "NONE";
        case PciDevice10B8::DEVICE_0005: return "DEVICE_0005";
        case PciDevice10B8::DEVICE_0006: return "DEVICE_0006";
        case PciDevice10B8::DEVICE_1000: return "DEVICE_1000";
        case PciDevice10B8::DEVICE_1001: return "DEVICE_1001";
        case PciDevice10B8::DEVICE_A011: return "DEVICE_A011";
        case PciDevice10B8::DEVICE_B106: return "DEVICE_B106";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B8 device10B8) // TEST: NO
{
    // COMMON_LT((" | device10B8 = %u", device10B8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10B8, enumToString(device10B8));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B8 device10B8) // TEST: NO
{
    // COMMON_LT((" | device10B8 = %u", device10B8)); // Commented to avoid bad looking logs



    switch (device10B8)
    {
        case PciDevice10B8::DEVICE_0005: return "83c170 EPIC/100 Fast Ethernet Adapter";
        case PciDevice10B8::DEVICE_0006: return "83c175 EPIC/100 Fast Ethernet Adapter";
        case PciDevice10B8::DEVICE_1000: return "FDC 37c665";
        case PciDevice10B8::DEVICE_1001: return "FDC 37C922";
        case PciDevice10B8::DEVICE_A011: return "83C170QF";
        case PciDevice10B8::DEVICE_B106: return "SMC34C90";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCIDEVICE10B8_H
