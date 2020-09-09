// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A0E_PCIDEVICE1A0E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A0E_PCIDEVICE1A0E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A0E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_083F = 0x083F
};



inline const char8* enumToString(PciDevice1A0E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A0E::NONE:        return "NONE";
        case PciDevice1A0E::DEVICE_083F: return "DEVICE_083F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A0E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A0E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A0E::DEVICE_083F: return "DTA-2111 VHF/UHF Modulator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A0E_PCIDEVICE1A0E_H
