// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C00_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C00_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0C00: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_10 = 0x10
};



inline const char8* enumToString(PciInterface0C00 interface0C00) // TEST: NO
{
    // COMMON_LT((" | interface0C00 = %u", interface0C00)); // Commented to avoid bad looking logs



    switch (interface0C00)
    {
        case PciInterface0C00::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0C00::INTERFACE_10: return "INTERFACE_10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0C00 interface0C00) // TEST: NO
{
    // COMMON_LT((" | interface0C00 = %u", interface0C00)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0C00, enumToString(interface0C00));

    return res;
}



inline const char8* enumToHumanString(PciInterface0C00 interface0C00) // TEST: NO
{
    // COMMON_LT((" | interface0C00 = %u", interface0C00)); // Commented to avoid bad looking logs



    switch (interface0C00)
    {
        case PciInterface0C00::INTERFACE_00: return "Serial bus controller - FireWire (IEEE 1394) - Generic";
        case PciInterface0C00::INTERFACE_10: return "Serial bus controller - FireWire (IEEE 1394) - OHCI";

        default: return "Serial bus controller - FireWire (IEEE 1394)";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C00_H
