// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0D_PCISUBCLASS0D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0D_PCISUBCLASS0D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass0D: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_10 = 0x10,
    SUB_CLASS_11 = 0x11,
    SUB_CLASS_12 = 0x12,
    SUB_CLASS_20 = 0x20,
    SUB_CLASS_21 = 0x21,
    SUB_CLASS_80 = 0x80
};



inline const char8* enumToString(PciSubClass0D class0D) // TEST: NO
{
    // COMMON_LT((" | class0D = %u", class0D)); // Commented to avoid bad looking logs



    switch (class0D)
    {
        case PciSubClass0D::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass0D::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass0D::SUB_CLASS_10: return "SUB_CLASS_10";
        case PciSubClass0D::SUB_CLASS_11: return "SUB_CLASS_11";
        case PciSubClass0D::SUB_CLASS_12: return "SUB_CLASS_12";
        case PciSubClass0D::SUB_CLASS_20: return "SUB_CLASS_20";
        case PciSubClass0D::SUB_CLASS_21: return "SUB_CLASS_21";
        case PciSubClass0D::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass0D class0D) // TEST: NO
{
    // COMMON_LT((" | class0D = %u", class0D)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class0D, enumToString(class0D));

    return res;
}



inline const char8* enumToHumanString(PciSubClass0D class0D) // TEST: NO
{
    // COMMON_LT((" | class0D = %u", class0D)); // Commented to avoid bad looking logs



    switch (class0D)
    {
        case PciSubClass0D::SUB_CLASS_00: return "Wireless controller - IRDA controller";
        case PciSubClass0D::SUB_CLASS_01: return "Wireless controller - Consumer IR controller";
        case PciSubClass0D::SUB_CLASS_10: return "Wireless controller - RF controller";
        case PciSubClass0D::SUB_CLASS_11: return "Wireless controller - Bluetooth";
        case PciSubClass0D::SUB_CLASS_12: return "Wireless controller - Broadband";
        case PciSubClass0D::SUB_CLASS_20: return "Wireless controller - 802.1a controller";
        case PciSubClass0D::SUB_CLASS_21: return "Wireless controller - 802.1b controller";
        case PciSubClass0D::SUB_CLASS_80: return "Wireless controller - Wireless controller";

        default: return "Wireless controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS0D_PCISUBCLASS0D_H
