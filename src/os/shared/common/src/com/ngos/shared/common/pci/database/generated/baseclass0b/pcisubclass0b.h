// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0B_PCISUBCLASS0B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0B_PCISUBCLASS0B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass0B: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_10 = 0x10,
    SUB_CLASS_20 = 0x20,
    SUB_CLASS_30 = 0x30,
    SUB_CLASS_40 = 0x40,
};



inline const char8* enumToString(PciSubClass0B class0B) // TEST: NO
{
    // COMMON_LT((" | class0B = %u", class0B)); // Commented to avoid bad looking logs



    switch (class0B)
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



inline const char8* enumToFullString(PciSubClass0B class0B) // TEST: NO
{
    // COMMON_LT((" | class0B = %u", class0B)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class0B, enumToString(class0B));

    return res;
}



inline const char8* enumToHumanString(PciSubClass0B class0B, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class0B = %u, interfaceId = %u", class0B, interfaceId)); // Commented to avoid bad looking logs



    switch (class0B)
    {
        case PciSubClass0B::SUB_CLASS_00: return "386";
        case PciSubClass0B::SUB_CLASS_01: return "486";
        case PciSubClass0B::SUB_CLASS_02: return "Pentium";
        case PciSubClass0B::SUB_CLASS_10: return "Alpha";
        case PciSubClass0B::SUB_CLASS_20: return "Power PC";
        case PciSubClass0B::SUB_CLASS_30: return "MIPS";
        case PciSubClass0B::SUB_CLASS_40: return "Co-processor";

        default: return "Processor";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0B_PCISUBCLASS0B_H
