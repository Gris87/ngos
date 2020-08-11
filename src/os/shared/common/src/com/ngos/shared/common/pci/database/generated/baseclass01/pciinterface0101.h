// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0101_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0101: u8
{
    INTERFACE_00 = 0x00,
    INTERFACE_05 = 0x05,
    INTERFACE_0A = 0x0A,
    INTERFACE_0F = 0x0F,
    INTERFACE_80 = 0x80,
    INTERFACE_85 = 0x85,
    INTERFACE_8A = 0x8A,
    INTERFACE_8F = 0x8F,
};



inline const char8* enumToString(PciInterface0101 interface0101) // TEST: NO
{
    // COMMON_LT((" | interface0101 = %u", interface0101)); // Commented to avoid bad looking logs



    switch (interface0101)
    {
        case PciInterface0101::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0101::INTERFACE_05: return "INTERFACE_05";
        case PciInterface0101::INTERFACE_0A: return "INTERFACE_0A";
        case PciInterface0101::INTERFACE_0F: return "INTERFACE_0F";
        case PciInterface0101::INTERFACE_80: return "INTERFACE_80";
        case PciInterface0101::INTERFACE_85: return "INTERFACE_85";
        case PciInterface0101::INTERFACE_8A: return "INTERFACE_8A";
        case PciInterface0101::INTERFACE_8F: return "INTERFACE_8F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0101 interface0101) // TEST: NO
{
    // COMMON_LT((" | interface0101 = %u", interface0101)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0101, enumToString(interface0101));

    return res;
}



inline const char8* enumToHumanString(PciInterface0101 interface0101) // TEST: NO
{
    // COMMON_LT((" | interface0101 = %u", interface0101)); // Commented to avoid bad looking logs



    switch (interface0101)
    {
        case PciInterface0101::INTERFACE_00: return "ISA Compatibility mode-only controller";
        case PciInterface0101::INTERFACE_05: return "PCI native mode-only controller";
        case PciInterface0101::INTERFACE_0A: return "ISA Compatibility mode controller, supports both channels switched to PCI native mode";
        case PciInterface0101::INTERFACE_0F: return "PCI native mode controller, supports both channels switched to ISA compatibility mode";
        case PciInterface0101::INTERFACE_80: return "ISA Compatibility mode-only controller, supports bus mastering";
        case PciInterface0101::INTERFACE_85: return "PCI native mode-only controller, supports bus mastering";
        case PciInterface0101::INTERFACE_8A: return "ISA Compatibility mode controller, supports both channels switched to PCI native mode, supports bus mastering";
        case PciInterface0101::INTERFACE_8F: return "PCI native mode controller, supports both channels switched to ISA compatibility mode, supports bus mastering";

        default: return "IDE interface";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0101_H
