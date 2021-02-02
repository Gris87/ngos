// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCISUBCLASS08_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCISUBCLASS08_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0800.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0801.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0802.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0803.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pciinterface0899.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass08: bad_uint8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_04 = 0x04,
    SUB_CLASS_05 = 0x05,
    SUB_CLASS_06 = 0x06,
    SUB_CLASS_80 = 0x80,
    SUB_CLASS_99 = 0x99
};



inline const char8* enumToString(PciSubClass08 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass08::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass08::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass08::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass08::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass08::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass08::SUB_CLASS_05: return "SUB_CLASS_05";
        case PciSubClass08::SUB_CLASS_06: return "SUB_CLASS_06";
        case PciSubClass08::SUB_CLASS_80: return "SUB_CLASS_80";
        case PciSubClass08::SUB_CLASS_99: return "SUB_CLASS_99";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass08 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass08 subClass, bad_uint8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | subClass = %u, interfaceId = %u", subClass, interfaceId)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass08::SUB_CLASS_00: return enumToHumanString((PciInterface0800)interfaceId);
        case PciSubClass08::SUB_CLASS_01: return enumToHumanString((PciInterface0801)interfaceId);
        case PciSubClass08::SUB_CLASS_02: return enumToHumanString((PciInterface0802)interfaceId);
        case PciSubClass08::SUB_CLASS_03: return enumToHumanString((PciInterface0803)interfaceId);
        case PciSubClass08::SUB_CLASS_04: return "Generic system peripheral - PCI Hot-plug controller";
        case PciSubClass08::SUB_CLASS_05: return "Generic system peripheral - SD Host controller";
        case PciSubClass08::SUB_CLASS_06: return "Generic system peripheral - IOMMU";
        case PciSubClass08::SUB_CLASS_80: return "Generic system peripheral - System peripheral";
        case PciSubClass08::SUB_CLASS_99: return enumToHumanString((PciInterface0899)interfaceId);

        default: return "Generic system peripheral";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS08_PCISUBCLASS08_H
