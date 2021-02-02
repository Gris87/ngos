#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTSCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTSCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessageaddress.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessagecontrol.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciMessageSignaledInterruptsCapability
{
    PciCapabilityHeader                        header;
    PciMessageSignaledInterruptsMessageControl messageControl;
    PciMessageSignaledInterruptsMessageAddress messageAddress;
    bad_uint16                                        messageData;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTSCAPABILITY_H
