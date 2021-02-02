// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17B3_PCIDEVICE17B3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17B3_PCIDEVICE17B3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17B3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_AB08 = 0xAB08
};



inline const char8* enumToString(PciDevice17B3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17B3::NONE:        return "NONE";
        case PciDevice17B3::DEVICE_AB08: return "DEVICE_AB08";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17B3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice17B3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17B3::DEVICE_AB08: return "PN672TX 10/100 Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17B3_PCIDEVICE17B3_H
