// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCAFE_PCIDEVICECAFE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCAFE_PCIDEVICECAFE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceCAFE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008
};



inline const char8* enumToString(PciDeviceCAFE deviceCAFE) // TEST: NO
{
    // COMMON_LT((" | deviceCAFE = %u", deviceCAFE)); // Commented to avoid bad looking logs



    switch (deviceCAFE)
    {
        case PciDeviceCAFE::NONE:        return "NONE";
        case PciDeviceCAFE::DEVICE_0003: return "DEVICE_0003";
        case PciDeviceCAFE::DEVICE_0006: return "DEVICE_0006";
        case PciDeviceCAFE::DEVICE_0007: return "DEVICE_0007";
        case PciDeviceCAFE::DEVICE_0008: return "DEVICE_0008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceCAFE deviceCAFE) // TEST: NO
{
    // COMMON_LT((" | deviceCAFE = %u", deviceCAFE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceCAFE, enumToString(deviceCAFE));

    return res;
}



inline const char8* enumToHumanString(PciDeviceCAFE deviceCAFE) // TEST: NO
{
    // COMMON_LT((" | deviceCAFE = %u", deviceCAFE)); // Commented to avoid bad looking logs



    switch (deviceCAFE)
    {
        case PciDeviceCAFE::DEVICE_0003: return "Luna K3 Hardware Security Module";
        case PciDeviceCAFE::DEVICE_0006: return "Luna PCI-e 3000 Hardware Security Module";
        case PciDeviceCAFE::DEVICE_0007: return "Luna K6 Hardware Security Module";
        case PciDeviceCAFE::DEVICE_0008: return "Luna K7 Hardware Security Module";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCAFE_PCIDEVICECAFE_H
