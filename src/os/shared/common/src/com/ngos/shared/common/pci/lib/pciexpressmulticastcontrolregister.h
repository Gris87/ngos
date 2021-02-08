#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressMulticastControlRegister
{
    u8 mcNumGroupReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return mcNumGroup + 1;
    }



    union
    {
        struct
        {
            u16 mcNumGroup : 6;
            u16 __reserved : 9;
            u16 mcEnable   : 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCONTROLREGISTER_H
