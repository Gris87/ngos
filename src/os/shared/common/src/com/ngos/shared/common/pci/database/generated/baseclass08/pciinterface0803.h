// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0803_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0803_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0803: u8 // Ignore CppEnumVerifier
{
    INTERFACE_00 = 0x00,
    INTERFACE_01 = 0x01
};



inline const char8* enumToString(PciInterface0803 interface0803) // TEST: NO
{
    // COMMON_LT((" | interface0803 = %u", interface0803)); // Commented to avoid bad looking logs



    switch (interface0803)
    {
        case PciInterface0803::INTERFACE_00: return "INTERFACE_00";
        case PciInterface0803::INTERFACE_01: return "INTERFACE_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0803 interface0803) // TEST: NO
{
    // COMMON_LT((" | interface0803 = %u", interface0803)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0803, enumToString(interface0803));

    return res;
}



inline const char8* enumToHumanString(PciInterface0803 interface0803) // TEST: NO
{
    // COMMON_LT((" | interface0803 = %u", interface0803)); // Commented to avoid bad looking logs



    switch (interface0803)
    {
        case PciInterface0803::INTERFACE_00: return "Generic system peripheral - RTC - Generic";
        case PciInterface0803::INTERFACE_01: return "Generic system peripheral - RTC - ISA RTC";

        default: return "Generic system peripheral - RTC";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCIINTERFACE0803_H
