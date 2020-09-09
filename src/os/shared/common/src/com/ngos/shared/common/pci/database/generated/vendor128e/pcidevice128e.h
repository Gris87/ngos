// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR128E_PCIDEVICE128E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR128E_PCIDEVICE128E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice128E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C
};



inline const char8* enumToString(PciDevice128E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice128E::NONE:        return "NONE";
        case PciDevice128E::DEVICE_0008: return "DEVICE_0008";
        case PciDevice128E::DEVICE_0009: return "DEVICE_0009";
        case PciDevice128E::DEVICE_000A: return "DEVICE_000A";
        case PciDevice128E::DEVICE_000B: return "DEVICE_000B";
        case PciDevice128E::DEVICE_000C: return "DEVICE_000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice128E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice128E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice128E::DEVICE_0008: return "ST128 WSS/SB";
        case PciDevice128E::DEVICE_0009: return "ST128 SAM9407";
        case PciDevice128E::DEVICE_000A: return "ST128 Game Port";
        case PciDevice128E::DEVICE_000B: return "ST128 MPU Port";
        case PciDevice128E::DEVICE_000C: return "ST128 Ctrl Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR128E_PCIDEVICE128E_H
