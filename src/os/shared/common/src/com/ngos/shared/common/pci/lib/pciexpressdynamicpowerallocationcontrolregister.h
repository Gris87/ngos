#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressDynamicPowerAllocationControlRegister
{
    union
    {
        struct
        {
            u16 substateControl : 5;
            u16 __reserved      : 11;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCONTROLREGISTER_H
