// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FD4_PCIDEVICE1FD4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FD4_PCIDEVICE1FD4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1FD4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_1999 = 0x1999
};



inline const char8* enumToString(PciDevice1FD4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1FD4::NONE:        return "NONE";
        case PciDevice1FD4::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1FD4::DEVICE_1999: return "DEVICE_1999";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1FD4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1FD4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1FD4::DEVICE_0001: return "Matrix multiport serial adapter";
        case PciDevice1FD4::DEVICE_1999: return "Multiport serial controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FD4_PCIDEVICE1FD4_H
