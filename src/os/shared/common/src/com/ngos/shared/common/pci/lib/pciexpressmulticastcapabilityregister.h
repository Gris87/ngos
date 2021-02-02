#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressMulticastCapabilityRegister
{
    bad_uint8 mcMaxGroupReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return mcMaxGroup + 1;
    }



    union
    {
        struct
        {
            bad_uint16 mcMaxGroup                  : 6;
            bad_uint16 __reserved                  : 2;
            bad_uint16 mcWindowSizeRequested       : 6;
            bad_uint16 __reserved2                 : 1;
            bad_uint16 mcEcrcRegenerationSupported : 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTCAPABILITYREGISTER_H
