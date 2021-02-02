#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGEADDRESS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGEADDRESS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciMessageSignaledInterruptsMessageAddress
{
    union
    {
        struct
        {
            bad_uint32 __reserved: 2;
            bad_uint32 value:      30;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGEADDRESS_H
