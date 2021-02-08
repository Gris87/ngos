#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICAPABILITYREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressAriCapabilityRegister
{
    union
    {
        struct
        {
            u16 mfvcFunctionGroupsCapability : 1;
            u16 acsFunctionGroupsCapability  : 1;
            u16 __reserved                   : 6;
            u16 nextFunctionNumber           : 8;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICAPABILITYREGISTER_H
