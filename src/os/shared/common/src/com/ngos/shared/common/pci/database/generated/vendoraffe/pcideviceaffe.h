// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAFFE_PCIDEVICEAFFE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAFFE_PCIDEVICEAFFE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceAFFE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_01E1 = 0x01E1,
    DEVICE_02E1 = 0x02E1,
    DEVICE_450E = 0x450E,
    DEVICE_DEAD = 0xDEAD
};



inline const char8* enumToString(PciDeviceAFFE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceAFFE::NONE:        return "NONE";
        case PciDeviceAFFE::DEVICE_01E1: return "DEVICE_01E1";
        case PciDeviceAFFE::DEVICE_02E1: return "DEVICE_02E1";
        case PciDeviceAFFE::DEVICE_450E: return "DEVICE_450E";
        case PciDeviceAFFE::DEVICE_DEAD: return "DEVICE_DEAD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceAFFE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceAFFE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceAFFE::DEVICE_01E1: return "PCI1E1 1-port ISDN E1 interface";
        case PciDeviceAFFE::DEVICE_02E1: return "PCI2E1 2-port ISDN E1 interface";
        case PciDeviceAFFE::DEVICE_450E: return "PCI4S0EC 4-port ISDN S0 interface";
        case PciDeviceAFFE::DEVICE_DEAD: return "Sirrix.PCI4S0 4-port ISDN S0 interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORAFFE_PCIDEVICEAFFE_H
