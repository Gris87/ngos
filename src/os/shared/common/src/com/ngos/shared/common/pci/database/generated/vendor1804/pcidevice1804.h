// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1804_PCIDEVICE1804_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1804_PCIDEVICE1804_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1804: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3060 = 0x3060
};



inline const char8* enumToString(PciDevice1804 device1804) // TEST: NO
{
    // COMMON_LT((" | device1804 = %u", device1804)); // Commented to avoid bad looking logs



    switch (device1804)
    {
        case PciDevice1804::NONE:        return "NONE";
        case PciDevice1804::DEVICE_3060: return "DEVICE_3060";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1804 device1804) // TEST: NO
{
    // COMMON_LT((" | device1804 = %u", device1804)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1804, enumToString(device1804));

    return res;
}



inline const char8* enumToHumanString(PciDevice1804 device1804) // TEST: NO
{
    // COMMON_LT((" | device1804 = %u", device1804)); // Commented to avoid bad looking logs



    switch (device1804)
    {
        case PciDevice1804::DEVICE_3060: return "RT3060 Wireless 802.11n 1T/1R";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1804_PCIDEVICE1804_H
