// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCIDEVICE18EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCIDEVICE18EC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18EC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6D05 = 0x6D05,
    DEVICE_C006 = 0xC006,
    DEVICE_C032 = 0xC032,
    DEVICE_C045 = 0xC045,
    DEVICE_C050 = 0xC050,
    DEVICE_C058 = 0xC058,
    DEVICE_C132 = 0xC132,
    DEVICE_C232 = 0xC232
};



inline const char8* enumToString(PciDevice18EC device18EC) // TEST: NO
{
    // COMMON_LT((" | device18EC = %u", device18EC)); // Commented to avoid bad looking logs



    switch (device18EC)
    {
        case PciDevice18EC::NONE:        return "NONE";
        case PciDevice18EC::DEVICE_6D05: return "DEVICE_6D05";
        case PciDevice18EC::DEVICE_C006: return "DEVICE_C006";
        case PciDevice18EC::DEVICE_C032: return "DEVICE_C032";
        case PciDevice18EC::DEVICE_C045: return "DEVICE_C045";
        case PciDevice18EC::DEVICE_C050: return "DEVICE_C050";
        case PciDevice18EC::DEVICE_C058: return "DEVICE_C058";
        case PciDevice18EC::DEVICE_C132: return "DEVICE_C132";
        case PciDevice18EC::DEVICE_C232: return "DEVICE_C232";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18EC device18EC) // TEST: NO
{
    // COMMON_LT((" | device18EC = %u", device18EC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18EC, enumToString(device18EC));

    return res;
}



inline const char8* enumToHumanString(PciDevice18EC device18EC) // TEST: NO
{
    // COMMON_LT((" | device18EC = %u", device18EC)); // Commented to avoid bad looking logs



    switch (device18EC)
    {
        case PciDevice18EC::DEVICE_6D05: return "ML555";
        case PciDevice18EC::DEVICE_C006: return "COMBO6";
        case PciDevice18EC::DEVICE_C032: return "COMBO-LXT110";
        case PciDevice18EC::DEVICE_C045: return "COMBO6E";
        case PciDevice18EC::DEVICE_C050: return "COMBO-PTM";
        case PciDevice18EC::DEVICE_C058: return "COMBO6X";
        case PciDevice18EC::DEVICE_C132: return "COMBO-LXT155";
        case PciDevice18EC::DEVICE_C232: return "COMBO-FXT100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCIDEVICE18EC_H
