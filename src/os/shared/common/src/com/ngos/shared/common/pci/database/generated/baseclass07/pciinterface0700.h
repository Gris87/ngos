// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0700_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0700_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0700: u8
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02,
    INTERFACE_03 = 0x03,
    INTERFACE_04 = 0x04,
    INTERFACE_05 = 0x05,
    INTERFACE_06 = 0x06,
};



inline const char8* enumToString(PciInterface0700 interface0700) // TEST: NO
{
    // COMMON_LT((" | interface0700 = %u", interface0700)); // Commented to avoid bad looking logs



    switch (interface0700)
    {
        case PciInterface0700::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0700::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0700::INTERFACE_02: return "INTERFACE_02";
        case PciInterface0700::INTERFACE_03: return "INTERFACE_03";
        case PciInterface0700::INTERFACE_04: return "INTERFACE_04";
        case PciInterface0700::INTERFACE_05: return "INTERFACE_05";
        case PciInterface0700::INTERFACE_06: return "INTERFACE_06";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0700 interface0700) // TEST: NO
{
    // COMMON_LT((" | interface0700 = %u", interface0700)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0700, enumToString(interface0700));

    return res;
}



inline const char8* enumToHumanString(PciInterface0700 interface0700) // TEST: NO
{
    // COMMON_LT((" | interface0700 = %u", interface0700)); // Commented to avoid bad looking logs



    switch (interface0700)
    {
        case PciInterface0700::INTERFACE_00: return "8250";
        case PciInterface0700::INTERFACE_01: return "16450";
        case PciInterface0700::INTERFACE_02: return "16550";
        case PciInterface0700::INTERFACE_03: return "16650";
        case PciInterface0700::INTERFACE_04: return "16750";
        case PciInterface0700::INTERFACE_05: return "16850";
        case PciInterface0700::INTERFACE_06: return "16950";

        default: return "Serial controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0700_H
