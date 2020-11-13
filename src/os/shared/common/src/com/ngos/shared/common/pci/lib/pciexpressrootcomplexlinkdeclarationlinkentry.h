#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKENTRY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKENTRY_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkaddress.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkdescription.h>



struct PciExpressRootComplexLinkDeclarationLinkEntry
{
    PciExpressRootComplexLinkDeclarationLinkDescription linkDescription;
    u32                                                 __reserved;
    PciExpressRootComplexLinkDeclarationLinkAndress     linkAddress;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKENTRY_H
