// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS05_PCISUBCLASS05_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS05_PCISUBCLASS05_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass05: bad_uint8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass05 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass05::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass05::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass05::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass05 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (bad_uint8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass05 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass05::SUB_CLASS_00: return "Memory controller - RAM memory";
        case PciSubClass05::SUB_CLASS_01: return "Memory controller - FLASH memory";
        case PciSubClass05::SUB_CLASS_80: return "Memory controller - Memory controller";

        default: return "Memory controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS05_PCISUBCLASS05_H
