// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
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



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_PCIBASECLASS_H
