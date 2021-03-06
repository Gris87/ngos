// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCISUBCLASS00_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCISUBCLASS00_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass00: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_05 = 0x05
};



inline const char8* enumToString(PciSubClass00 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass00::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass00::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass00::SUB_CLASS_05: return "SUB_CLASS_05";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass00 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass00 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass00::SUB_CLASS_00: return "Unclassified device - Non-VGA unclassified device";
        case PciSubClass00::SUB_CLASS_01: return "Unclassified device - VGA compatible unclassified device";
        case PciSubClass00::SUB_CLASS_05: return "Unclassified device - Image coprocessor";

        default: return "Unclassified device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCISUBCLASS00_H
