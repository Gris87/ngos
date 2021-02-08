// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C7_PCIDEVICE12C7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C7_PCIDEVICE12C7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12C7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0546 = 0x0546,
    DEVICE_0647 = 0x0647,
    DEVICE_0676 = 0x0676,
    DEVICE_0685 = 0x0685
};



inline const char8* enumToString(PciDevice12C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12C7::NONE:        return "NONE";
        case PciDevice12C7::DEVICE_0546: return "DEVICE_0546";
        case PciDevice12C7::DEVICE_0647: return "DEVICE_0647";
        case PciDevice12C7::DEVICE_0676: return "DEVICE_0676";
        case PciDevice12C7::DEVICE_0685: return "DEVICE_0685";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12C7::DEVICE_0546: return "Springware D/120JCT-LS";
        case PciDevice12C7::DEVICE_0647: return "Springware D/240JCT-T1";
        case PciDevice12C7::DEVICE_0676: return "Springware D/41JCT-LS";
        case PciDevice12C7::DEVICE_0685: return "Springware D/480JCT-2T1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C7_PCIDEVICE12C7_H
