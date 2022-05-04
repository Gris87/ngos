// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D1C_PCIDEVICE1D1C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D1C_PCIDEVICE1D1C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D1C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0010 = 0x0010,
    DEVICE_0100 = 0x0100,
    DEVICE_0110 = 0x0110
};



inline const char8* enumToString(PciDevice1D1C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D1C::NONE:        return "NONE";
        case PciDevice1D1C::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1D1C::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1D1C::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1D1C::DEVICE_0110: return "DEVICE_0110";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D1C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D1C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D1C::DEVICE_0001: return "Tofino 1";
        case PciDevice1D1C::DEVICE_0010: return "Tofino 1";
        case PciDevice1D1C::DEVICE_0100: return "Tofino 2";
        case PciDevice1D1C::DEVICE_0110: return "Tofino 2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D1C_PCIDEVICE1D1C_H
