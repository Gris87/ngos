// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0105_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0105_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0105: u8 // Ignore CppEnumVerifier
{
    NONE         = 0,
    INTERFACE_20 = 0x20,
    INTERFACE_30 = 0x30
};



inline const char8* enumToString(PciInterface0105 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0105::NONE:         return "NONE";
        case PciInterface0105::INTERFACE_20: return "INTERFACE_20";
        case PciInterface0105::INTERFACE_30: return "INTERFACE_30";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0105 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0105 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0105::INTERFACE_20: return "Mass storage controller - ATA controller - ADMA single stepping";
        case PciInterface0105::INTERFACE_30: return "Mass storage controller - ATA controller - ADMA continuous operation";

        default: return "Mass storage controller - ATA controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0105_H
