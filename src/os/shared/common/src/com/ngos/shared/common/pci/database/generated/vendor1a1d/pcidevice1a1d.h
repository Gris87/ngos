// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A1D_PCIDEVICE1A1D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A1D_PCIDEVICE1A1D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A1D: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1A17 = 0x1A17
};



inline const char8* enumToString(PciDevice1A1D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A1D::NONE:        return "NONE";
        case PciDevice1A1D::DEVICE_1A17: return "DEVICE_1A17";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A1D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A1D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A1D::DEVICE_1A17: return "Meta Networks MTP-1G IDPS NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A1D_PCIDEVICE1A1D_H
