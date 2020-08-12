// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1231_PCIDEVICE1231_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1231_PCIDEVICE1231_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1231: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_04E1 = 0x04E1,
    DEVICE_05E1 = 0x05E1,
    DEVICE_0D00 = 0x0D00,
    DEVICE_0D02 = 0x0D02,
    DEVICE_0D13 = 0x0D13
};



inline const char8* enumToString(PciDevice1231 device1231) // TEST: NO
{
    // COMMON_LT((" | device1231 = %u", device1231)); // Commented to avoid bad looking logs



    switch (device1231)
    {
        case PciDevice1231::NONE:        return "NONE";
        case PciDevice1231::DEVICE_04E1: return "DEVICE_04E1";
        case PciDevice1231::DEVICE_05E1: return "DEVICE_05E1";
        case PciDevice1231::DEVICE_0D00: return "DEVICE_0D00";
        case PciDevice1231::DEVICE_0D02: return "DEVICE_0D02";
        case PciDevice1231::DEVICE_0D13: return "DEVICE_0D13";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1231 device1231) // TEST: NO
{
    // COMMON_LT((" | device1231 = %u", device1231)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1231, enumToString(device1231));

    return res;
}



inline const char8* enumToHumanString(PciDevice1231 device1231) // TEST: NO
{
    // COMMON_LT((" | device1231 = %u", device1231)); // Commented to avoid bad looking logs



    switch (device1231)
    {
        case PciDevice1231::DEVICE_04E1: return "Desktop PCI Telephony 4";
        case PciDevice1231::DEVICE_05E1: return "Desktop PCI Telephony 5/6";
        case PciDevice1231::DEVICE_0D00: return "LightParser";
        case PciDevice1231::DEVICE_0D02: return "LightParser 2";
        case PciDevice1231::DEVICE_0D13: return "Desktop PCI L1/L3 Telephony";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1231_PCIDEVICE1231_H
