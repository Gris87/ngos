// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0801_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0801_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0801: bad_uint8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02
};



inline const char8* enumToString(PciInterface0801 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0801::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0801::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0801::INTERFACE_02: return "INTERFACE_02";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0801 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)interface, enumToString(interface));

    return res;
}



inline const char8* enumToHumanString(PciInterface0801 interface) // TEST: NO
{
    // COMMON_LT((" | interface = %u", interface)); // Commented to avoid bad looking logs



    switch (interface)
    {
        case PciInterface0801::INTERFACE_00: return "Generic system peripheral - DMA controller - 8237";
        case PciInterface0801::INTERFACE_01: return "Generic system peripheral - DMA controller - ISA DMA";
        case PciInterface0801::INTERFACE_02: return "Generic system peripheral - DMA controller - EISA DMA";

        default: return "Generic system peripheral - DMA controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0801_H
