#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDTABLEOFFSETBIRUNION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDTABLEOFFSETBIRUNION_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciMessageSignaledInterruptsExtendedTableOffsetBirUnion
{
    union
    {
        struct
        {
            u32 baseAddressIndicator: 3;
            u32 tableOffset:          29;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDTABLEOFFSETBIRUNION_H
