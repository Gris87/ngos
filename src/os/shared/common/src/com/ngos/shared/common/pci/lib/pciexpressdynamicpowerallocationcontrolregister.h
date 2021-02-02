#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressDynamicPowerAllocationControlRegister
{
    union
    {
        struct
        {
            bad_uint16 substateControl : 5;
            bad_uint16 __reserved      : 11;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONCONTROLREGISTER_H
