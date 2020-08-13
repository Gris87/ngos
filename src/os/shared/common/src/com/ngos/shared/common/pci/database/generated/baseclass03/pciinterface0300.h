// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS03_PCIINTERFACE0300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS03_PCIINTERFACE0300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0300: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01
};



inline const char8* enumToString(PciInterface0300 interface0300) // TEST: NO
{
    // COMMON_LT((" | interface0300 = %u", interface0300)); // Commented to avoid bad looking logs



    switch (interface0300)
    {
        case PciInterface0300::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0300::INTERFACE_01: return "INTERFACE_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0300 interface0300) // TEST: NO
{
    // COMMON_LT((" | interface0300 = %u", interface0300)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0300, enumToString(interface0300));

    return res;
}



inline const char8* enumToHumanString(PciInterface0300 interface0300) // TEST: NO
{
    // COMMON_LT((" | interface0300 = %u", interface0300)); // Commented to avoid bad looking logs



    switch (interface0300)
    {
        case PciInterface0300::INTERFACE_00: return "Display controller - VGA compatible controller - VGA controller";
        case PciInterface0300::INTERFACE_01: return "Display controller - VGA compatible controller - 8514 controller";

        default: return "Display controller - VGA compatible controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS03_PCIINTERFACE0300_H
