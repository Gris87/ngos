// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0180_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0180_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0180: u8
{
    INTERFACE_00 = 0x00
};



inline const char8* enumToString(PciInterface0180 interface0180) // TEST: NO
{
    // COMMON_LT((" | interface0180 = %u", interface0180)); // Commented to avoid bad looking logs



    switch (interface0180)
    {
        case PciInterface0180::INTERFACE_00: return "INTERFACE_00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0180 interface0180) // TEST: NO
{
    // COMMON_LT((" | interface0180 = %u", interface0180)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0180, enumToString(interface0180));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0180_H
