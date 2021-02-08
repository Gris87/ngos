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
            u8 type:            7; // TODO: Use enum PciHeaderType
            u8 isMultiFunction: 1;
        };

        u8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHEADERTYPEUNION_H
