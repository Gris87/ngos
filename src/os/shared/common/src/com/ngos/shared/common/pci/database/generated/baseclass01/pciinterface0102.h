// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0102_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0102_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0102: u8
{
    INTERFACE_00 = 0x00
};



inline const char8* enumToString(PciInterface0102 interface0102) // TEST: NO
{
    // COMMON_LT((" | interface0102 = %u", interface0102)); // Commented to avoid bad looking logs



    switch (interface0102)
    {
        case PciInterface0102::INTERFACE_00: return "INTERFACE_00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0102 interface0102) // TEST: NO
{
    // COMMON_LT((" | interface0102 = %u", interface0102)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0102, enumToString(interface0102));

    return res;
}



inline const char8* enumToHumanString(PciInterface0102 interface0102) // TEST: NO
{
    // COMMON_LT((" | interface0102 = %u", interface0102)); // Commented to avoid bad looking logs



    switch (interface0102)
    {
        case PciInterface0102::INTERFACE_00: return "Floppy disk controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0102_H
