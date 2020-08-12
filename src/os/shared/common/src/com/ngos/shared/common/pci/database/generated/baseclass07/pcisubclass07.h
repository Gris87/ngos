// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCISUBCLASS07_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCISUBCLASS07_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pciinterface0700.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pciinterface0701.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pciinterface0703.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass07: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_04 = 0x04,
    SUB_CLASS_05 = 0x05,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass07 class07) // TEST: NO
{
    // COMMON_LT((" | class07 = %u", class07)); // Commented to avoid bad looking logs



    switch (class07)
    {
        case PciSubClass07::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass07::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass07::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass07::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass07::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass07::SUB_CLASS_05: return "SUB_CLASS_05";
        case PciSubClass07::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass07 class07) // TEST: NO
{
    // COMMON_LT((" | class07 = %u", class07)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class07, enumToString(class07));

    return res;
}



inline const char8* enumToHumanString(PciSubClass07 class07, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class07 = %u, interfaceId = %u", class07, interfaceId)); // Commented to avoid bad looking logs



    switch (class07)
    {
        case PciSubClass07::SUB_CLASS_00: return enumToHumanString((PciInterface0700)interfaceId);
        case PciSubClass07::SUB_CLASS_01: return enumToHumanString((PciInterface0701)interfaceId);
        case PciSubClass07::SUB_CLASS_02: return "Communication controller - Multiport serial controller";
        case PciSubClass07::SUB_CLASS_03: return enumToHumanString((PciInterface0703)interfaceId);
        case PciSubClass07::SUB_CLASS_04: return "Communication controller - GPIB controller";
        case PciSubClass07::SUB_CLASS_05: return "Communication controller - Smard Card controller";
        case PciSubClass07::SUB_CLASS_80: return "Communication controller - Communication controller";

        default: return "Communication controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS07_PCISUBCLASS07_H
