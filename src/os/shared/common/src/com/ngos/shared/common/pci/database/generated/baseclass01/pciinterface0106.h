// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0106_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0106_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0106: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02
};



inline const char8* enumToString(PciInterface0106 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0106::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0106::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0106::INTERFACE_02: return "INTERFACE_02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0106 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0106 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0106::INTERFACE_00: return "Mass storage controller - SATA controller - Vendor specific";
        case PciInterface0106::INTERFACE_01: return "Mass storage controller - SATA controller - AHCI 1.0";
        case PciInterface0106::INTERFACE_02: return "Mass storage controller - SATA controller - Serial Storage Bus";

        default: return "Mass storage controller - SATA controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0106_H
