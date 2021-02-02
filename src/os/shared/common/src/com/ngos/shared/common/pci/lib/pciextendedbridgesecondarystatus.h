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
            bad_uint16 is64BitDevice:             1;
            bad_uint16 support133MHz:             1;
            bad_uint16 splitCompletionDiscarded:  1;
            bad_uint16 unexpectedSplitCompletion: 1;
            bad_uint16 splitCompletionOverrun:    1;
            bad_uint16 splitRequestDelayed:       1;
            bad_uint16 secondaryClockFrequency:   3; // TODO: Use enum PciExtendedBridgeSecondaryClockFrequency
            bad_uint16 __reserved:                7;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESECONDARYSTATUS_H
