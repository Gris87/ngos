// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0A_PCISUBCLASS0A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0A_PCISUBCLASS0A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass0A: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_80 = 0x80,
};



inline const char8* enumToString(PciSubClass0A class0A) // TEST: NO
{
    // COMMON_LT((" | class0A = %u", class0A)); // Commented to avoid bad looking logs



    switch (class0A)
    {
        case PciSubClass0A::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass0A::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass0A class0A) // TEST: NO
{
    // COMMON_LT((" | class0A = %u", class0A)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class0A, enumToString(class0A));

    return res;
}



inline const char8* enumToHumanString(PciSubClass0A class0A, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class0A = %u, interfaceId = %u", class0A, interfaceId)); // Commented to avoid bad looking logs



    switch (class0A)
    {
        case PciSubClass0A::SUB_CLASS_00: return "Generic Docking Station";
        case PciSubClass0A::SUB_CLASS_80: return "Docking Station";

        default: return "Docking station";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0A_PCISUBCLASS0A_H
