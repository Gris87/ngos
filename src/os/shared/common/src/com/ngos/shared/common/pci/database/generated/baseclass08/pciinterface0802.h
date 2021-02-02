// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0802_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0802_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0802: bad_uint8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02,
    INTERFACE_03 = 0x03
};



inline const char8* enumToString(PciInterface0802 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0802::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0802::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0802::INTERFACE_02: return "INTERFACE_02";
        case PciInterface0802::INTERFACE_03: return "INTERFACE_03";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0802 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0802 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0802::INTERFACE_00: return "Generic system peripheral - Timer - 8254";
        case PciInterface0802::INTERFACE_01: return "Generic system peripheral - Timer - ISA Timer";
        case PciInterface0802::INTERFACE_02: return "Generic system peripheral - Timer - EISA Timers";
        case PciInterface0802::INTERFACE_03: return "Generic system peripheral - Timer - HPET";

        default: return "Generic system peripheral - Timer";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0802_H
