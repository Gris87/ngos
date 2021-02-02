#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressAriControlRegister
{
    union
    {
        struct
        {
            bad_uint16 mfvcFunctionGroupsEnable : 1;
            bad_uint16 acsFunctionGroupsEnable  : 1;
            bad_uint16 __reserved               : 2;
            bad_uint16 functionGroup            : 3;
            bad_uint16 __reserved2              : 9;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSARICONTROLREGISTER_H
