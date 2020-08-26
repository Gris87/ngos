#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCISLOTNUMBERINGEXPANSIONSLOT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCISLOTNUMBERINGEXPANSIONSLOT_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciSlotNumberingExpansionSlot
{
    union
    {
        struct
        {
            u8 expansionSlotsProvided: 5;
            u8 firstInChassis:         1;
            u8 __reserved:             2;
        };

        u8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCISLOTNUMBERINGEXPANSIONSLOT_H
