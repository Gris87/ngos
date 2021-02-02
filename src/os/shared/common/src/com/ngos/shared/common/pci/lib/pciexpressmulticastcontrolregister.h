#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressMulticastControlRegister
{
    bad_uint8 mcNumGroupReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return mcNumGroup + 1;
    }



    union
    {
        struct
        {
            bad_uint16 mcNumGroup : 6;
            bad_uint16 __reserved : 9;
            bad_uint16 mcEnable   : 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H
