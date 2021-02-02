#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTOVERLAYBASEADDRESSREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTOVERLAYBASEADDRESSREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressMulticastOverlayBaseAddressRegister
{
    union
    {
        struct
        {
            bad_uint64 mcOverlaySize        : 6;
            bad_uint64 mcOverlayBaseAddress : 58;
        };

        bad_uint64 value64;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTOVERLAYBASEADDRESSREGISTER_H
