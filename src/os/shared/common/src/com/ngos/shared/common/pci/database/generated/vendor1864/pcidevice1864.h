// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1864_PCIDEVICE1864_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1864_PCIDEVICE1864_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1864: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2110 = 0x2110
};



inline const char8* enumToString(PciDevice1864 device1864) // TEST: NO
{
    // COMMON_LT((" | device1864 = %u", device1864)); // Commented to avoid bad looking logs



    switch (device1864)
    {
        case PciDevice1864::NONE:        return "NONE";
        case PciDevice1864::DEVICE_2110: return "DEVICE_2110";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1864 device1864) // TEST: NO
{
    // COMMON_LT((" | device1864 = %u", device1864)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1864, enumToString(device1864));

    return res;
}



inline const char8* enumToHumanString(PciDevice1864 device1864) // TEST: NO
{
    // COMMON_LT((" | device1864 = %u", device1864)); // Commented to avoid bad looking logs



    switch (device1864)
    {
        case PciDevice1864::DEVICE_2110: return "ISNAP 2110";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1864_PCIDEVICE1864_H
