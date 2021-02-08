// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS09_PCISUBCLASS09_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS09_PCISUBCLASS09_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass09/pciinterface0904.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass09: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_04 = 0x04,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass09 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass09::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass09::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass09::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass09::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass09::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass09::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass09 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass09 subClass, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | subClass = %u, interfaceId = %u", subClass, interfaceId)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass09::SUB_CLASS_00: return "Input device controller - Keyboard controller";
        case PciSubClass09::SUB_CLASS_01: return "Input device controller - Digitizer Pen";
        case PciSubClass09::SUB_CLASS_02: return "Input device controller - Mouse controller";
        case PciSubClass09::SUB_CLASS_03: return "Input device controller - Scanner controller";
        case PciSubClass09::SUB_CLASS_04: return enumToHumanString((PciInterface0904)interfaceId);
        case PciSubClass09::SUB_CLASS_80: return "Input device controller - Input device controller";

        default: return "Input device controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS09_PCISUBCLASS09_H
