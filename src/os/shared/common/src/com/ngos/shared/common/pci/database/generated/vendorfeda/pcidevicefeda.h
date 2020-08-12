// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFEDA_PCIDEVICEFEDA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFEDA_PCIDEVICEFEDA_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceFEDA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A0FA = 0xA0FA,
    DEVICE_A10E = 0xA10E
};



inline const char8* enumToString(PciDeviceFEDA deviceFEDA) // TEST: NO
{
    // COMMON_LT((" | deviceFEDA = %u", deviceFEDA)); // Commented to avoid bad looking logs



    switch (deviceFEDA)
    {
        case PciDeviceFEDA::NONE:        return "NONE";
        case PciDeviceFEDA::DEVICE_A0FA: return "DEVICE_A0FA";
        case PciDeviceFEDA::DEVICE_A10E: return "DEVICE_A10E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceFEDA deviceFEDA) // TEST: NO
{
    // COMMON_LT((" | deviceFEDA = %u", deviceFEDA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceFEDA, enumToString(deviceFEDA));

    return res;
}



inline const char8* enumToHumanString(PciDeviceFEDA deviceFEDA) // TEST: NO
{
    // COMMON_LT((" | deviceFEDA = %u", deviceFEDA)); // Commented to avoid bad looking logs



    switch (deviceFEDA)
    {
        case PciDeviceFEDA::DEVICE_A0FA: return "BCM4210 iLine10 HomePNA 2.0";
        case PciDeviceFEDA::DEVICE_A10E: return "BCM4230 iLine10 HomePNA 2.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFEDA_PCIDEVICEFEDA_H
