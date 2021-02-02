// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D3_PCIDEVICE14D3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D3_PCIDEVICE14D3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14D3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004
};



inline const char8* enumToString(PciDevice14D3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D3::NONE:        return "NONE";
        case PciDevice14D3::DEVICE_0002: return "DEVICE_0002";
        case PciDevice14D3::DEVICE_0003: return "DEVICE_0003";
        case PciDevice14D3::DEVICE_0004: return "DEVICE_0004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14D3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14D3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D3::DEVICE_0002: return "DTL-T14000 Rev. 1 [PS2 TOOL CD/DVD Emulator]";
        case PciDevice14D3::DEVICE_0003: return "DTL-T14000 Rev. 2 [PS2 TOOL CD/DVD Emulator]";
        case PciDevice14D3::DEVICE_0004: return "DTL-T14000 Rev. 3 [PS2 TOOL CD/DVD Emulator]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D3_PCIDEVICE14D3_H
