#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressAriControlRegister
{
    union
    {
        struct
        {
            u16 mfvcFunctionGroupsEnable : 1;
            u16 acsFunctionGroupsEnable  : 1;
            u16 __reserved               : 2;
            u16 functionGroup            : 3;
            u16 __reserved2              : 9;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICONTROLREGISTER_H
