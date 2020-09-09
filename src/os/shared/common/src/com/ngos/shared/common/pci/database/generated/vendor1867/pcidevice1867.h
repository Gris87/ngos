// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1867_PCIDEVICE1867_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1867_PCIDEVICE1867_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1867: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5A44 = 0x5A44,
    DEVICE_5A45 = 0x5A45,
    DEVICE_5A46 = 0x5A46,
    DEVICE_6278 = 0x6278,
    DEVICE_6282 = 0x6282
};



inline const char8* enumToString(PciDevice1867 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1867::NONE:        return "NONE";
        case PciDevice1867::DEVICE_5A44: return "DEVICE_5A44";
        case PciDevice1867::DEVICE_5A45: return "DEVICE_5A45";
        case PciDevice1867::DEVICE_5A46: return "DEVICE_5A46";
        case PciDevice1867::DEVICE_6278: return "DEVICE_6278";
        case PciDevice1867::DEVICE_6282: return "DEVICE_6282";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1867 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1867 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1867::DEVICE_5A44: return "MT23108 InfiniHost HCA";
        case PciDevice1867::DEVICE_5A45: return "MT23108 InfiniHost HCA flash recovery";
        case PciDevice1867::DEVICE_5A46: return "MT23108 InfiniHost HCA bridge";
        case PciDevice1867::DEVICE_6278: return "MT25208 InfiniHost III Ex (Tavor compatibility mode)";
        case PciDevice1867::DEVICE_6282: return "MT25208 InfiniHost III Ex";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1867_PCIDEVICE1867_H
