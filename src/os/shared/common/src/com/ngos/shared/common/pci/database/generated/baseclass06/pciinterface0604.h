// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0604_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0604_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0604: bad_uint8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01
};



inline const char8* enumToString(PciInterface0604 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0604::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0604::INTERFACE_01: return "INTERFACE_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0604 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0604 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0604::INTERFACE_00: return "Bridge - PCI bridge - Normal decode";
        case PciInterface0604::INTERFACE_01: return "Bridge - PCI bridge - Subtractive decode";

        default: return "Bridge - PCI bridge";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCIINTERFACE0604_H
