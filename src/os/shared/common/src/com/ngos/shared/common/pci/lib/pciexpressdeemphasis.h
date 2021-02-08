#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEEMPHASIS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEEMPHASIS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressDeemphasis: u8
{
    MINUS_6_DB   = 0,
    MINUS_3_5_DB = 1
};



inline const char8* enumToString(PciExpressDeemphasis deemphasis) // TEST: NO
{
    // COMMON_LT((" | deemphasis = %u", deemphasis)); // Commented to avoid bad looking logs



    switch (deemphasis)
    {
        case PciExpressDeemphasis::MINUS_6_DB:   return "MINUS_6_DB";
        case PciExpressDeemphasis::MINUS_3_5_DB: return "MINUS_3_5_DB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressDeemphasis deemphasis) // TEST: NO
{
    // COMMON_LT((" | deemphasis = %u", deemphasis)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)deemphasis, enumToString(deemphasis));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEEMPHASIS_H
