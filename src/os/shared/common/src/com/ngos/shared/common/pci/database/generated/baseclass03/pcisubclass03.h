// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS03_PCISUBCLASS03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS03_PCISUBCLASS03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass03/pciinterface0300.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass03: bad_uint8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass03 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass03::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass03::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass03::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass03::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass03 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass03 subClass, bad_uint8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | subClass = %u, interfaceId = %u", subClass, interfaceId)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass03::SUB_CLASS_00: return enumToHumanString((PciInterface0300)interfaceId);
        case PciSubClass03::SUB_CLASS_01: return "Display controller - XGA compatible controller";
        case PciSubClass03::SUB_CLASS_02: return "Display controller - 3D controller";
        case PciSubClass03::SUB_CLASS_80: return "Display controller - Display controller";

        default: return "Display controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS03_PCISUBCLASS03_H
