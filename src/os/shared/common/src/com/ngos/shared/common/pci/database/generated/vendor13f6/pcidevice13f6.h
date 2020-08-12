// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCIDEVICE13F6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCIDEVICE13F6_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13F6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0011 = 0x0011,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0111 = 0x0111,
    DEVICE_0211 = 0x0211,
    DEVICE_5011 = 0x5011,
    DEVICE_8788 = 0x8788
};



inline const char8* enumToString(PciDevice13F6 device13F6) // TEST: NO
{
    // COMMON_LT((" | device13F6 = %u", device13F6)); // Commented to avoid bad looking logs



    switch (device13F6)
    {
        case PciDevice13F6::NONE:        return "NONE";
        case PciDevice13F6::DEVICE_0011: return "DEVICE_0011";
        case PciDevice13F6::DEVICE_0100: return "DEVICE_0100";
        case PciDevice13F6::DEVICE_0101: return "DEVICE_0101";
        case PciDevice13F6::DEVICE_0111: return "DEVICE_0111";
        case PciDevice13F6::DEVICE_0211: return "DEVICE_0211";
        case PciDevice13F6::DEVICE_5011: return "DEVICE_5011";
        case PciDevice13F6::DEVICE_8788: return "DEVICE_8788";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13F6 device13F6) // TEST: NO
{
    // COMMON_LT((" | device13F6 = %u", device13F6)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device13F6, enumToString(device13F6));

    return res;
}



inline const char8* enumToHumanString(PciDevice13F6 device13F6) // TEST: NO
{
    // COMMON_LT((" | device13F6 = %u", device13F6)); // Commented to avoid bad looking logs



    switch (device13F6)
    {
        case PciDevice13F6::DEVICE_0011: return "CMI8738";
        case PciDevice13F6::DEVICE_0100: return "CM8338A";
        case PciDevice13F6::DEVICE_0101: return "CM8338B";
        case PciDevice13F6::DEVICE_0111: return "CMI8738/CMI8768 PCI Audio";
        case PciDevice13F6::DEVICE_0211: return "CM8738";
        case PciDevice13F6::DEVICE_5011: return "CM8888 [Oxygen Express]";
        case PciDevice13F6::DEVICE_8788: return "CMI8788 [Oxygen HD Audio]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCIDEVICE13F6_H
