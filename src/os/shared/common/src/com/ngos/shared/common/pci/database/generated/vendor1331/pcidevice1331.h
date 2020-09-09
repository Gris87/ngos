// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1331_PCIDEVICE1331_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1331_PCIDEVICE1331_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1331: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0030 = 0x0030,
    DEVICE_8200 = 0x8200,
    DEVICE_8201 = 0x8201,
    DEVICE_8202 = 0x8202,
    DEVICE_8210 = 0x8210
};



inline const char8* enumToString(PciDevice1331 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1331::NONE:        return "NONE";
        case PciDevice1331::DEVICE_0030: return "DEVICE_0030";
        case PciDevice1331::DEVICE_8200: return "DEVICE_8200";
        case PciDevice1331::DEVICE_8201: return "DEVICE_8201";
        case PciDevice1331::DEVICE_8202: return "DEVICE_8202";
        case PciDevice1331::DEVICE_8210: return "DEVICE_8210";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1331 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1331 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1331::DEVICE_0030: return "ENP-2611";
        case PciDevice1331::DEVICE_8200: return "82600 Host Bridge";
        case PciDevice1331::DEVICE_8201: return "82600 IDE";
        case PciDevice1331::DEVICE_8202: return "82600 USB";
        case PciDevice1331::DEVICE_8210: return "82600 PCI Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1331_PCIDEVICE1331_H
