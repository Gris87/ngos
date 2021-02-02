// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR80EE_PCIDEVICE80EE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR80EE_PCIDEVICE80EE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice80EE: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_BEEF = 0xBEEF,
    DEVICE_CAFE = 0xCAFE
};



inline const char8* enumToString(PciDevice80EE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice80EE::NONE:        return "NONE";
        case PciDevice80EE::DEVICE_BEEF: return "DEVICE_BEEF";
        case PciDevice80EE::DEVICE_CAFE: return "DEVICE_CAFE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice80EE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice80EE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice80EE::DEVICE_BEEF: return "VirtualBox Graphics Adapter";
        case PciDevice80EE::DEVICE_CAFE: return "VirtualBox Guest Service";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR80EE_PCIDEVICE80EE_H
