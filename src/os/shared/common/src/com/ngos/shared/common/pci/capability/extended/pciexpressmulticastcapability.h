#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSMULTICASTCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSMULTICASTCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressmulticastbaseaddressregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastcapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastcontrolregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressmulticastoverlaybaseaddressregister.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressMulticastCapability
{
    PciExtendedCapabilityHeader                   header;
    PciExpressMulticastCapabilityRegister         capability;
    PciExpressMulticastControlRegister            control;
    PciExpressMulticastBaseAddressRegister        mcBaseAddress;
    bad_uint64                                           mcReceive;
    bad_uint64                                           mcBlockAll;
    bad_uint64                                           mcBlockUntranslated;
    PciExpressMulticastOverlayBaseAddressRegister mcOverlayBaseAddress;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSMULTICASTCAPABILITY_H
