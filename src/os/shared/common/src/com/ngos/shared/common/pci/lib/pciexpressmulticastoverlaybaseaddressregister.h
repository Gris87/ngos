#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTOVERLAYBASEADDRESSREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTOVERLAYBASEADDRESSREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressMulticastOverlayBaseAddressRegister
{
    union
    {
        struct
        {
            u64 mcOverlaySize        : 6;
            u64 mcOverlayBaseAddress : 58;
        };

        u64 value64;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTOVERLAYBASEADDRESSREGISTER_H
