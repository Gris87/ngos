#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexinternallinkcontrollinkcapabilities.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexinternallinkcontrollinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexinternallinkcontrollinkstatus.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressRootComplexInternalLinkControlCapability
{
    PciExtendedCapabilityHeader                              header;
    PciExpressRootComplexInternalLinkControlLinkCapabilities rootComplexLinkCapabilities;
    PciExpressRootComplexInternalLinkControlLinkControl      rootComplexLinkControl;
    PciExpressRootComplexInternalLinkControlLinkStatus       rootComplexLinkStatus;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLCAPABILITY_H
