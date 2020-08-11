// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS10_PCISUBCLASS10_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS10_PCISUBCLASS10_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass10: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_10 = 0x10,
    SUB_CLASS_80 = 0x80,
};



inline const char8* enumToString(PciSubClass10 class10) // TEST: NO
{
    // COMMON_LT((" | class10 = %u", class10)); // Commented to avoid bad looking logs



    switch (class10)
    {
        case PciSubClass10::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass10::SUB_CLASS_10: return "SUB_CLASS_10";
        case PciSubClass10::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass10 class10) // TEST: NO
{
    // COMMON_LT((" | class10 = %u", class10)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class10, enumToString(class10));

    return res;
}



inline const char8* enumToHumanString(PciSubClass10 class10, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class10 = %u, interfaceId = %u", class10, interfaceId)); // Commented to avoid bad looking logs



    switch (class10)
    {
        case PciSubClass10::SUB_CLASS_00: return "Network and computing encryption device";
        case PciSubClass10::SUB_CLASS_10: return "Entertainment encryption device";
        case PciSubClass10::SUB_CLASS_80: return "Encryption controller";

        default: return "Encryption controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS10_PCISUBCLASS10_H
