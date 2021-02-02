#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciMessageSignaledInterruptsMessageControl
{
    bad_uint16 supportMultipleMessageReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (1ULL << supportMultipleMessage);
    }

    bad_uint16 enableMultipleMessageReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (1ULL << enableMultipleMessage);
    }



    union
    {
        struct
        {
            bad_uint16 enableMSI:               1;
            bad_uint16 supportMultipleMessage:  3;
            bad_uint16 enableMultipleMessage:   3;
            bad_uint16 support64BitAddress:     1;
            bad_uint16 supportPerVectorMasking: 1;
            bad_uint16 __reserved:              7;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSMESSAGECONTROL_H
