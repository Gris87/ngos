// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18E6_PCIDEVICE18E6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18E6_PCIDEVICE18E6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18E6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice18E6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18E6::NONE:        return "NONE";
        case PciDevice18E6::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18E6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice18E6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18E6::DEVICE_0001: return "OSCI [Octal Serial Communication Interface]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18E6_PCIDEVICE18E6_H
