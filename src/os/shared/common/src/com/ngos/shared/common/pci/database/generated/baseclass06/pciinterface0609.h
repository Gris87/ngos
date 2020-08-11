// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0609_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0609_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0609: u8
{
    NONE         = 0,
    INTERFACE_40 = 0x40,
    INTERFACE_80 = 0x80,
};



inline const char8* enumToString(PciInterface0609 interface0609) // TEST: NO
{
    // COMMON_LT((" | interface0609 = %u", interface0609)); // Commented to avoid bad looking logs



    switch (interface0609)
    {
        case PciInterface0609::NONE:         return "NONE";
        case PciInterface0609::INTERFACE_40: return "INTERFACE_40";
        case PciInterface0609::INTERFACE_80: return "INTERFACE_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0609 interface0609) // TEST: NO
{
    // COMMON_LT((" | interface0609 = %u", interface0609)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0609, enumToString(interface0609));

    return res;
}



inline const char8* enumToHumanString(PciInterface0609 interface0609) // TEST: NO
{
    // COMMON_LT((" | interface0609 = %u", interface0609)); // Commented to avoid bad looking logs



    switch (interface0609)
    {
        case PciInterface0609::INTERFACE_40: return "Primary bus towards host CPU";
        case PciInterface0609::INTERFACE_80: return "Secondary bus towards host CPU";

        default: return "Semi-transparent PCI-to-PCI bridge";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0609_H
