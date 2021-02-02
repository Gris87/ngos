#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICAPABILITYREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressAriCapabilityRegister
{
    union
    {
        struct
        {
            bad_uint16 mfvcFunctionGroupsCapability : 1;
            bad_uint16 acsFunctionGroupsCapability  : 1;
            bad_uint16 __reserved                   : 6;
            bad_uint16 nextFunctionNumber           : 8;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICAPABILITYREGISTER_H
