// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C07_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C07_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0C07: u8
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02,
};



inline const char8* enumToString(PciInterface0C07 interface0C07) // TEST: NO
{
    // COMMON_LT((" | interface0C07 = %u", interface0C07)); // Commented to avoid bad looking logs



    switch (interface0C07)
    {
        case PciInterface0C07::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0C07::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0C07::INTERFACE_02: return "INTERFACE_02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0C07 interface0C07) // TEST: NO
{
    // COMMON_LT((" | interface0C07 = %u", interface0C07)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0C07, enumToString(interface0C07));

    return res;
}



inline const char8* enumToHumanString(PciInterface0C07 interface0C07) // TEST: NO
{
    // COMMON_LT((" | interface0C07 = %u", interface0C07)); // Commented to avoid bad looking logs



    switch (interface0C07)
    {
        case PciInterface0C07::INTERFACE_00: return "SMIC";
        case PciInterface0C07::INTERFACE_01: return "KCS";
        case PciInterface0C07::INTERFACE_02: return "BT (Block Transfer)";

        default: return "IPMI Interface";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C07_H
