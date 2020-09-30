#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSEXTENDEDTAGFIELD_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSEXTENDEDTAGFIELD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressExtendedTagField: u8
{
    _5_BIT_FIELD = 0,
    _8_BIT_FIELD = 1
};



inline const char8* enumToString(PciExpressExtendedTagField field) // TEST: NO
{
    // COMMON_LT((" | field = %u", field)); // Commented to avoid bad looking logs



    switch (field)
    {
        case PciExpressExtendedTagField::_5_BIT_FIELD: return "5_BIT_FIELD";
        case PciExpressExtendedTagField::_8_BIT_FIELD: return "8_BIT_FIELD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressExtendedTagField field) // TEST: NO
{
    // COMMON_LT((" | field = %u", field)); // Commented to avoid bad looking logs



    static char8 res[19];

    sprintf(res, "0x%02X (%s)", (u8)field, enumToString(field));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSEXTENDEDTAGFIELD_H
