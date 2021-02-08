#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTCOMMAND_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTCOMMAND_H



#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportrateflags.h>



struct PciAcceleratedGraphicsPortCommand
{
    union
    {
        struct
        {
            u32 rate:                           3; // TODO: Use flags PciAcceleratedGraphicsPortRateFlags
            u32 __reserved:                     5;
            u32 enableAcceleratedGraphicsPort:  1;
            u32 enableSideBandAddressing:       1;
            u32 __reserved2:                    14;
            u32 maximumNumberOfCommandRequests: 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTCOMMAND_H
