// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8E2E_PCIDEVICE8E2E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8E2E_PCIDEVICE8E2E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice8E2E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3000 = 0x3000
};



inline const char8* enumToString(PciDevice8E2E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8E2E::NONE:        return "NONE";
        case PciDevice8E2E::DEVICE_3000: return "DEVICE_3000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice8E2E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice8E2E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8E2E::DEVICE_3000: return "ET32P2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8E2E_PCIDEVICE8E2E_H
