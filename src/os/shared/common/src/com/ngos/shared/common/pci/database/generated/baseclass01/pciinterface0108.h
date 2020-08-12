// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0108_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0108_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0108: u8 // Ignore CppEnumVerifier
{
    NONE         = 0,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02
};



inline const char8* enumToString(PciInterface0108 interface0108) // TEST: NO
{
    // COMMON_LT((" | interface0108 = %u", interface0108)); // Commented to avoid bad looking logs



    switch (interface0108)
    {
        case PciInterface0108::NONE:         return "NONE";
        case PciInterface0108::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0108::INTERFACE_02: return "INTERFACE_02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0108 interface0108) // TEST: NO
{
    // COMMON_LT((" | interface0108 = %u", interface0108)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0108, enumToString(interface0108));

    return res;
}



inline const char8* enumToHumanString(PciInterface0108 interface0108) // TEST: NO
{
    // COMMON_LT((" | interface0108 = %u", interface0108)); // Commented to avoid bad looking logs



    switch (interface0108)
    {
        case PciInterface0108::INTERFACE_01: return "Mass storage controller - Non-Volatile memory controller - NVMHCI";
        case PciInterface0108::INTERFACE_02: return "Mass storage controller - Non-Volatile memory controller - NVM Express";

        default: return "Mass storage controller - Non-Volatile memory controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0108_H
