#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTSTATUS_H



#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportrateflags.h>



struct PciAcceleratedGraphicsPortStatus
{
    union
    {
        struct
        {
            bad_uint32 rate:                           2; // TODO: Use flags PciAcceleratedGraphicsPortRateFlags
            bad_uint32 __reserved:                     7;
            bad_uint32 supportSideBandAddressing:      1;
            bad_uint32 __reserved2:                    14;
            bad_uint32 maximumNumberOfCommandRequests: 8;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTSTATUS_H
