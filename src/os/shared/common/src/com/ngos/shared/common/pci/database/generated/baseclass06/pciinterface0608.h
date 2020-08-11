// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0608_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0608_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0608: u8
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
};



inline const char8* enumToString(PciInterface0608 interface0608) // TEST: NO
{
    // COMMON_LT((" | interface0608 = %u", interface0608)); // Commented to avoid bad looking logs



    switch (interface0608)
    {
        case PciInterface0608::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0608::INTERFACE_01: return "INTERFACE_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0608 interface0608) // TEST: NO
{
    // COMMON_LT((" | interface0608 = %u", interface0608)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0608, enumToString(interface0608));

    return res;
}



inline const char8* enumToHumanString(PciInterface0608 interface0608) // TEST: NO
{
    // COMMON_LT((" | interface0608 = %u", interface0608)); // Commented to avoid bad looking logs



    switch (interface0608)
    {
        case PciInterface0608::INTERFACE_00: return "Transparent mode";
        case PciInterface0608::INTERFACE_01: return "Endpoint mode";

        default: return "RACEway bridge";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0608_H
