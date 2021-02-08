// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BEE_PCIDEVICE1BEE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BEE_PCIDEVICE1BEE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BEE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDevice1BEE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BEE::NONE:        return "NONE";
        case PciDevice1BEE::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BEE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BEE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BEE::DEVICE_0003: return "CAN-IB200/PCIe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BEE_PCIDEVICE1BEE_H
