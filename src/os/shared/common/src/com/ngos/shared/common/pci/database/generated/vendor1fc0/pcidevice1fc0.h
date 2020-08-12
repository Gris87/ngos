// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC0_PCIDEVICE1FC0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC0_PCIDEVICE1FC0_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1FC0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0300 = 0x0300,
    DEVICE_0301 = 0x0301
};



inline const char8* enumToString(PciDevice1FC0 device1FC0) // TEST: NO
{
    // COMMON_LT((" | device1FC0 = %u", device1FC0)); // Commented to avoid bad looking logs



    switch (device1FC0)
    {
        case PciDevice1FC0::NONE:        return "NONE";
        case PciDevice1FC0::DEVICE_0300: return "DEVICE_0300";
        case PciDevice1FC0::DEVICE_0301: return "DEVICE_0301";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1FC0 device1FC0) // TEST: NO
{
    // COMMON_LT((" | device1FC0 = %u", device1FC0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1FC0, enumToString(device1FC0));

    return res;
}



inline const char8* enumToHumanString(PciDevice1FC0 device1FC0) // TEST: NO
{
    // COMMON_LT((" | device1FC0 = %u", device1FC0)); // Commented to avoid bad looking logs



    switch (device1FC0)
    {
        case PciDevice1FC0::DEVICE_0300: return "E2200 Dual E1/Rawpipe Card";
        case PciDevice1FC0::DEVICE_0301: return "C5400 SHDSL/E1 Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC0_PCIDEVICE1FC0_H
