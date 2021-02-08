// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D4_PCIDEVICE11D4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D4_PCIDEVICE11D4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11D4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1535 = 0x1535,
    DEVICE_1805 = 0x1805
};



inline const char8* enumToString(PciDevice11D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11D4::NONE:        return "NONE";
        case PciDevice11D4::DEVICE_1535: return "DEVICE_1535";
        case PciDevice11D4::DEVICE_1805: return "DEVICE_1805";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11D4::DEVICE_1535: return "Blackfin BF535 processor";
        case PciDevice11D4::DEVICE_1805: return "SM56 PCI modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D4_PCIDEVICE11D4_H
