// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DED_PCIDEVICE1DED_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DED_PCIDEVICE1DED_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DED: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_107F = 0x107F,
    DEVICE_5007 = 0x5007,
    DEVICE_8000 = 0x8000,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002,
    DEVICE_8003 = 0x8003,
    DEVICE_8004 = 0x8004
};



inline const char8* enumToString(PciDevice1DED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DED::NONE:        return "NONE";
        case PciDevice1DED::DEVICE_107F: return "DEVICE_107F";
        case PciDevice1DED::DEVICE_5007: return "DEVICE_5007";
        case PciDevice1DED::DEVICE_8000: return "DEVICE_8000";
        case PciDevice1DED::DEVICE_8001: return "DEVICE_8001";
        case PciDevice1DED::DEVICE_8002: return "DEVICE_8002";
        case PciDevice1DED::DEVICE_8003: return "DEVICE_8003";
        case PciDevice1DED::DEVICE_8004: return "DEVICE_8004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DED device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DED::DEVICE_107F: return "Elastic RDMA Adapter";
        case PciDevice1DED::DEVICE_5007: return "Elastic RDMA Adapter";
        case PciDevice1DED::DEVICE_8000: return "M1 Root Port";
        case PciDevice1DED::DEVICE_8001: return "ACC-RCiEP";
        case PciDevice1DED::DEVICE_8002: return "RCiEP VF";
        case PciDevice1DED::DEVICE_8003: return "RCEC PF";
        case PciDevice1DED::DEVICE_8004: return "RCEC VF";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DED_PCIDEVICE1DED_H
