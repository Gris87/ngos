// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS02_PCISUBCLASS02_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS02_PCISUBCLASS02_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass02: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_04 = 0x04,
    SUB_CLASS_05 = 0x05,
    SUB_CLASS_06 = 0x06,
    SUB_CLASS_07 = 0x07,
    SUB_CLASS_08 = 0x08,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass02 class02) // TEST: NO
{
    // COMMON_LT((" | class02 = %u", class02)); // Commented to avoid bad looking logs



    switch (class02)
    {
        case PciSubClass02::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass02::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass02::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass02::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass02::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass02::SUB_CLASS_05: return "SUB_CLASS_05";
        case PciSubClass02::SUB_CLASS_06: return "SUB_CLASS_06";
        case PciSubClass02::SUB_CLASS_07: return "SUB_CLASS_07";
        case PciSubClass02::SUB_CLASS_08: return "SUB_CLASS_08";
        case PciSubClass02::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass02 class02) // TEST: NO
{
    // COMMON_LT((" | class02 = %u", class02)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class02, enumToString(class02));

    return res;
}



inline const char8* enumToHumanString(PciSubClass02 class02) // TEST: NO
{
    // COMMON_LT((" | class02 = %u", class02)); // Commented to avoid bad looking logs



    switch (class02)
    {
        case PciSubClass02::SUB_CLASS_00: return "Network controller - Ethernet controller";
        case PciSubClass02::SUB_CLASS_01: return "Network controller - Token ring network controller";
        case PciSubClass02::SUB_CLASS_02: return "Network controller - FDDI network controller";
        case PciSubClass02::SUB_CLASS_03: return "Network controller - ATM network controller";
        case PciSubClass02::SUB_CLASS_04: return "Network controller - ISDN controller";
        case PciSubClass02::SUB_CLASS_05: return "Network controller - WorldFip controller";
        case PciSubClass02::SUB_CLASS_06: return "Network controller - PICMG controller";
        case PciSubClass02::SUB_CLASS_07: return "Network controller - Infiniband controller";
        case PciSubClass02::SUB_CLASS_08: return "Network controller - Fabric controller";
        case PciSubClass02::SUB_CLASS_80: return "Network controller - Network controller";

        default: return "Network controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS02_PCISUBCLASS02_H
