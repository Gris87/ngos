// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCDDD_PCIDEVICECDDD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCDDD_PCIDEVICECDDD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceCDDD: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDeviceCDDD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceCDDD::NONE:        return "NONE";
        case PciDeviceCDDD::DEVICE_0101: return "DEVICE_0101";
        case PciDeviceCDDD::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceCDDD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceCDDD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceCDDD::DEVICE_0101: return "DeepSea 1 High Speed Stereo Vision Frame Grabber";
        case PciDeviceCDDD::DEVICE_0200: return "DeepSea 2 High Speed Stereo Vision Frame Grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCDDD_PCIDEVICECDDD_H
