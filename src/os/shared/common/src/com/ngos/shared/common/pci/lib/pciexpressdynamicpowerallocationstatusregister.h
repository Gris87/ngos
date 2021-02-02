#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONSTATUSREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONSTATUSREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressDynamicPowerAllocationStatusRegister
{
    union
    {
        struct
        {
            bad_uint16 substateStatus         : 5;
            bad_uint16 __reserved             : 3;
            bad_uint16 substateControlEnabled : 1;
            bad_uint16 __reserved2            : 7;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDYNAMICPOWERALLOCATIONSTATUSREGISTER_H
