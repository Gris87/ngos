// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCISUBCLASS01_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCISUBCLASS01_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0101.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0105.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0106.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0107.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pciinterface0108.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass01: u8
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
    SUB_CLASS_80 = 0x80,
};



inline const char8* enumToString(PciSubClass01 class01) // TEST: NO
{
    // COMMON_LT((" | class01 = %u", class01)); // Commented to avoid bad looking logs



    switch (class01)
    {
        case PciSubClass01::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass01::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass01::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass01::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass01::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass01::SUB_CLASS_05: return "SUB_CLASS_05";
        case PciSubClass01::SUB_CLASS_06: return "SUB_CLASS_06";
        case PciSubClass01::SUB_CLASS_07: return "SUB_CLASS_07";
        case PciSubClass01::SUB_CLASS_08: return "SUB_CLASS_08";
        case PciSubClass01::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass01 class01) // TEST: NO
{
    // COMMON_LT((" | class01 = %u", class01)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class01, enumToString(class01));

    return res;
}



inline const char8* enumToHumanString(PciSubClass01 class01, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class01 = %u, interfaceId = %u", class01, interfaceId)); // Commented to avoid bad looking logs



    switch (class01)
    {
        case PciSubClass01::SUB_CLASS_00: return "SCSI storage controller";
        case PciSubClass01::SUB_CLASS_01: return enumToHumanString((PciInterface0101)interfaceId);
        case PciSubClass01::SUB_CLASS_02: return "Floppy disk controller";
        case PciSubClass01::SUB_CLASS_03: return "IPI bus controller";
        case PciSubClass01::SUB_CLASS_04: return "RAID bus controller";
        case PciSubClass01::SUB_CLASS_05: return enumToHumanString((PciInterface0105)interfaceId);
        case PciSubClass01::SUB_CLASS_06: return enumToHumanString((PciInterface0106)interfaceId);
        case PciSubClass01::SUB_CLASS_07: return enumToHumanString((PciInterface0107)interfaceId);
        case PciSubClass01::SUB_CLASS_08: return enumToHumanString((PciInterface0108)interfaceId);
        case PciSubClass01::SUB_CLASS_80: return "Mass storage controller";

        default: return "Mass storage controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCISUBCLASS01_H
