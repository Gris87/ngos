#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIVITALPRODUCTDATAADDRESSUNION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIVITALPRODUCTDATAADDRESSUNION_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciVitalProductDataAddressUnion
{
    union
    {
        struct
        {
            bad_uint16 value:    15;
            bad_uint16 finished: 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIVITALPRODUCTDATAADDRESSUNION_H
