// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14EA_PCIDEVICE14EA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14EA_PCIDEVICE14EA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14EA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_AB06 = 0xAB06,
    DEVICE_AB07 = 0xAB07,
    DEVICE_AB08 = 0xAB08
};



inline const char8* enumToString(PciDevice14EA device14EA) // TEST: NO
{
    // COMMON_LT((" | device14EA = %u", device14EA)); // Commented to avoid bad looking logs



    switch (device14EA)
    {
        case PciDevice14EA::NONE:        return "NONE";
        case PciDevice14EA::DEVICE_AB06: return "DEVICE_AB06";
        case PciDevice14EA::DEVICE_AB07: return "DEVICE_AB07";
        case PciDevice14EA::DEVICE_AB08: return "DEVICE_AB08";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14EA device14EA) // TEST: NO
{
    // COMMON_LT((" | device14EA = %u", device14EA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14EA, enumToString(device14EA));

    return res;
}



inline const char8* enumToHumanString(PciDevice14EA device14EA) // TEST: NO
{
    // COMMON_LT((" | device14EA = %u", device14EA)); // Commented to avoid bad looking logs



    switch (device14EA)
    {
        case PciDevice14EA::DEVICE_AB06: return "FNW-3603-TX CardBus Fast Ethernet";
        case PciDevice14EA::DEVICE_AB07: return "RTL81xx RealTek Ethernet";
        case PciDevice14EA::DEVICE_AB08: return "FNW-3602-TX CardBus Fast Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14EA_PCIDEVICE14EA_H
