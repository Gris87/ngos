// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0103_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0103_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0103: u8
{
    INTERFACE_00 = 0x00
};



inline const char8* enumToString(PciInterface0103 interface0103) // TEST: NO
{
    // COMMON_LT((" | interface0103 = %u", interface0103)); // Commented to avoid bad looking logs



    switch (interface0103)
    {
        case PciInterface0103::INTERFACE_00: return "INTERFACE_00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0103 interface0103) // TEST: NO
{
    // COMMON_LT((" | interface0103 = %u", interface0103)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0103, enumToString(interface0103));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0103_H
