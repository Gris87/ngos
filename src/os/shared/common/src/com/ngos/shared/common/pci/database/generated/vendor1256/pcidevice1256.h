// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1256_PCIDEVICE1256_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1256_PCIDEVICE1256_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1256: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4201 = 0x4201,
    DEVICE_4401 = 0x4401,
    DEVICE_5201 = 0x5201
};



inline const char8* enumToString(PciDevice1256 device1256) // TEST: NO
{
    // COMMON_LT((" | device1256 = %u", device1256)); // Commented to avoid bad looking logs



    switch (device1256)
    {
        case PciDevice1256::NONE:        return "NONE";
        case PciDevice1256::DEVICE_4201: return "DEVICE_4201";
        case PciDevice1256::DEVICE_4401: return "DEVICE_4401";
        case PciDevice1256::DEVICE_5201: return "DEVICE_5201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1256 device1256) // TEST: NO
{
    // COMMON_LT((" | device1256 = %u", device1256)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1256, enumToString(device1256));

    return res;
}



inline const char8* enumToHumanString(PciDevice1256 device1256) // TEST: NO
{
    // COMMON_LT((" | device1256 = %u", device1256)); // Commented to avoid bad looking logs



    switch (device1256)
    {
        case PciDevice1256::DEVICE_4201: return "PCI-2220I";
        case PciDevice1256::DEVICE_4401: return "PCI-2240I";
        case PciDevice1256::DEVICE_5201: return "PCI-2000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1256_PCIDEVICE1256_H
