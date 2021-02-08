// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10F5_PCIDEVICE10F5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10F5_PCIDEVICE10F5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10F5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A001 = 0xA001
};



inline const char8* enumToString(PciDevice10F5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10F5::NONE:        return "NONE";
        case PciDevice10F5::DEVICE_A001: return "DEVICE_A001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10F5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10F5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10F5::DEVICE_A001: return "NDR4000 [NR4600 Bridge]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10F5_PCIDEVICE10F5_H
