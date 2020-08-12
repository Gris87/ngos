// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B74_PCIDEVICE1B74_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B74_PCIDEVICE1B74_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B74: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0115 = 0x0115,
    DEVICE_D130 = 0xD130,
    DEVICE_D210 = 0xD210,
    DEVICE_D230 = 0xD230,
    DEVICE_D410 = 0xD410,
    DEVICE_D430 = 0xD430
};



inline const char8* enumToString(PciDevice1B74 device1B74) // TEST: NO
{
    // COMMON_LT((" | device1B74 = %u", device1B74)); // Commented to avoid bad looking logs



    switch (device1B74)
    {
        case PciDevice1B74::NONE:        return "NONE";
        case PciDevice1B74::DEVICE_0115: return "DEVICE_0115";
        case PciDevice1B74::DEVICE_D130: return "DEVICE_D130";
        case PciDevice1B74::DEVICE_D210: return "DEVICE_D210";
        case PciDevice1B74::DEVICE_D230: return "DEVICE_D230";
        case PciDevice1B74::DEVICE_D410: return "DEVICE_D410";
        case PciDevice1B74::DEVICE_D430: return "DEVICE_D430";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B74 device1B74) // TEST: NO
{
    // COMMON_LT((" | device1B74 = %u", device1B74)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B74, enumToString(device1B74));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B74 device1B74) // TEST: NO
{
    // COMMON_LT((" | device1B74 = %u", device1B74)); // Commented to avoid bad looking logs



    switch (device1B74)
    {
        case PciDevice1B74::DEVICE_0115: return "D115P/D115E Single-port E1/T1 card";
        case PciDevice1B74::DEVICE_D130: return "D130P/D130E Single-port E1/T1 card (3rd GEN)";
        case PciDevice1B74::DEVICE_D210: return "D210P/D210E Dual-port E1/T1 card(2nd generation)";
        case PciDevice1B74::DEVICE_D230: return "D230 Dual-port E1/T1 card (2nd generation)";
        case PciDevice1B74::DEVICE_D410: return "D410/430 Quad-port E1/T1 card";
        case PciDevice1B74::DEVICE_D430: return "D410/430 Quad-port E1/T1 card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B74_PCIDEVICE1B74_H
