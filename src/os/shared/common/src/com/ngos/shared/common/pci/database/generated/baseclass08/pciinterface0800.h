// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0800_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0800_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0800: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01,
    INTERFACE_02 = 0x02,
    INTERFACE_10 = 0x10,
    INTERFACE_20 = 0x20
};



inline const char8* enumToString(PciInterface0800 interface0800) // TEST: NO
{
    // COMMON_LT((" | interface0800 = %u", interface0800)); // Commented to avoid bad looking logs



    switch (interface0800)
    {
        case PciInterface0800::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0800::INTERFACE_01: return "INTERFACE_01";
        case PciInterface0800::INTERFACE_02: return "INTERFACE_02";
        case PciInterface0800::INTERFACE_10: return "INTERFACE_10";
        case PciInterface0800::INTERFACE_20: return "INTERFACE_20";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0800 interface0800) // TEST: NO
{
    // COMMON_LT((" | interface0800 = %u", interface0800)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0800, enumToString(interface0800));

    return res;
}



inline const char8* enumToHumanString(PciInterface0800 interface0800) // TEST: NO
{
    // COMMON_LT((" | interface0800 = %u", interface0800)); // Commented to avoid bad looking logs



    switch (interface0800)
    {
        case PciInterface0800::INTERFACE_00: return "Generic system peripheral - PIC - 8259";
        case PciInterface0800::INTERFACE_01: return "Generic system peripheral - PIC - ISA PIC";
        case PciInterface0800::INTERFACE_02: return "Generic system peripheral - PIC - EISA PIC";
        case PciInterface0800::INTERFACE_10: return "Generic system peripheral - PIC - IO-APIC";
        case PciInterface0800::INTERFACE_20: return "Generic system peripheral - PIC - IO(X)-APIC";

        default: return "Generic system peripheral - PIC";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0800_H
