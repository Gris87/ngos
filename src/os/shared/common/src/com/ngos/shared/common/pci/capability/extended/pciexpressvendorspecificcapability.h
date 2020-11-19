#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSVENDORSPECIFICCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSVENDORSPECIFICCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressvendorspecificheader.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressVendorSpecificCapability
{
    PciExtendedCapabilityHeader    header;
    PciExpressVendorSpecificHeader vendorSpecificHeader;
    u8                             vendorSpecificRegisters[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSVENDORSPECIFICCAPABILITY_H
