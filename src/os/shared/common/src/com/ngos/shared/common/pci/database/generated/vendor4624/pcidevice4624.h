// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4624_PCIDEVICE4624_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4624_PCIDEVICE4624_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4624: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_ADC1 = 0xADC1,
    DEVICE_DE01 = 0xDE01,
    DEVICE_DE02 = 0xDE02
};



inline const char8* enumToString(PciDevice4624 device4624) // TEST: NO
{
    // COMMON_LT((" | device4624 = %u", device4624)); // Commented to avoid bad looking logs



    switch (device4624)
    {
        case PciDevice4624::NONE:        return "NONE";
        case PciDevice4624::DEVICE_ADC1: return "DEVICE_ADC1";
        case PciDevice4624::DEVICE_DE01: return "DEVICE_DE01";
        case PciDevice4624::DEVICE_DE02: return "DEVICE_DE02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4624 device4624) // TEST: NO
{
    // COMMON_LT((" | device4624 = %u", device4624)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4624, enumToString(device4624));

    return res;
}



inline const char8* enumToHumanString(PciDevice4624 device4624) // TEST: NO
{
    // COMMON_LT((" | device4624 = %u", device4624)); // Commented to avoid bad looking logs



    switch (device4624)
    {
        case PciDevice4624::DEVICE_ADC1: return "ADC200ME High speed ADC";
        case PciDevice4624::DEVICE_DE01: return "DL200ME High resolution delay line PCI based card";
        case PciDevice4624::DEVICE_DE02: return "DL200ME Middle resolution delay line PCI based card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4624_PCIDEVICE4624_H
