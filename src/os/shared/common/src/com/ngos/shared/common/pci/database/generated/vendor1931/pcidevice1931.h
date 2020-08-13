// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1931_PCIDEVICE1931_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1931_PCIDEVICE1931_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1931: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000C = 0x000C
};



inline const char8* enumToString(PciDevice1931 device1931) // TEST: NO
{
    // COMMON_LT((" | device1931 = %u", device1931)); // Commented to avoid bad looking logs



    switch (device1931)
    {
        case PciDevice1931::NONE:        return "NONE";
        case PciDevice1931::DEVICE_000C: return "DEVICE_000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1931 device1931) // TEST: NO
{
    // COMMON_LT((" | device1931 = %u", device1931)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1931, enumToString(device1931));

    return res;
}



inline const char8* enumToHumanString(PciDevice1931 device1931) // TEST: NO
{
    // COMMON_LT((" | device1931 = %u", device1931)); // Commented to avoid bad looking logs



    switch (device1931)
    {
        case PciDevice1931::DEVICE_000C: return "Qualcomm MSM6275 UMTS chip";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1931_PCIDEVICE1931_H
