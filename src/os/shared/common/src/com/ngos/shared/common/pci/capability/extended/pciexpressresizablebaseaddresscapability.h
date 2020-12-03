#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddresscapabilityandcontrol.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressResizableBaseAddressCapability
{
    PciExtendedCapabilityHeader                        header;
    PciExpressResizableBaseAddressCapabilityAndControl capabilityAndControl[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITY_H
