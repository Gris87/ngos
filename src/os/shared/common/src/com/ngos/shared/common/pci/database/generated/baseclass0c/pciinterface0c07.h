// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C07_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C07_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0C07: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02
};



inline const char8* enumToString(PciInterface0C07 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0C07::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0C07::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0C07::INTERFACE_02: return "INTERFACE_02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0C07 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0C07 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0C07::INTERFACE_00: return "Serial bus controller - IPMI Interface - SMIC";
        case PciInterface0C07::INTERFACE_01: return "Serial bus controller - IPMI Interface - KCS";
        case PciInterface0C07::INTERFACE_02: return "Serial bus controller - IPMI Interface - BT (Block Transfer)";

        default: return "Serial bus controller - IPMI Interface";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C07_H
