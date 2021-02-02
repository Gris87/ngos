#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTCOMMAND_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTCOMMAND_H



#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportrateflags.h>



struct PciAcceleratedGraphicsPortCommand
{
    union
    {
        struct
        {
            bad_uint32 rate:                           3; // TODO: Use flags PciAcceleratedGraphicsPortRateFlags
            bad_uint32 __reserved:                     5;
            bad_uint32 enableAcceleratedGraphicsPort:  1;
            bad_uint32 enableSideBandAddressing:       1;
            bad_uint32 __reserved2:                    14;
            bad_uint32 maximumNumberOfCommandRequests: 8;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIACCELERATEDGRAPHICSPORTCOMMAND_H
