// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0F_PCISUBCLASS0F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0F_PCISUBCLASS0F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass0F: bad_uint8 // Ignore CppEnumVerifier
{
    NONE         = 0,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_04 = 0x04
};



inline const char8* enumToString(PciSubClass0F subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass0F::NONE:         return "NONE";
        case PciSubClass0F::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass0F::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass0F::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass0F::SUB_CLASS_04: return "SUB_CLASS_04";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass0F subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass0F subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass0F::SUB_CLASS_01: return "Satellite communications controller - Satellite TV controller";
        case PciSubClass0F::SUB_CLASS_02: return "Satellite communications controller - Satellite audio communication controller";
        case PciSubClass0F::SUB_CLASS_03: return "Satellite communications controller - Satellite voice communication controller";
        case PciSubClass0F::SUB_CLASS_04: return "Satellite communications controller - Satellite data communication controller";

        default: return "Satellite communications controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0F_PCISUBCLASS0F_H
