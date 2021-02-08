// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1197_PCIDEVICE1197_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1197_PCIDEVICE1197_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1197: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_010C = 0x010C
};



inline const char8* enumToString(PciDevice1197 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1197::NONE:        return "NONE";
        case PciDevice1197::DEVICE_010C: return "DEVICE_010C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1197 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1197 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1197::DEVICE_010C: return "CompuScope 82G 8bit 2GS/s Analog Input Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1197_PCIDEVICE1197_H
