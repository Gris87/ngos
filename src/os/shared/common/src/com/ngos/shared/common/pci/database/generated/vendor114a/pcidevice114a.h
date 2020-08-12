// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114A_PCIDEVICE114A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114A_PCIDEVICE114A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice114A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5565 = 0x5565,
    DEVICE_5579 = 0x5579,
    DEVICE_5587 = 0x5587,
    DEVICE_6504 = 0x6504,
    DEVICE_7587 = 0x7587
};



inline const char8* enumToString(PciDevice114A device114A) // TEST: NO
{
    // COMMON_LT((" | device114A = %u", device114A)); // Commented to avoid bad looking logs



    switch (device114A)
    {
        case PciDevice114A::NONE:        return "NONE";
        case PciDevice114A::DEVICE_5565: return "DEVICE_5565";
        case PciDevice114A::DEVICE_5579: return "DEVICE_5579";
        case PciDevice114A::DEVICE_5587: return "DEVICE_5587";
        case PciDevice114A::DEVICE_6504: return "DEVICE_6504";
        case PciDevice114A::DEVICE_7587: return "DEVICE_7587";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice114A device114A) // TEST: NO
{
    // COMMON_LT((" | device114A = %u", device114A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device114A, enumToString(device114A));

    return res;
}



inline const char8* enumToHumanString(PciDevice114A device114A) // TEST: NO
{
    // COMMON_LT((" | device114A = %u", device114A)); // Commented to avoid bad looking logs



    switch (device114A)
    {
        case PciDevice114A::DEVICE_5565: return "GE-IP PCI5565, PMC5565 Reflective Memory Node";
        case PciDevice114A::DEVICE_5579: return "VMIPCI-5579 (Reflective Memory Card)";
        case PciDevice114A::DEVICE_5587: return "VMIPCI-5587 (Reflective Memory Card)";
        case PciDevice114A::DEVICE_6504: return "VMIC PCI 7755 FPGA";
        case PciDevice114A::DEVICE_7587: return "VMIVME-7587";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114A_PCIDEVICE114A_H
