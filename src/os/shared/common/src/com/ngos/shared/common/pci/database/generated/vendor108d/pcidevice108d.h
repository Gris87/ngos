// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCIDEVICE108D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCIDEVICE108D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice108D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0019 = 0x0019,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022
};



inline const char8* enumToString(PciDevice108D device108D) // TEST: NO
{
    // COMMON_LT((" | device108D = %u", device108D)); // Commented to avoid bad looking logs



    switch (device108D)
    {
        case PciDevice108D::NONE:        return "NONE";
        case PciDevice108D::DEVICE_0001: return "DEVICE_0001";
        case PciDevice108D::DEVICE_0002: return "DEVICE_0002";
        case PciDevice108D::DEVICE_0004: return "DEVICE_0004";
        case PciDevice108D::DEVICE_0005: return "DEVICE_0005";
        case PciDevice108D::DEVICE_0006: return "DEVICE_0006";
        case PciDevice108D::DEVICE_0007: return "DEVICE_0007";
        case PciDevice108D::DEVICE_0008: return "DEVICE_0008";
        case PciDevice108D::DEVICE_0011: return "DEVICE_0011";
        case PciDevice108D::DEVICE_0012: return "DEVICE_0012";
        case PciDevice108D::DEVICE_0013: return "DEVICE_0013";
        case PciDevice108D::DEVICE_0014: return "DEVICE_0014";
        case PciDevice108D::DEVICE_0019: return "DEVICE_0019";
        case PciDevice108D::DEVICE_0021: return "DEVICE_0021";
        case PciDevice108D::DEVICE_0022: return "DEVICE_0022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice108D device108D) // TEST: NO
{
    // COMMON_LT((" | device108D = %u", device108D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device108D, enumToString(device108D));

    return res;
}



inline const char8* enumToHumanString(PciDevice108D device108D) // TEST: NO
{
    // COMMON_LT((" | device108D = %u", device108D)); // Commented to avoid bad looking logs



    switch (device108D)
    {
        case PciDevice108D::DEVICE_0001: return "Token-Ring 16/4 PCI Adapter (3136/3137)";
        case PciDevice108D::DEVICE_0002: return "16/4 Token Ring";
        case PciDevice108D::DEVICE_0004: return "RapidFire OC-3139/3140 Token-Ring 16/4 PCI Adapter";
        case PciDevice108D::DEVICE_0005: return "GoCard 3250 Token-Ring 16/4 CardBus PC Card";
        case PciDevice108D::DEVICE_0006: return "OC-3530 RapidFire Token-Ring 100";
        case PciDevice108D::DEVICE_0007: return "RapidFire 3141 Token-Ring 16/4 PCI Fiber Adapter";
        case PciDevice108D::DEVICE_0008: return "RapidFire 3540 HSTR 100/16/4 PCI Adapter";
        case PciDevice108D::DEVICE_0011: return "OC-2315";
        case PciDevice108D::DEVICE_0012: return "OC-2325";
        case PciDevice108D::DEVICE_0013: return "OC-2183/2185";
        case PciDevice108D::DEVICE_0014: return "OC-2326";
        case PciDevice108D::DEVICE_0019: return "OC-2327/2250 10/100 Ethernet Adapter";
        case PciDevice108D::DEVICE_0021: return "OC-6151/6152 [RapidFire ATM 155]";
        case PciDevice108D::DEVICE_0022: return "ATM Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR108D_PCIDEVICE108D_H
