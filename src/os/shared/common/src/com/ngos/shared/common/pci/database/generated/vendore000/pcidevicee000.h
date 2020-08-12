// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE000_PCIDEVICEE000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE000_PCIDEVICEE000_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceE000: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E000 = 0xE000
};



inline const char8* enumToString(PciDeviceE000 deviceE000) // TEST: NO
{
    // COMMON_LT((" | deviceE000 = %u", deviceE000)); // Commented to avoid bad looking logs



    switch (deviceE000)
    {
        case PciDeviceE000::NONE:        return "NONE";
        case PciDeviceE000::DEVICE_E000: return "DEVICE_E000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceE000 deviceE000) // TEST: NO
{
    // COMMON_LT((" | deviceE000 = %u", deviceE000)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceE000, enumToString(deviceE000));

    return res;
}



inline const char8* enumToHumanString(PciDeviceE000 deviceE000) // TEST: NO
{
    // COMMON_LT((" | deviceE000 = %u", deviceE000)); // Commented to avoid bad looking logs



    switch (deviceE000)
    {
        case PciDeviceE000::DEVICE_E000: return "W89C940";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORE000_PCIDEVICEE000_H
