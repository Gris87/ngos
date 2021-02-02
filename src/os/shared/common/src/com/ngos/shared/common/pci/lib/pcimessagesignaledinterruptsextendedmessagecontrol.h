#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciMessageSignaledInterruptsExtendedMessageControl
{
    bad_uint16 tableSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return tableSize + 1;
    }



    union
    {
        struct
        {
            bad_uint16 tableSize:  11;
            bad_uint16 __reserved: 4;
            bad_uint16 enableMSIX: 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDMESSAGECONTROL_H
