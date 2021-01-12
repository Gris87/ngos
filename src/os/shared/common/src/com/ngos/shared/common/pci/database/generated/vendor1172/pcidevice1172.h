// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1172_PCIDEVICE1172_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1172_PCIDEVICE1172_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1172: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_00A7 = 0x00A7,
    DEVICE_0530 = 0x0530,
    DEVICE_646C = 0x646C
};



inline const char8* enumToString(PciDevice1172 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1172::NONE:        return "NONE";
        case PciDevice1172::DEVICE_00A7: return "DEVICE_00A7";
        case PciDevice1172::DEVICE_0530: return "DEVICE_0530";
        case PciDevice1172::DEVICE_646C: return "DEVICE_646C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1172 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1172 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1172::DEVICE_00A7: return "Stratix V";
        case PciDevice1172::DEVICE_0530: return "Stratix IV";
        case PciDevice1172::DEVICE_646C: return "KT-500/KT-521 board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1172_PCIDEVICE1172_H
