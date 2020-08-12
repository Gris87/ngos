// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0703_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0703_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0703: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02,
    INTERFACE_03 = 0x03,
    INTERFACE_04 = 0x04
};



inline const char8* enumToString(PciInterface0703 interface0703) // TEST: NO
{
    // COMMON_LT((" | interface0703 = %u", interface0703)); // Commented to avoid bad looking logs



    switch (interface0703)
    {
        case PciInterface0703::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0703::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0703::INTERFACE_02: return "INTERFACE_02";
        case PciInterface0703::INTERFACE_03: return "INTERFACE_03";
        case PciInterface0703::INTERFACE_04: return "INTERFACE_04";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0703 interface0703) // TEST: NO
{
    // COMMON_LT((" | interface0703 = %u", interface0703)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0703, enumToString(interface0703));

    return res;
}



inline const char8* enumToHumanString(PciInterface0703 interface0703) // TEST: NO
{
    // COMMON_LT((" | interface0703 = %u", interface0703)); // Commented to avoid bad looking logs



    switch (interface0703)
    {
        case PciInterface0703::INTERFACE_00: return "Communication controller - Modem - Generic";
        case PciInterface0703::INTERFACE_01: return "Communication controller - Modem - Hayes/16450";
        case PciInterface0703::INTERFACE_02: return "Communication controller - Modem - Hayes/16550";
        case PciInterface0703::INTERFACE_03: return "Communication controller - Modem - Hayes/16650";
        case PciInterface0703::INTERFACE_04: return "Communication controller - Modem - Hayes/16750";

        default: return "Communication controller - Modem";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0703_H
