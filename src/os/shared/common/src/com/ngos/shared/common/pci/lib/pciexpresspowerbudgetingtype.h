#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressPowerBudgetingType: bad_uint8
{
    PME_AUXILIARY = 0,
    AUXILIARY     = 1,
    IDLE          = 2,
    SUSTAINED     = 3
};



inline const char8* enumToString(PciExpressPowerBudgetingType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciExpressPowerBudgetingType::PME_AUXILIARY: return "PME_AUXILIARY";
        case PciExpressPowerBudgetingType::AUXILIARY:     return "AUXILIARY";
        case PciExpressPowerBudgetingType::IDLE:          return "IDLE";
        case PciExpressPowerBudgetingType::SUSTAINED:     return "SUSTAINED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressPowerBudgetingType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGTYPE_H
