#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTSTATUS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressRootStatus
{
    union
    {
        struct
        {
            u32 pmeRequesterId : 16;
            u32 pmeStatus      : 1;
            u32 pmePending     : 1;
            u32 __reserved     : 14;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTSTATUS_H
