// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0899_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0899_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0899: u8 // Ignore CppEnumVerifier
{
    NONE         = 0,
    INTERFACE_01 = 0x01
};



inline const char8* enumToString(PciInterface0899 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0899::NONE:         return "NONE";
        case PciInterface0899::INTERFACE_01: return "INTERFACE_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0899 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0899 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0899::INTERFACE_01: return "Generic system peripheral - Timing Card - TAP Timing Card";

        default: return "Generic system peripheral - Timing Card";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0899_H
