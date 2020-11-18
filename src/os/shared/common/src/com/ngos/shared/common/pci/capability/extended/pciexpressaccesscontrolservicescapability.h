#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSACCESSCONTROLSERVICESCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSACCESSCONTROLSERVICESCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressaccesscontrolservicesacscapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressaccesscontrolservicesacscontrolflags.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressAccessControlServicesCapability
{
    PciExtendedCapabilityHeader                    header;
    PciExpressAccessControlServicesAcsCapability   capability;
    PciExpressAccessControlServicesAcsControlFlags control;
    u32                                            egressControlVector[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSACCESSCONTROLSERVICESCAPABILITY_H
