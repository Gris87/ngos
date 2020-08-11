// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCISUBCLASS08_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCISUBCLASS08_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0800.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0801.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0802.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0803.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass08: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_04 = 0x04,
    SUB_CLASS_05 = 0x05,
    SUB_CLASS_06 = 0x06,
    SUB_CLASS_80 = 0x80,
};



inline const char8* enumToString(PciSubClass08 class08) // TEST: NO
{
    // COMMON_LT((" | class08 = %u", class08)); // Commented to avoid bad looking logs



    switch (class08)
    {
        case PciSubClass08::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass08::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass08::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass08::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass08::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass08::SUB_CLASS_05: return "SUB_CLASS_05";
        case PciSubClass08::SUB_CLASS_06: return "SUB_CLASS_06";
        case PciSubClass08::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass08 class08) // TEST: NO
{
    // COMMON_LT((" | class08 = %u", class08)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class08, enumToString(class08));

    return res;
}



inline const char8* enumToHumanString(PciSubClass08 class08, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class08 = %u, interfaceId = %u", class08, interfaceId)); // Commented to avoid bad looking logs



    switch (class08)
    {
        case PciSubClass08::SUB_CLASS_00: return enumToHumanString((PciInterface0800)interfaceId);
        case PciSubClass08::SUB_CLASS_01: return enumToHumanString((PciInterface0801)interfaceId);
        case PciSubClass08::SUB_CLASS_02: return enumToHumanString((PciInterface0802)interfaceId);
        case PciSubClass08::SUB_CLASS_03: return enumToHumanString((PciInterface0803)interfaceId);
        case PciSubClass08::SUB_CLASS_04: return "PCI Hot-plug controller";
        case PciSubClass08::SUB_CLASS_05: return "SD Host controller";
        case PciSubClass08::SUB_CLASS_06: return "IOMMU";
        case PciSubClass08::SUB_CLASS_80: return "System peripheral";

        default: return "Generic system peripheral";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCISUBCLASS08_H
