#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciMessageSignaledInterruptsExtendedMessageControl
{
    u16 tableSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return tableSize + 1;
    }



    union
    {
        struct
        {
            u16 tableSize:  11;
            u16 __reserved: 4;
            u16 enableMSIX: 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H
