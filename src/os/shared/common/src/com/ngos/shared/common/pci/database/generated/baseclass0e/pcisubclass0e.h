// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0E_PCISUBCLASS0E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0E_PCISUBCLASS0E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass0E: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00
};



inline const char8* enumToString(PciSubClass0E class0E) // TEST: NO
{
    // COMMON_LT((" | class0E = %u", class0E)); // Commented to avoid bad looking logs



    switch (class0E)
    {
        case PciSubClass0E::SUB_CLASS_00: return "SUB_CLASS_00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass0E class0E) // TEST: NO
{
    // COMMON_LT((" | class0E = %u", class0E)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class0E, enumToString(class0E));

    return res;
}



inline const char8* enumToHumanString(PciSubClass0E class0E) // TEST: NO
{
    // COMMON_LT((" | class0E = %u", class0E)); // Commented to avoid bad looking logs



    switch (class0E)
    {
        case PciSubClass0E::SUB_CLASS_00: return "Intelligent controller - I2O";

        default: return "Intelligent controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0E_PCISUBCLASS0E_H
