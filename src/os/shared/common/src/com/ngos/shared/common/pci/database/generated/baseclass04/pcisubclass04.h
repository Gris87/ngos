// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS04_PCISUBCLASS04_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS04_PCISUBCLASS04_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass04: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass04 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass04::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass04::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass04::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass04::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass04::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass04 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass04 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass04::SUB_CLASS_00: return "Multimedia controller - Multimedia video controller";
        case PciSubClass04::SUB_CLASS_01: return "Multimedia controller - Multimedia audio controller";
        case PciSubClass04::SUB_CLASS_02: return "Multimedia controller - Computer telephony device";
        case PciSubClass04::SUB_CLASS_03: return "Multimedia controller - Audio device";
        case PciSubClass04::SUB_CLASS_80: return "Multimedia controller - Multimedia controller";

        default: return "Multimedia controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS04_PCISUBCLASS04_H
