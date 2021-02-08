#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGEADDRESS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGEADDRESS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciMessageSignaledInterruptsMessageAddress
{
    union
    {
        struct
        {
            u32 __reserved: 2;
            u32 value:      30;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGEADDRESS_H
