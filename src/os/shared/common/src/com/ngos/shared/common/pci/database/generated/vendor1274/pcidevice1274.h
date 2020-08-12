// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCIDEVICE1274_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCIDEVICE1274_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1274: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1171 = 0x1171,
    DEVICE_1371 = 0x1371,
    DEVICE_5000 = 0x5000,
    DEVICE_5880 = 0x5880,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002
};



inline const char8* enumToString(PciDevice1274 device1274) // TEST: NO
{
    // COMMON_LT((" | device1274 = %u", device1274)); // Commented to avoid bad looking logs



    switch (device1274)
    {
        case PciDevice1274::NONE:        return "NONE";
        case PciDevice1274::DEVICE_1171: return "DEVICE_1171";
        case PciDevice1274::DEVICE_1371: return "DEVICE_1371";
        case PciDevice1274::DEVICE_5000: return "DEVICE_5000";
        case PciDevice1274::DEVICE_5880: return "DEVICE_5880";
        case PciDevice1274::DEVICE_8001: return "DEVICE_8001";
        case PciDevice1274::DEVICE_8002: return "DEVICE_8002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1274 device1274) // TEST: NO
{
    // COMMON_LT((" | device1274 = %u", device1274)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1274, enumToString(device1274));

    return res;
}



inline const char8* enumToHumanString(PciDevice1274 device1274) // TEST: NO
{
    // COMMON_LT((" | device1274 = %u", device1274)); // Commented to avoid bad looking logs



    switch (device1274)
    {
        case PciDevice1274::DEVICE_1171: return "ES1373 / Creative Labs CT5803 [AudioPCI]";
        case PciDevice1274::DEVICE_1371: return "ES1371/ES1373 / Creative Labs CT2518";
        case PciDevice1274::DEVICE_5000: return "ES1370 [AudioPCI]";
        case PciDevice1274::DEVICE_5880: return "5880B / Creative Labs CT5880";
        case PciDevice1274::DEVICE_8001: return "CT5880 [AudioPCI]";
        case PciDevice1274::DEVICE_8002: return "5880A [AudioPCI]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCIDEVICE1274_H
