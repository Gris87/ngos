// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1259_PCIDEVICE1259_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1259_PCIDEVICE1259_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1259: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2560 = 0x2560,
    DEVICE_2801 = 0x2801,
    DEVICE_A117 = 0xA117,
    DEVICE_A11E = 0xA11E,
    DEVICE_A120 = 0xA120
};



inline const char8* enumToString(PciDevice1259 device1259) // TEST: NO
{
    // COMMON_LT((" | device1259 = %u", device1259)); // Commented to avoid bad looking logs



    switch (device1259)
    {
        case PciDevice1259::NONE:        return "NONE";
        case PciDevice1259::DEVICE_2560: return "DEVICE_2560";
        case PciDevice1259::DEVICE_2801: return "DEVICE_2801";
        case PciDevice1259::DEVICE_A117: return "DEVICE_A117";
        case PciDevice1259::DEVICE_A11E: return "DEVICE_A11E";
        case PciDevice1259::DEVICE_A120: return "DEVICE_A120";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1259 device1259) // TEST: NO
{
    // COMMON_LT((" | device1259 = %u", device1259)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1259, enumToString(device1259));

    return res;
}



inline const char8* enumToHumanString(PciDevice1259 device1259) // TEST: NO
{
    // COMMON_LT((" | device1259 = %u", device1259)); // Commented to avoid bad looking logs



    switch (device1259)
    {
        case PciDevice1259::DEVICE_2560: return "AT-2560 Fast Ethernet Adapter (i82557B)";
        case PciDevice1259::DEVICE_2801: return "AT-2801FX (RTL-8139)";
        case PciDevice1259::DEVICE_A117: return "RTL81xx Fast Ethernet";
        case PciDevice1259::DEVICE_A11E: return "RTL81xx Fast Ethernet";
        case PciDevice1259::DEVICE_A120: return "21x4x DEC-Tulip compatible 10/100 Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1259_PCIDEVICE1259_H
