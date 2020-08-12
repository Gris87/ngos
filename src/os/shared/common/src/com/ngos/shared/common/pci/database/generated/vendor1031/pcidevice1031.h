// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1031_PCIDEVICE1031_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1031_PCIDEVICE1031_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1031: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5601 = 0x5601,
    DEVICE_5607 = 0x5607,
    DEVICE_5631 = 0x5631,
    DEVICE_6057 = 0x6057
};



inline const char8* enumToString(PciDevice1031 device1031) // TEST: NO
{
    // COMMON_LT((" | device1031 = %u", device1031)); // Commented to avoid bad looking logs



    switch (device1031)
    {
        case PciDevice1031::NONE:        return "NONE";
        case PciDevice1031::DEVICE_5601: return "DEVICE_5601";
        case PciDevice1031::DEVICE_5607: return "DEVICE_5607";
        case PciDevice1031::DEVICE_5631: return "DEVICE_5631";
        case PciDevice1031::DEVICE_6057: return "DEVICE_6057";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1031 device1031) // TEST: NO
{
    // COMMON_LT((" | device1031 = %u", device1031)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1031, enumToString(device1031));

    return res;
}



inline const char8* enumToHumanString(PciDevice1031 device1031) // TEST: NO
{
    // COMMON_LT((" | device1031 = %u", device1031)); // Commented to avoid bad looking logs



    switch (device1031)
    {
        case PciDevice1031::DEVICE_5601: return "DC20 ASIC";
        case PciDevice1031::DEVICE_5607: return "Video I/O & motion JPEG compressor";
        case PciDevice1031::DEVICE_5631: return "Media 3D";
        case PciDevice1031::DEVICE_6057: return "MiroVideo DC10/DC30+";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1031_PCIDEVICE1031_H
