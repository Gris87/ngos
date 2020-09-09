// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12E0_PCIDEVICE12E0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12E0_PCIDEVICE12E0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12E0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0020 = 0x0020,
    DEVICE_0030 = 0x0030
};



inline const char8* enumToString(PciDevice12E0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12E0::NONE:        return "NONE";
        case PciDevice12E0::DEVICE_0010: return "DEVICE_0010";
        case PciDevice12E0::DEVICE_0020: return "DEVICE_0020";
        case PciDevice12E0::DEVICE_0030: return "DEVICE_0030";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12E0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12E0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12E0::DEVICE_0010: return "ST16C654 Quad UART";
        case PciDevice12E0::DEVICE_0020: return "ST16C654 Quad UART";
        case PciDevice12E0::DEVICE_0030: return "ST16C654 Quad UART";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12E0_PCIDEVICE12E0_H
