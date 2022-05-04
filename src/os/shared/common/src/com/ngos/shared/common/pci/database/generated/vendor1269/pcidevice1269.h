// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1269_PCIDEVICE1269_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1269_PCIDEVICE1269_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1269: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_00B3 = 0x00B3
};



inline const char8* enumToString(PciDevice1269 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1269::NONE:        return "NONE";
        case PciDevice1269::DEVICE_00B3: return "DEVICE_00B3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1269 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1269 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1269::DEVICE_00B3: return "5G Data Card [Cinterion MV31-W]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1269_PCIDEVICE1269_H
