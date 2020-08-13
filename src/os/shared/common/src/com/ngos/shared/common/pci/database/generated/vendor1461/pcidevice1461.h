// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1461_PCIDEVICE1461_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1461_PCIDEVICE1461_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1461: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A3CE = 0xA3CE,
    DEVICE_A3CF = 0xA3CF,
    DEVICE_A836 = 0xA836,
    DEVICE_E836 = 0xE836,
    DEVICE_F436 = 0xF436
};



inline const char8* enumToString(PciDevice1461 device1461) // TEST: NO
{
    // COMMON_LT((" | device1461 = %u", device1461)); // Commented to avoid bad looking logs



    switch (device1461)
    {
        case PciDevice1461::NONE:        return "NONE";
        case PciDevice1461::DEVICE_A3CE: return "DEVICE_A3CE";
        case PciDevice1461::DEVICE_A3CF: return "DEVICE_A3CF";
        case PciDevice1461::DEVICE_A836: return "DEVICE_A836";
        case PciDevice1461::DEVICE_E836: return "DEVICE_E836";
        case PciDevice1461::DEVICE_F436: return "DEVICE_F436";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1461 device1461) // TEST: NO
{
    // COMMON_LT((" | device1461 = %u", device1461)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1461, enumToString(device1461));

    return res;
}



inline const char8* enumToHumanString(PciDevice1461 device1461) // TEST: NO
{
    // COMMON_LT((" | device1461 = %u", device1461)); // Commented to avoid bad looking logs



    switch (device1461)
    {
        case PciDevice1461::DEVICE_A3CE: return "M179";
        case PciDevice1461::DEVICE_A3CF: return "M179";
        case PciDevice1461::DEVICE_A836: return "M115 DVB-T, PAL/SECAM/NTSC Tuner";
        case PciDevice1461::DEVICE_E836: return "M115S Hybrid Analog/DVB PAL/SECAM/NTSC Tuner";
        case PciDevice1461::DEVICE_F436: return "AVerTV Hybrid+FM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1461_PCIDEVICE1461_H
