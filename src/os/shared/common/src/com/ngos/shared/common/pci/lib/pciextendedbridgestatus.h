#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESTATUS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExtendedBridgeStatus
{
    union
    {
        struct
        {
            u32 functionNumber:            3;
            u32 deviceNumber:              5;
            u32 busNumber:                 8;
            u32 is64BitDevice:             1;
            u32 support133MHz:             1;
            u32 splitCompletionDiscarded:  1;
            u32 unexpectedSplitCompletion: 1;
            u32 splitCompletionOverrun:    1;
            u32 splitRequestDelayed:       1;
            u32 __reserved:                10;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESTATUS_H
