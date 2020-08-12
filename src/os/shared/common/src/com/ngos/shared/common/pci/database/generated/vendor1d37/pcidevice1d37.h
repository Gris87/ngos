// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D37_PCIDEVICE1D37_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D37_PCIDEVICE1D37_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D37: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016
};



inline const char8* enumToString(PciDevice1D37 device1D37) // TEST: NO
{
    // COMMON_LT((" | device1D37 = %u", device1D37)); // Commented to avoid bad looking logs



    switch (device1D37)
    {
        case PciDevice1D37::NONE:        return "NONE";
        case PciDevice1D37::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1D37::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1D37::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1D37::DEVICE_0016: return "DEVICE_0016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D37 device1D37) // TEST: NO
{
    // COMMON_LT((" | device1D37 = %u", device1D37)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D37, enumToString(device1D37));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D37 device1D37) // TEST: NO
{
    // COMMON_LT((" | device1D37 = %u", device1D37)); // Commented to avoid bad looking logs



    switch (device1D37)
    {
        case PciDevice1D37::DEVICE_0013: return "PM3";
        case PciDevice1D37::DEVICE_0014: return "PM4";
        case PciDevice1D37::DEVICE_0015: return "PM4edge";
        case PciDevice1D37::DEVICE_0016: return "PM4edge User Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D37_PCIDEVICE1D37_H
