#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY2_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressLinkCapability2
{
    union
    {
        struct
        {
            bad_uint32 __reserved       : 1;
            bad_uint32 linkSpeedsVector : 7;
            bad_uint32 crosslink        : 1;
            bad_uint32 __reserved2      : 23;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY2_H
