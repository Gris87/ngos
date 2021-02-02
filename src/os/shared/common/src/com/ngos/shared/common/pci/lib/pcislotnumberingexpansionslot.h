#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCISLOTNUMBERINGEXPANSIONSLOT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCISLOTNUMBERINGEXPANSIONSLOT_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciSlotNumberingExpansionSlot
{
    union
    {
        struct
        {
            bad_uint8 expansionSlotsProvided: 5;
            bad_uint8 firstInChassis:         1;
            bad_uint8 __reserved:             2;
        };

        bad_uint8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCISLOTNUMBERINGEXPANSIONSLOT_H
