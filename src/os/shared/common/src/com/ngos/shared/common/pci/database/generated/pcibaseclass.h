// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass00/pcisubclass00.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass01/pcisubclass01.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciBaseClass: u8
{
    BASE_CLASS_00 = 0x00,
    BASE_CLASS_01 = 0x01
};



inline const char8* enumToString(PciBaseClass baseClass) // TEST: NO
{
    // COMMON_LT((" | baseClass = %u", baseClass)); // Commented to avoid bad looking logs



    switch (baseClass)
    {
        case PciBaseClass::BASE_CLASS_00: return "BASE_CLASS_00";
        case PciBaseClass::BASE_CLASS_01: return "BASE_CLASS_01";

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
        case PciBaseClass::BASE_CLASS_00: return enumToHumanString((PciSubClass00)subClassId, interfaceId);
        case PciBaseClass::BASE_CLASS_01: return enumToHumanString((PciSubClass01)subClassId, interfaceId);

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H
