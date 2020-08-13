// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDEDA_PCIDEVICEDEDA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDEDA_PCIDEVICEDEDA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceDEDA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4001 = 0x4001,
    DEVICE_4021 = 0x4021
};



inline const char8* enumToString(PciDeviceDEDA deviceDEDA) // TEST: NO
{
    // COMMON_LT((" | deviceDEDA = %u", deviceDEDA)); // Commented to avoid bad looking logs



    switch (deviceDEDA)
    {
        case PciDeviceDEDA::NONE:        return "NONE";
        case PciDeviceDEDA::DEVICE_4001: return "DEVICE_4001";
        case PciDeviceDEDA::DEVICE_4021: return "DEVICE_4021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceDEDA deviceDEDA) // TEST: NO
{
    // COMMON_LT((" | deviceDEDA = %u", deviceDEDA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceDEDA, enumToString(deviceDEDA));

    return res;
}



inline const char8* enumToHumanString(PciDeviceDEDA deviceDEDA) // TEST: NO
{
    // COMMON_LT((" | deviceDEDA = %u", deviceDEDA)); // Commented to avoid bad looking logs



    switch (deviceDEDA)
    {
        case PciDeviceDEDA::DEVICE_4001: return "CB or MX camera";
        case PciDeviceDEDA::DEVICE_4021: return "MT camera";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDEDA_PCIDEVICEDEDA_H
