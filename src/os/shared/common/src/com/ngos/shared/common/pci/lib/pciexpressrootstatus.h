#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTSTATUS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressRootStatus
{
    union
    {
        struct
        {
            bad_uint32 pmeRequesterId : 16;
            bad_uint32 pmeStatus      : 1;
            bad_uint32 pmePending     : 1;
            bad_uint32 __reserved     : 14;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTSTATUS_H
