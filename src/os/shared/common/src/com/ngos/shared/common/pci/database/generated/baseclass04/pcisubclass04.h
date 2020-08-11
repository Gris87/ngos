// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS04_PCISUBCLASS04_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS04_PCISUBCLASS04_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass04: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_80 = 0x80,
};



inline const char8* enumToString(PciSubClass04 class04) // TEST: NO
{
    // COMMON_LT((" | class04 = %u", class04)); // Commented to avoid bad looking logs



    switch (class04)
    {
        case PciSubClass04::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass04::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass04::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass04::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass04::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass04 class04) // TEST: NO
{
    // COMMON_LT((" | class04 = %u", class04)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class04, enumToString(class04));

    return res;
}



inline const char8* enumToHumanString(PciSubClass04 class04, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class04 = %u, interfaceId = %u", class04, interfaceId)); // Commented to avoid bad looking logs



    switch (class04)
    {
        case PciSubClass04::SUB_CLASS_00: return "Multimedia video controller";
        case PciSubClass04::SUB_CLASS_01: return "Multimedia audio controller";
        case PciSubClass04::SUB_CLASS_02: return "Computer telephony device";
        case PciSubClass04::SUB_CLASS_03: return "Audio device";
        case PciSubClass04::SUB_CLASS_80: return "Multimedia controller";

        default: return "Multimedia controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS04_PCISUBCLASS04_H
