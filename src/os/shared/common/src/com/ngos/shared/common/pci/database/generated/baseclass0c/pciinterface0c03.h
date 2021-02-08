// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0C03: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_10 = 0x10,
    INTERFACE_20 = 0x20,
    INTERFACE_30 = 0x30,
    INTERFACE_40 = 0x40,
    INTERFACE_80 = 0x80,
    INTERFACE_FE = 0xFE
};



inline const char8* enumToString(PciInterface0C03 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0C03::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0C03::INTERFACE_10: return "INTERFACE_10";
        case PciInterface0C03::INTERFACE_20: return "INTERFACE_20";
        case PciInterface0C03::INTERFACE_30: return "INTERFACE_30";
        case PciInterface0C03::INTERFACE_40: return "INTERFACE_40";
        case PciInterface0C03::INTERFACE_80: return "INTERFACE_80";
        case PciInterface0C03::INTERFACE_FE: return "INTERFACE_FE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0C03 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0C03 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0C03::INTERFACE_00: return "Serial bus controller - USB controller - UHCI";
        case PciInterface0C03::INTERFACE_10: return "Serial bus controller - USB controller - OHCI";
        case PciInterface0C03::INTERFACE_20: return "Serial bus controller - USB controller - EHCI";
        case PciInterface0C03::INTERFACE_30: return "Serial bus controller - USB controller - XHCI";
        case PciInterface0C03::INTERFACE_40: return "Serial bus controller - USB controller - USB4 Host Interface";
        case PciInterface0C03::INTERFACE_80: return "Serial bus controller - USB controller - Unspecified";
        case PciInterface0C03::INTERFACE_FE: return "Serial bus controller - USB controller - USB Device";

        default: return "Serial bus controller - USB controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCIINTERFACE0C03_H
