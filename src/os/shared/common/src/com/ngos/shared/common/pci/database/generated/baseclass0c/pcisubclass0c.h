// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCISUBCLASS0C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCISUBCLASS0C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pciinterface0c00.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pciinterface0c03.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pciinterface0c07.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass0C: u8 // Ignore CppEnumVerifier
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
    SUB_CLASS_09 = 0x09,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass0C subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass0C::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass0C::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass0C::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass0C::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass0C::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass0C::SUB_CLASS_05: return "SUB_CLASS_05";
        case PciSubClass0C::SUB_CLASS_06: return "SUB_CLASS_06";
        case PciSubClass0C::SUB_CLASS_07: return "SUB_CLASS_07";
        case PciSubClass0C::SUB_CLASS_08: return "SUB_CLASS_08";
        case PciSubClass0C::SUB_CLASS_09: return "SUB_CLASS_09";
        case PciSubClass0C::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass0C subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass0C subClass, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | subClass = %u, interfaceId = %u", subClass, interfaceId)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass0C::SUB_CLASS_00: return enumToHumanString((PciInterface0C00)interfaceId);
        case PciSubClass0C::SUB_CLASS_01: return "Serial bus controller - ACCESS Bus";
        case PciSubClass0C::SUB_CLASS_02: return "Serial bus controller - SSA";
        case PciSubClass0C::SUB_CLASS_03: return enumToHumanString((PciInterface0C03)interfaceId);
        case PciSubClass0C::SUB_CLASS_04: return "Serial bus controller - Fibre Channel";
        case PciSubClass0C::SUB_CLASS_05: return "Serial bus controller - SMBus";
        case PciSubClass0C::SUB_CLASS_06: return "Serial bus controller - InfiniBand";
        case PciSubClass0C::SUB_CLASS_07: return enumToHumanString((PciInterface0C07)interfaceId);
        case PciSubClass0C::SUB_CLASS_08: return "Serial bus controller - SERCOS interface";
        case PciSubClass0C::SUB_CLASS_09: return "Serial bus controller - CANBUS";
        case PciSubClass0C::SUB_CLASS_80: return "Serial bus controller - Serial bus controller";

        default: return "Serial bus controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0C_PCISUBCLASS0C_H
