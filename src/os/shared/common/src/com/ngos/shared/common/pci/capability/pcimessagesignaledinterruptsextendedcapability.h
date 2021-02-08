#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedmessagecontrol.h>
#include <com/ngos/shared/common/pci/lib/pcimessagesignaledinterruptsextendedtableoffsetbirunion.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciMessageSignaledInterruptsExtendedCapability
{
    PciCapabilityHeader                                     header;
    PciMessageSignaledInterruptsExtendedMessageControl      messageControl;
    u32                                                     messageAddressUpper;
    PciMessageSignaledInterruptsExtendedTableOffsetBirUnion tableOffsetAndBir;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIMESSAGESIGNALEDINTERRUPTSEXTENDEDCAPABILITY_H
