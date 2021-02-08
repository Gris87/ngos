#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORSTATUS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressRootErrorStatus
{
    union
    {
        struct
        {
            u32 errCorReceived                      : 1;
            u32 multipleErrCorReceived              : 1;
            u32 errFatalOrNonFatalReceived          : 1;
            u32 multipleErrFatalOrNonFatalReceived  : 1;
            u32 firstUncorrectableFatal             : 1;
            u32 nonFatalErrorMessagesReceived       : 1;
            u32 fatalErrorMessagesReceived          : 1;
            u32 __reserved                          : 20;
            u32 advancedErrorInterruptMessageNumber : 5;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORSTATUS_H
