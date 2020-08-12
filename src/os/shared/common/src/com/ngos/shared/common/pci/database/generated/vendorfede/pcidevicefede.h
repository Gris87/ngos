// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFEDE_PCIDEVICEFEDE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFEDE_PCIDEVICEFEDE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceFEDE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDeviceFEDE deviceFEDE) // TEST: NO
{
    // COMMON_LT((" | deviceFEDE = %u", deviceFEDE)); // Commented to avoid bad looking logs



    switch (deviceFEDE)
    {
        case PciDeviceFEDE::NONE:        return "NONE";
        case PciDeviceFEDE::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceFEDE deviceFEDE) // TEST: NO
{
    // COMMON_LT((" | deviceFEDE = %u", deviceFEDE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceFEDE, enumToString(deviceFEDE));

    return res;
}



inline const char8* enumToHumanString(PciDeviceFEDE deviceFEDE) // TEST: NO
{
    // COMMON_LT((" | deviceFEDE = %u", deviceFEDE)); // Commented to avoid bad looking logs



    switch (deviceFEDE)
    {
        case PciDeviceFEDE::DEVICE_0003: return "TABIC PCI v3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFEDE_PCIDEVICEFEDE_H
