// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0701_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0701_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0701: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02,
    INTERFACE_03 = 0x03,
    INTERFACE_FE = 0xFE
};



inline const char8* enumToString(PciInterface0701 interface0701) // TEST: NO
{
    // COMMON_LT((" | interface0701 = %u", interface0701)); // Commented to avoid bad looking logs



    switch (interface0701)
    {
        case PciInterface0701::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0701::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0701::INTERFACE_02: return "INTERFACE_02";
        case PciInterface0701::INTERFACE_03: return "INTERFACE_03";
        case PciInterface0701::INTERFACE_FE: return "INTERFACE_FE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0701 interface0701) // TEST: NO
{
    // COMMON_LT((" | interface0701 = %u", interface0701)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0701, enumToString(interface0701));

    return res;
}



inline const char8* enumToHumanString(PciInterface0701 interface0701) // TEST: NO
{
    // COMMON_LT((" | interface0701 = %u", interface0701)); // Commented to avoid bad looking logs



    switch (interface0701)
    {
        case PciInterface0701::INTERFACE_00: return "Communication controller - Parallel controller - SPP";
        case PciInterface0701::INTERFACE_01: return "Communication controller - Parallel controller - BiDir";
        case PciInterface0701::INTERFACE_02: return "Communication controller - Parallel controller - ECP";
        case PciInterface0701::INTERFACE_03: return "Communication controller - Parallel controller - IEEE1284";
        case PciInterface0701::INTERFACE_FE: return "Communication controller - Parallel controller - IEEE1284 Target";

        default: return "Communication controller - Parallel controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCIINTERFACE0701_H
