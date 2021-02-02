#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORSTATUS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressRootErrorStatus
{
    union
    {
        struct
        {
            bad_uint32 errCorReceived                      : 1;
            bad_uint32 multipleErrCorReceived              : 1;
            bad_uint32 errFatalOrNonFatalReceived          : 1;
            bad_uint32 multipleErrFatalOrNonFatalReceived  : 1;
            bad_uint32 firstUncorrectableFatal             : 1;
            bad_uint32 nonFatalErrorMessagesReceived       : 1;
            bad_uint32 fatalErrorMessagesReceived          : 1;
            bad_uint32 __reserved                          : 20;
            bad_uint32 advancedErrorInterruptMessageNumber : 5;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORSTATUS_H
