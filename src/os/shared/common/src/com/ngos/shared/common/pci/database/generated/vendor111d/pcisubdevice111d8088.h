// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111D_PCISUBDEVICE111D8088_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111D_PCISUBDEVICE111D8088_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice111D8088: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1093752F = 0x1093752F,
    SUBDEVICE_10937543 = 0x10937543,
    SUBDEVICE_1093755C = 0x1093755C,
    SUBDEVICE_1093755D = 0x1093755D,
    SUBDEVICE_109375FF = 0x109375FF,
    SUBDEVICE_10937600 = 0x10937600,
    SUBDEVICE_10937602 = 0x10937602
};



inline const char8* enumToString(PciSubDevice111D8088 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111D8088::NONE:               return "NONE";
        case PciSubDevice111D8088::SUBDEVICE_1093752F: return "SUBDEVICE_1093752F";
        case PciSubDevice111D8088::SUBDEVICE_10937543: return "SUBDEVICE_10937543";
        case PciSubDevice111D8088::SUBDEVICE_1093755C: return "SUBDEVICE_1093755C";
        case PciSubDevice111D8088::SUBDEVICE_1093755D: return "SUBDEVICE_1093755D";
        case PciSubDevice111D8088::SUBDEVICE_109375FF: return "SUBDEVICE_109375FF";
        case PciSubDevice111D8088::SUBDEVICE_10937600: return "SUBDEVICE_10937600";
        case PciSubDevice111D8088::SUBDEVICE_10937602: return "SUBDEVICE_10937602";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice111D8088 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice111D8088 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111D8088::SUBDEVICE_1093752F: return "PXIe-8383mc Device";
        case PciSubDevice111D8088::SUBDEVICE_10937543: return "PXIe-8383mc System Host";
        case PciSubDevice111D8088::SUBDEVICE_1093755C: return "PXIe-8364";
        case PciSubDevice111D8088::SUBDEVICE_1093755D: return "PXIe-8374";
        case PciSubDevice111D8088::SUBDEVICE_109375FF: return "PXIe-8383mc DMA";
        case PciSubDevice111D8088::SUBDEVICE_10937600: return "PXIe-8383mc DMA";
        case PciSubDevice111D8088::SUBDEVICE_10937602: return "PXIe-8384";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111D_PCISUBDEVICE111D8088_H
