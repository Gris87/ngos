#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVENDORSPECIFICHEADER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVENDORSPECIFICHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressVendorSpecificHeader
{
    union
    {
        struct
        {
            u32 id       : 16;
            u32 revision : 4;
            u32 length   : 12;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVENDORSPECIFICHEADER_H
