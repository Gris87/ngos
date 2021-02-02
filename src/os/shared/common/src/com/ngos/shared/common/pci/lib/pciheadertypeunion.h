#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHEADERTYPEUNION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHEADERTYPEUNION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciheadertype.h>



struct PciHeaderTypeUnion
{
    union
    {
        struct
        {
            bad_uint8 type:            7; // TODO: Use enum PciHeaderType
            bad_uint8 isMultiFunction: 1;
        };

        bad_uint8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHEADERTYPEUNION_H
