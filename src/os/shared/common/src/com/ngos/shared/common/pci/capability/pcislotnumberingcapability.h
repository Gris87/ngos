#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCISLOTNUMBERINGCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCISLOTNUMBERINGCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcislotnumberingexpansionslot.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciSlotNumberingCapability
{
    PciCapabilityHeader           header;
    PciSlotNumberingExpansionSlot expansionSlot;
    bad_uint8                            chassisNumber;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCISLOTNUMBERINGCAPABILITY_H
