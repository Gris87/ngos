#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESTATUS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExtendedBridgeStatus
{
    union
    {
        struct
        {
            bad_uint32 functionNumber:            3;
            bad_uint32 deviceNumber:              5;
            bad_uint32 busNumber:                 8;
            bad_uint32 is64BitDevice:             1;
            bad_uint32 support133MHz:             1;
            bad_uint32 splitCompletionDiscarded:  1;
            bad_uint32 unexpectedSplitCompletion: 1;
            bad_uint32 splitCompletionOverrun:    1;
            bad_uint32 splitRequestDelayed:       1;
            bad_uint32 __reserved:                10;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESTATUS_H
