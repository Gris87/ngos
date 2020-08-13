// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1199_PCIDEVICE1199_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1199_PCIDEVICE1199_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1199: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101
};



inline const char8* enumToString(PciDevice1199 device1199) // TEST: NO
{
    // COMMON_LT((" | device1199 = %u", device1199)); // Commented to avoid bad looking logs



    switch (device1199)
    {
        case PciDevice1199::NONE:        return "NONE";
        case PciDevice1199::DEVICE_0101: return "DEVICE_0101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1199 device1199) // TEST: NO
{
    // COMMON_LT((" | device1199 = %u", device1199)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1199, enumToString(device1199));

    return res;
}



inline const char8* enumToHumanString(PciDevice1199 device1199) // TEST: NO
{
    // COMMON_LT((" | device1199 = %u", device1199)); // Commented to avoid bad looking logs



    switch (device1199)
    {
        case PciDevice1199::DEVICE_0101: return "Advanced ISCA/PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1199_PCIDEVICE1199_H
