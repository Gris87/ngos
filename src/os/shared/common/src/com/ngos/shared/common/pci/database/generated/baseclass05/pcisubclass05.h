// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS05_PCISUBCLASS05_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS05_PCISUBCLASS05_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass05: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_80 = 0x80,
};



inline const char8* enumToString(PciSubClass05 class05) // TEST: NO
{
    // COMMON_LT((" | class05 = %u", class05)); // Commented to avoid bad looking logs



    switch (class05)
    {
        case PciSubClass05::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass05::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass05::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass05 class05) // TEST: NO
{
    // COMMON_LT((" | class05 = %u", class05)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class05, enumToString(class05));

    return res;
}



inline const char8* enumToHumanString(PciSubClass05 class05, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class05 = %u, interfaceId = %u", class05, interfaceId)); // Commented to avoid bad looking logs



    switch (class05)
    {
        case PciSubClass05::SUB_CLASS_00: return "RAM memory";
        case PciSubClass05::SUB_CLASS_01: return "FLASH memory";
        case PciSubClass05::SUB_CLASS_80: return "Memory controller";

        default: return "Memory controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS05_PCISUBCLASS05_H
