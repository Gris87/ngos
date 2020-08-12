// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCIDEVICE1069_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCIDEVICE1069_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1069: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0010 = 0x0010,
    DEVICE_0020 = 0x0020,
    DEVICE_0050 = 0x0050,
    DEVICE_B166 = 0xB166,
    DEVICE_BA55 = 0xBA55,
    DEVICE_BA56 = 0xBA56,
    DEVICE_BA57 = 0xBA57
};



inline const char8* enumToString(PciDevice1069 device1069) // TEST: NO
{
    // COMMON_LT((" | device1069 = %u", device1069)); // Commented to avoid bad looking logs



    switch (device1069)
    {
        case PciDevice1069::NONE:        return "NONE";
        case PciDevice1069::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1069::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1069::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1069::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1069::DEVICE_0050: return "DEVICE_0050";
        case PciDevice1069::DEVICE_B166: return "DEVICE_B166";
        case PciDevice1069::DEVICE_BA55: return "DEVICE_BA55";
        case PciDevice1069::DEVICE_BA56: return "DEVICE_BA56";
        case PciDevice1069::DEVICE_BA57: return "DEVICE_BA57";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1069 device1069) // TEST: NO
{
    // COMMON_LT((" | device1069 = %u", device1069)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1069, enumToString(device1069));

    return res;
}



inline const char8* enumToHumanString(PciDevice1069 device1069) // TEST: NO
{
    // COMMON_LT((" | device1069 = %u", device1069)); // Commented to avoid bad looking logs



    switch (device1069)
    {
        case PciDevice1069::DEVICE_0001: return "DAC960P";
        case PciDevice1069::DEVICE_0002: return "DAC960PD";
        case PciDevice1069::DEVICE_0010: return "DAC960PG";
        case PciDevice1069::DEVICE_0020: return "DAC960LA";
        case PciDevice1069::DEVICE_0050: return "AcceleRAID 352/170/160 support Device";
        case PciDevice1069::DEVICE_B166: return "AcceleRAID 600/500/400/Sapphire support Device";
        case PciDevice1069::DEVICE_BA55: return "eXtremeRAID 1100 support Device";
        case PciDevice1069::DEVICE_BA56: return "eXtremeRAID 2000/3000 support Device";
        case PciDevice1069::DEVICE_BA57: return "eXtremeRAID 4000/5000 support Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCIDEVICE1069_H
