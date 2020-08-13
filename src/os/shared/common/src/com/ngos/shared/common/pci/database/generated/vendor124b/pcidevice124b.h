// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCIDEVICE124B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCIDEVICE124B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice124B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0040 = 0x0040
};



inline const char8* enumToString(PciDevice124B device124B) // TEST: NO
{
    // COMMON_LT((" | device124B = %u", device124B)); // Commented to avoid bad looking logs



    switch (device124B)
    {
        case PciDevice124B::NONE:        return "NONE";
        case PciDevice124B::DEVICE_0040: return "DEVICE_0040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice124B device124B) // TEST: NO
{
    // COMMON_LT((" | device124B = %u", device124B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device124B, enumToString(device124B));

    return res;
}



inline const char8* enumToHumanString(PciDevice124B device124B) // TEST: NO
{
    // COMMON_LT((" | device124B = %u", device124B)); // Commented to avoid bad looking logs



    switch (device124B)
    {
        case PciDevice124B::DEVICE_0040: return "PCI-40A or cPCI-200 Quad IndustryPack carrier";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124B_PCIDEVICE124B_H
