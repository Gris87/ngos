// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS10_PCISUBCLASS10_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS10_PCISUBCLASS10_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass10: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_10 = 0x10,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass10 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass10::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass10::SUB_CLASS_10: return "SUB_CLASS_10";
        case PciSubClass10::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass10 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass10 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass10::SUB_CLASS_00: return "Encryption controller - Network and computing encryption device";
        case PciSubClass10::SUB_CLASS_10: return "Encryption controller - Entertainment encryption device";
        case PciSubClass10::SUB_CLASS_80: return "Encryption controller - Encryption controller";

        default: return "Encryption controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS10_PCISUBCLASS10_H
