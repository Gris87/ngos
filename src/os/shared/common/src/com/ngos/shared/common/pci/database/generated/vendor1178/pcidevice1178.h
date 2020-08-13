// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1178_PCIDEVICE1178_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1178_PCIDEVICE1178_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1178: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_AFA1 = 0xAFA1
};



inline const char8* enumToString(PciDevice1178 device1178) // TEST: NO
{
    // COMMON_LT((" | device1178 = %u", device1178)); // Commented to avoid bad looking logs



    switch (device1178)
    {
        case PciDevice1178::NONE:        return "NONE";
        case PciDevice1178::DEVICE_AFA1: return "DEVICE_AFA1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1178 device1178) // TEST: NO
{
    // COMMON_LT((" | device1178 = %u", device1178)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1178, enumToString(device1178));

    return res;
}



inline const char8* enumToHumanString(PciDevice1178 device1178) // TEST: NO
{
    // COMMON_LT((" | device1178 = %u", device1178)); // Commented to avoid bad looking logs



    switch (device1178)
    {
        case PciDevice1178::DEVICE_AFA1: return "Fast Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1178_PCIDEVICE1178_H
