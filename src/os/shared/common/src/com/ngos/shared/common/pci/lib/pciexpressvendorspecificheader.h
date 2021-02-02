#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVENDORSPECIFICHEADER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVENDORSPECIFICHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressVendorSpecificHeader
{
    union
    {
        struct
        {
            bad_uint32 id       : 16;
            bad_uint32 revision : 4;
            bad_uint32 length   : 12;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVENDORSPECIFICHEADER_H
