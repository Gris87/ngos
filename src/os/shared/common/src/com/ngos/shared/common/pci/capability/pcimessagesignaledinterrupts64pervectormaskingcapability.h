#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTS64PERVECTORMASKINGCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTS64PERVECTORMASKINGCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessageaddress.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsmessagecontrol.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciMessageSignaledInterrupts64PerVectorMaskingCapability
{
    PciCapabilityHeader                        header;
    PciMessageSignaledInterruptsMessageControl messageControl;
    PciMessageSignaledInterruptsMessageAddress messageAddress;
    u32                                        messageAddressUpper;
    u16                                        messageData;
    u16                                        __reserved;
    u32                                        maskBits;
    u32                                        pendingBits;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTS64PERVECTORMASKINGCAPABILITY_H
