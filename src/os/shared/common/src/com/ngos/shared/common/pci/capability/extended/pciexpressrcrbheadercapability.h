#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSRCRBHEADERCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSRCRBHEADERCAPABILITY_H



#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrcrbheadercapabilitiesflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrcrbheadercontrolflags.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressRcrbHeaderCapability
{
    PciExtendedCapabilityHeader           header;
    PciVendor                             vendorId;
    u16                                   deviceId;
    PciExpressRcrbHeaderCapabilitiesFlags capabilities;
    PciExpressRcrbHeaderControlFlags      control;
    u32                                   __reserved;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSRCRBHEADERCAPABILITY_H
