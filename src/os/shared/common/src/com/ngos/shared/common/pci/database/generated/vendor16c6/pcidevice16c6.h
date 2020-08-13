// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16C6_PCIDEVICE16C6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16C6_PCIDEVICE16C6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16C6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8695 = 0x8695,
    DEVICE_8842 = 0x8842
};



inline const char8* enumToString(PciDevice16C6 device16C6) // TEST: NO
{
    // COMMON_LT((" | device16C6 = %u", device16C6)); // Commented to avoid bad looking logs



    switch (device16C6)
    {
        case PciDevice16C6::NONE:        return "NONE";
        case PciDevice16C6::DEVICE_8695: return "DEVICE_8695";
        case PciDevice16C6::DEVICE_8842: return "DEVICE_8842";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16C6 device16C6) // TEST: NO
{
    // COMMON_LT((" | device16C6 = %u", device16C6)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device16C6, enumToString(device16C6));

    return res;
}



inline const char8* enumToHumanString(PciDevice16C6 device16C6) // TEST: NO
{
    // COMMON_LT((" | device16C6 = %u", device16C6)); // Commented to avoid bad looking logs



    switch (device16C6)
    {
        case PciDevice16C6::DEVICE_8695: return "Centaur KS8695 ARM processor";
        case PciDevice16C6::DEVICE_8842: return "KSZ8842-PMQL 2-Port Ethernet Switch";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16C6_PCIDEVICE16C6_H
