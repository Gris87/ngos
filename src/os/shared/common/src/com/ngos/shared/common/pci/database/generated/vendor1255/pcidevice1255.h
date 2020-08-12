// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1255_PCIDEVICE1255_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1255_PCIDEVICE1255_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1255: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1110 = 0x1110,
    DEVICE_1210 = 0x1210,
    DEVICE_2110 = 0x2110,
    DEVICE_2120 = 0x2120,
    DEVICE_2130 = 0x2130
};



inline const char8* enumToString(PciDevice1255 device1255) // TEST: NO
{
    // COMMON_LT((" | device1255 = %u", device1255)); // Commented to avoid bad looking logs



    switch (device1255)
    {
        case PciDevice1255::NONE:        return "NONE";
        case PciDevice1255::DEVICE_1110: return "DEVICE_1110";
        case PciDevice1255::DEVICE_1210: return "DEVICE_1210";
        case PciDevice1255::DEVICE_2110: return "DEVICE_2110";
        case PciDevice1255::DEVICE_2120: return "DEVICE_2120";
        case PciDevice1255::DEVICE_2130: return "DEVICE_2130";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1255 device1255) // TEST: NO
{
    // COMMON_LT((" | device1255 = %u", device1255)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1255, enumToString(device1255));

    return res;
}



inline const char8* enumToHumanString(PciDevice1255 device1255) // TEST: NO
{
    // COMMON_LT((" | device1255 = %u", device1255)); // Commented to avoid bad looking logs



    switch (device1255)
    {
        case PciDevice1255::DEVICE_1110: return "MPEG Forge";
        case PciDevice1255::DEVICE_1210: return "MPEG Fusion";
        case PciDevice1255::DEVICE_2110: return "VideoPlex";
        case PciDevice1255::DEVICE_2120: return "VideoPlex CC";
        case PciDevice1255::DEVICE_2130: return "VideoQuest";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1255_PCIDEVICE1255_H
