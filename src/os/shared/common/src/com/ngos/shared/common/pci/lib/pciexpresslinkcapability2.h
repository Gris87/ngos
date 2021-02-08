#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY2_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressLinkCapability2
{
    union
    {
        struct
        {
            u32 __reserved       : 1;
            u32 linkSpeedsVector : 7;
            u32 crosslink        : 1;
            u32 __reserved2      : 23;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY2_H
