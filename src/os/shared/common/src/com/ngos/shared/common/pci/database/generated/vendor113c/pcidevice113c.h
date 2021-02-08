// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR113C_PCIDEVICE113C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR113C_PCIDEVICE113C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice113C: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0911 = 0x0911,
    DEVICE_0912 = 0x0912,
    DEVICE_0913 = 0x0913,
    DEVICE_0914 = 0x0914
};



inline const char8* enumToString(PciDevice113C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice113C::DEVICE_0000: return "DEVICE_0000";
        case PciDevice113C::DEVICE_0001: return "DEVICE_0001";
        case PciDevice113C::DEVICE_0911: return "DEVICE_0911";
        case PciDevice113C::DEVICE_0912: return "DEVICE_0912";
        case PciDevice113C::DEVICE_0913: return "DEVICE_0913";
        case PciDevice113C::DEVICE_0914: return "DEVICE_0914";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice113C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice113C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice113C::DEVICE_0000: return "PCI-9060 i960 Bridge";
        case PciDevice113C::DEVICE_0001: return "PCI-SDK [PCI i960 Evaluation Platform]";
        case PciDevice113C::DEVICE_0911: return "PCI-911 [i960Jx-based Intelligent I/O Controller]";
        case PciDevice113C::DEVICE_0912: return "PCI-912 [i960CF-based Intelligent I/O Controller]";
        case PciDevice113C::DEVICE_0913: return "PCI-913";
        case PciDevice113C::DEVICE_0914: return "PCI-914 [I/O Controller w/ secondary PCI bus]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR113C_PCIDEVICE113C_H
