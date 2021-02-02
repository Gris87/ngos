// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0101: bad_uint8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_05 = 0x05,
    INTERFACE_0A = 0x0A,
    INTERFACE_0F = 0x0F,
    INTERFACE_80 = 0x80,
    INTERFACE_85 = 0x85,
    INTERFACE_8A = 0x8A,
    INTERFACE_8F = 0x8F
};



inline const char8* enumToString(PciInterface0101 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
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



inline const char8* enumToFullString(PciInterface0101 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0101 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0101::INTERFACE_00: return "Mass storage controller - IDE interface - ISA Compatibility mode-only controller";
        case PciInterface0101::INTERFACE_05: return "Mass storage controller - IDE interface - PCI native mode-only controller";
        case PciInterface0101::INTERFACE_0A: return "Mass storage controller - IDE interface - ISA Compatibility mode controller, supports both channels switched to PCI native mode";
        case PciInterface0101::INTERFACE_0F: return "Mass storage controller - IDE interface - PCI native mode controller, supports both channels switched to ISA compatibility mode";
        case PciInterface0101::INTERFACE_80: return "Mass storage controller - IDE interface - ISA Compatibility mode-only controller, supports bus mastering";
        case PciInterface0101::INTERFACE_85: return "Mass storage controller - IDE interface - PCI native mode-only controller, supports bus mastering";
        case PciInterface0101::INTERFACE_8A: return "Mass storage controller - IDE interface - ISA Compatibility mode controller, supports both channels switched to PCI native mode, supports bus mastering";
        case PciInterface0101::INTERFACE_8F: return "Mass storage controller - IDE interface - PCI native mode controller, supports both channels switched to ISA compatibility mode, supports bus mastering";

        default: return "Mass storage controller - IDE interface";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0101_H
