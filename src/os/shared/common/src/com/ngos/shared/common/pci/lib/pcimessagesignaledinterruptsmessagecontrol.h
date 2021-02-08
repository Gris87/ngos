#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciMessageSignaledInterruptsMessageControl
{
    u16 supportMultipleMessageReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (1ULL << supportMultipleMessage);
    }

    u16 enableMultipleMessageReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (1ULL << enableMultipleMessage);
    }



    union
    {
        struct
        {
            u16 enableMSI:               1;
            u16 supportMultipleMessage:  3;
            u16 enableMultipleMessage:   3;
            u16 support64BitAddress:     1;
            u16 supportPerVectorMasking: 1;
            u16 __reserved:              7;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H
