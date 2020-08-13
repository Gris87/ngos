// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15EC_PCIDEVICE15EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15EC_PCIDEVICE15EC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15EC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3101 = 0x3101,
    DEVICE_5102 = 0x5102
};



inline const char8* enumToString(PciDevice15EC device15EC) // TEST: NO
{
    // COMMON_LT((" | device15EC = %u", device15EC)); // Commented to avoid bad looking logs



    switch (device15EC)
    {
        case PciDevice15EC::NONE:        return "NONE";
        case PciDevice15EC::DEVICE_3101: return "DEVICE_3101";
        case PciDevice15EC::DEVICE_5102: return "DEVICE_5102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15EC device15EC) // TEST: NO
{
    // COMMON_LT((" | device15EC = %u", device15EC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15EC, enumToString(device15EC));

    return res;
}



inline const char8* enumToHumanString(PciDevice15EC device15EC) // TEST: NO
{
    // COMMON_LT((" | device15EC = %u", device15EC)); // Commented to avoid bad looking logs



    switch (device15EC)
    {
        case PciDevice15EC::DEVICE_3101: return "FC3101 Profibus DP 1 Channel PCI";
        case PciDevice15EC::DEVICE_5102: return "FC5102";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15EC_PCIDEVICE15EC_H
