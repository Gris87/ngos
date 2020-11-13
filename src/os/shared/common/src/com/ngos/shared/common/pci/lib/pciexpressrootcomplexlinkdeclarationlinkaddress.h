#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESS_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkaddresslinkconfigurationspace.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinkaddresslinkmemorymappedspace.h>



struct PciExpressRootComplexLinkDeclarationLinkAndress
{
    union
    {
        PciExpressRootComplexLinkDeclarationLinkAndressMemoryMappedSpace  memoryMappedSpace;
        PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace configurationSpace;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESS_H
