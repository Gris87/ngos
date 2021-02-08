#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTSTATUS_H



#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportrateflags.h>



struct PciAcceleratedGraphicsPortStatus
{
    union
    {
        struct
        {
            u32 rate:                           2; // TODO: Use flags PciAcceleratedGraphicsPortRateFlags
            u32 __reserved:                     7;
            u32 supportSideBandAddressing:      1;
            u32 __reserved2:                    14;
            u32 maximumNumberOfCommandRequests: 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTSTATUS_H
