#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTBASEADDRESSREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTBASEADDRESSREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressMulticastBaseAddressRegister
{
    union
    {
        struct
        {
            u64 mcIndexPosition : 6;
            u64 __reserved      : 6;
            u64 mcBaseAddress   : 52;
        };

        u64 value64;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSMULTICASTBASEADDRESSREGISTER_H
