#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESECONDARYSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESECONDARYSTATUS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgesecondaryclockfrequency.h>



struct PciExtendedBridgeSecondaryStatus
{
    union
    {
        struct
        {
            u16 is64BitDevice:             1;
            u16 support133MHz:             1;
            u16 splitCompletionDiscarded:  1;
            u16 unexpectedSplitCompletion: 1;
            u16 splitCompletionOverrun:    1;
            u16 splitRequestDelayed:       1;
            u16 secondaryClockFrequency:   3; // TODO: Use enum PciExtendedBridgeSecondaryClockFrequency
            u16 __reserved:                7;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESECONDARYSTATUS_H
