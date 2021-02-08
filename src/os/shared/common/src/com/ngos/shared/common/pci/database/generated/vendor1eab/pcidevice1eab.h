// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EAB_PCIDEVICE1EAB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EAB_PCIDEVICE1EAB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1EAB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_300A = 0x300A,
    DEVICE_300B = 0x300B
};



inline const char8* enumToString(PciDevice1EAB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EAB::NONE:        return "NONE";
        case PciDevice1EAB::DEVICE_300A: return "DEVICE_300A";
        case PciDevice1EAB::DEVICE_300B: return "DEVICE_300B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1EAB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1EAB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EAB::DEVICE_300A: return "NVMe SSD Controller 300A";
        case PciDevice1EAB::DEVICE_300B: return "NVMe SSD Controller 300B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EAB_PCIDEVICE1EAB_H
