#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONSTATUSREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONSTATUSREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressDynamicPowerAllocationStatusRegister
{
    union
    {
        struct
        {
            u16 substateStatus         : 5;
            u16 __reserved             : 3;
            u16 substateControlEnabled : 1;
            u16 __reserved2            : 7;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONSTATUSREGISTER_H
