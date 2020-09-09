// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS09_PCIINTERFACE0904_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS09_PCIINTERFACE0904_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0904: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_10 = 0x10
};



inline const char8* enumToString(PciInterface0904 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0904::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0904::INTERFACE_10: return "INTERFACE_10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0904 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0904 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0904::INTERFACE_00: return "Input device controller - Gameport controller - Generic";
        case PciInterface0904::INTERFACE_10: return "Input device controller - Gameport controller - Extended";

        default: return "Input device controller - Gameport controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS09_PCIINTERFACE0904_H
