// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5045_PCIDEVICE5045_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5045_PCIDEVICE5045_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5045: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4243 = 0x4243
};



inline const char8* enumToString(PciDevice5045 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5045::NONE:        return "NONE";
        case PciDevice5045::DEVICE_4243: return "DEVICE_4243";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5045 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice5045 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5045::DEVICE_4243: return "BLASTbus PCI Interface Card v1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5045_PCIDEVICE5045_H
