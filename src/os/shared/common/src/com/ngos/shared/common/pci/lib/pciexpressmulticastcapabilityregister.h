#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressMulticastCapabilityRegister
{
    u8 mcMaxGroupReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return mcMaxGroup + 1;
    }



    union
    {
        struct
        {
            u16 mcMaxGroup                  : 6;
            u16 __reserved                  : 2;
            u16 mcWindowSizeRequested       : 6;
            u16 __reserved2                 : 1;
            u16 mcEcrcRegenerationSupported : 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H
