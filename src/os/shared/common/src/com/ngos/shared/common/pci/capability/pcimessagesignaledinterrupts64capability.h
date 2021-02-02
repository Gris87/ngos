#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTS64CAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTS64CAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessageaddress.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessagecontrol.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciMessageSignaledInterrupts64Capability
{
    PciCapabilityHeader                        header;
    PciMessageSignaledInterruptsMessageControl messageControl;
    PciMessageSignaledInterruptsMessageAddress messageAddress;
    bad_uint32                                        messageAddressUpper;
    bad_uint16                                        messageData;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTS64CAPABILITY_H
