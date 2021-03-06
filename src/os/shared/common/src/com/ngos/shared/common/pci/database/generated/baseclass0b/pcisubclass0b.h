// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0B_PCISUBCLASS0B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0B_PCISUBCLASS0B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass0B: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_10 = 0x10,
    SUB_CLASS_20 = 0x20,
    SUB_CLASS_30 = 0x30,
    SUB_CLASS_40 = 0x40
};



inline const char8* enumToString(PciSubClass0B subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass0B::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass0B::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass0B::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass0B::SUB_CLASS_10: return "SUB_CLASS_10";
        case PciSubClass0B::SUB_CLASS_20: return "SUB_CLASS_20";
        case PciSubClass0B::SUB_CLASS_30: return "SUB_CLASS_30";
        case PciSubClass0B::SUB_CLASS_40: return "SUB_CLASS_40";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass0B subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass0B subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass0B::SUB_CLASS_00: return "Processor - 386";
        case PciSubClass0B::SUB_CLASS_01: return "Processor - 486";
        case PciSubClass0B::SUB_CLASS_02: return "Processor - Pentium";
        case PciSubClass0B::SUB_CLASS_10: return "Processor - Alpha";
        case PciSubClass0B::SUB_CLASS_20: return "Processor - Power PC";
        case PciSubClass0B::SUB_CLASS_30: return "Processor - MIPS";
        case PciSubClass0B::SUB_CLASS_40: return "Processor - Co-processor";

        default: return "Processor";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0B_PCISUBCLASS0B_H
