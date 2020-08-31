#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXTENDEDBRIDGECAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXTENDEDBRIDGECAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciextendedbridgedownstreamsplittransaction.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgesecondarystatus.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgestatus.h>
#include <com/ngos/shared/common/pci/lib/pciextendedbridgeupstreamsplittransaction.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciExtendedBridgeCapability
{
    PciCapabilityHeader                         header;
    PciExtendedBridgeSecondaryStatus            secondaryStatus;
    PciExtendedBridgeStatus                     status;
    PciExtendedBridgeUpstreamSplitTransaction   upstream;
    PciExtendedBridgeDownstreamSplitTransaction downstream;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXTENDEDBRIDGECAPABILITY_H
