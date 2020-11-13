#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationelementselfdescription.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkentry.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressRootComplexLinkDeclarationCapability
{
    PciExtendedCapabilityHeader                                header;
    PciExpressRootComplexLinkDeclarationElementSelfDescription elementSelfDescription;
    u32                                                        __reserved;
    PciExpressRootComplexLinkDeclarationLinkEntry              linkEntry[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONCAPABILITY_H
