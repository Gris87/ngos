// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREA60_PCIDEVICEEA60_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREA60_PCIDEVICEEA60_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceEA60: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9896 = 0x9896,
    DEVICE_9897 = 0x9897,
    DEVICE_9898 = 0x9898
};



inline const char8* enumToString(PciDeviceEA60 deviceEA60) // TEST: NO
{
    // COMMON_LT((" | deviceEA60 = %u", deviceEA60)); // Commented to avoid bad looking logs



    switch (deviceEA60)
    {
        case PciDeviceEA60::NONE:        return "NONE";
        case PciDeviceEA60::DEVICE_9896: return "DEVICE_9896";
        case PciDeviceEA60::DEVICE_9897: return "DEVICE_9897";
        case PciDeviceEA60::DEVICE_9898: return "DEVICE_9898";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceEA60 deviceEA60) // TEST: NO
{
    // COMMON_LT((" | deviceEA60 = %u", deviceEA60)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceEA60, enumToString(deviceEA60));

    return res;
}



inline const char8* enumToHumanString(PciDeviceEA60 deviceEA60) // TEST: NO
{
    // COMMON_LT((" | deviceEA60 = %u", deviceEA60)); // Commented to avoid bad looking logs



    switch (deviceEA60)
    {
        case PciDeviceEA60::DEVICE_9896: return "Digi32";
        case PciDeviceEA60::DEVICE_9897: return "Digi32 Pro";
        case PciDeviceEA60::DEVICE_9898: return "Digi32/8";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREA60_PCIDEVICEEA60_H
