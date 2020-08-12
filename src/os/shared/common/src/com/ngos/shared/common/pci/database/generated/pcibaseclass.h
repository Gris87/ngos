// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass00/pcisubclass00.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pcisubclass01.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass02/pcisubclass02.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass03/pcisubclass03.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass04/pcisubclass04.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass05/pcisubclass05.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pcisubclass06.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass07/pcisubclass07.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass08/pcisubclass08.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass09/pcisubclass09.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0a/pcisubclass0a.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0b/pcisubclass0b.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0c/pcisubclass0c.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0d/pcisubclass0d.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0e/pcisubclass0e.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass0f/pcisubclass0f.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass10/pcisubclass10.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass11/pcisubclass11.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass12/pcisubclass12.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciBaseClass: u8
{
    BASE_CLASS_00 = 0x00,
    BASE_CLASS_01 = 0x01,
    BASE_CLASS_02 = 0x02,
    BASE_CLASS_03 = 0x03,
    BASE_CLASS_04 = 0x04,
    BASE_CLASS_05 = 0x05,
    BASE_CLASS_06 = 0x06,
    BASE_CLASS_07 = 0x07,
    BASE_CLASS_08 = 0x08,
    BASE_CLASS_09 = 0x09,
    BASE_CLASS_0A = 0x0A,
    BASE_CLASS_0B = 0x0B,
    BASE_CLASS_0C = 0x0C,
    BASE_CLASS_0D = 0x0D,
    BASE_CLASS_0E = 0x0E,
    BASE_CLASS_0F = 0x0F,
    BASE_CLASS_10 = 0x10,
    BASE_CLASS_11 = 0x11,
    BASE_CLASS_12 = 0x12,
    BASE_CLASS_13 = 0x13,
    BASE_CLASS_40 = 0x40,
    BASE_CLASS_FF = 0xFF
};



inline const char8* enumToString(PciBaseClass baseClass) // TEST: NO
{
    // COMMON_LT((" | baseClass = %u", baseClass)); // Commented to avoid bad looking logs



    switch (baseClass)
    {
        case PciBaseClass::BASE_CLASS_00: return "BASE_CLASS_00";
        case PciBaseClass::BASE_CLASS_01: return "BASE_CLASS_01";
        case PciBaseClass::BASE_CLASS_02: return "BASE_CLASS_02";
        case PciBaseClass::BASE_CLASS_03: return "BASE_CLASS_03";
        case PciBaseClass::BASE_CLASS_04: return "BASE_CLASS_04";
        case PciBaseClass::BASE_CLASS_05: return "BASE_CLASS_05";
        case PciBaseClass::BASE_CLASS_06: return "BASE_CLASS_06";
        case PciBaseClass::BASE_CLASS_07: return "BASE_CLASS_07";
        case PciBaseClass::BASE_CLASS_08: return "BASE_CLASS_08";
        case PciBaseClass::BASE_CLASS_09: return "BASE_CLASS_09";
        case PciBaseClass::BASE_CLASS_0A: return "BASE_CLASS_0A";
        case PciBaseClass::BASE_CLASS_0B: return "BASE_CLASS_0B";
        case PciBaseClass::BASE_CLASS_0C: return "BASE_CLASS_0C";
        case PciBaseClass::BASE_CLASS_0D: return "BASE_CLASS_0D";
        case PciBaseClass::BASE_CLASS_0E: return "BASE_CLASS_0E";
        case PciBaseClass::BASE_CLASS_0F: return "BASE_CLASS_0F";
        case PciBaseClass::BASE_CLASS_10: return "BASE_CLASS_10";
        case PciBaseClass::BASE_CLASS_11: return "BASE_CLASS_11";
        case PciBaseClass::BASE_CLASS_12: return "BASE_CLASS_12";
        case PciBaseClass::BASE_CLASS_13: return "BASE_CLASS_13";
        case PciBaseClass::BASE_CLASS_40: return "BASE_CLASS_40";
        case PciBaseClass::BASE_CLASS_FF: return "BASE_CLASS_FF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciBaseClass baseClass) // TEST: NO
{
    // COMMON_LT((" | baseClass = %u", baseClass)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%02X (%s)", (u8)baseClass, enumToString(baseClass));

    return res;
}



inline const char8* enumToHumanString(PciBaseClass baseClass, u8 subClassId, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | baseClass = %u, subClassId = %u, interfaceId = %u", baseClass, subClassId, interfaceId)); // Commented to avoid bad looking logs



    switch (baseClass)
    {
        case PciBaseClass::BASE_CLASS_00: return enumToHumanString((PciSubClass00)subClassId);
        case PciBaseClass::BASE_CLASS_01: return enumToHumanString((PciSubClass01)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_02: return enumToHumanString((PciSubClass02)subClassId);
        case PciBaseClass::BASE_CLASS_03: return enumToHumanString((PciSubClass03)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_04: return enumToHumanString((PciSubClass04)subClassId);
        case PciBaseClass::BASE_CLASS_05: return enumToHumanString((PciSubClass05)subClassId);
        case PciBaseClass::BASE_CLASS_06: return enumToHumanString((PciSubClass06)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_07: return enumToHumanString((PciSubClass07)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_08: return enumToHumanString((PciSubClass08)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_09: return enumToHumanString((PciSubClass09)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_0A: return enumToHumanString((PciSubClass0A)subClassId);
        case PciBaseClass::BASE_CLASS_0B: return enumToHumanString((PciSubClass0B)subClassId);
        case PciBaseClass::BASE_CLASS_0C: return enumToHumanString((PciSubClass0C)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_0D: return enumToHumanString((PciSubClass0D)subClassId);
        case PciBaseClass::BASE_CLASS_0E: return enumToHumanString((PciSubClass0E)subClassId);
        case PciBaseClass::BASE_CLASS_0F: return enumToHumanString((PciSubClass0F)subClassId);
        case PciBaseClass::BASE_CLASS_10: return enumToHumanString((PciSubClass10)subClassId);
        case PciBaseClass::BASE_CLASS_11: return enumToHumanString((PciSubClass11)subClassId);
        case PciBaseClass::BASE_CLASS_12: return enumToHumanString((PciSubClass12)subClassId);
        case PciBaseClass::BASE_CLASS_13: return "Non-Essential Instrumentation";
        case PciBaseClass::BASE_CLASS_40: return "Coprocessor";
        case PciBaseClass::BASE_CLASS_FF: return "Unassigned class";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H
