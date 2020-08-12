// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B47_PCIDEVICE1B47_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B47_PCIDEVICE1B47_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B47: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0601 = 0x0601,
    DEVICE_0602 = 0x0602
};



inline const char8* enumToString(PciDevice1B47 device1B47) // TEST: NO
{
    // COMMON_LT((" | device1B47 = %u", device1B47)); // Commented to avoid bad looking logs



    switch (device1B47)
    {
        case PciDevice1B47::NONE:        return "NONE";
        case PciDevice1B47::DEVICE_0601: return "DEVICE_0601";
        case PciDevice1B47::DEVICE_0602: return "DEVICE_0602";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B47 device1B47) // TEST: NO
{
    // COMMON_LT((" | device1B47 = %u", device1B47)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B47, enumToString(device1B47));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B47 device1B47) // TEST: NO
{
    // COMMON_LT((" | device1B47 = %u", device1B47)); // Commented to avoid bad looking logs



    switch (device1B47)
    {
        case PciDevice1B47::DEVICE_0601: return "NumaChip N601";
        case PciDevice1B47::DEVICE_0602: return "NumaChip N602";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B47_PCIDEVICE1B47_H
