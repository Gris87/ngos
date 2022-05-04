// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E5D_PCIDEVICE1E5D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E5D_PCIDEVICE1E5D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E5D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7000 = 0x7000,
    DEVICE_7010 = 0x7010
};



inline const char8* enumToString(PciDevice1E5D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E5D::NONE:        return "NONE";
        case PciDevice1E5D::DEVICE_7000: return "DEVICE_7000";
        case PciDevice1E5D::DEVICE_7010: return "DEVICE_7010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E5D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E5D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E5D::DEVICE_7000: return "AI controller A7000";
        case PciDevice1E5D::DEVICE_7010: return "AI controller A7010";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E5D_PCIDEVICE1E5D_H
