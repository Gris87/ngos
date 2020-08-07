// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCIINTERFACE0001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCIINTERFACE0001_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0001: u8
{
    INTERFACE_00 = 0x00
};



inline const char8* enumToString(PciInterface0001 interface0001) // TEST: NO
{
    // COMMON_LT((" | interface0001 = %u", interface0001)); // Commented to avoid bad looking logs



    switch (interface0001)
    {
        case PciInterface0001::INTERFACE_00: return "INTERFACE_00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0001 interface0001) // TEST: NO
{
    // COMMON_LT((" | interface0001 = %u", interface0001)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0001, enumToString(interface0001));

    return res;
}



inline const char8* enumToHumanString(PciInterface0001 interface0001) // TEST: NO
{
    // COMMON_LT((" | interface0001 = %u", interface0001)); // Commented to avoid bad looking logs



    switch (interface0001)
    {
        case PciInterface0001::INTERFACE_00: return "VGA-compatible device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCIINTERFACE0001_H
