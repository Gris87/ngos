#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTSELFDESCRIPTION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTSELFDESCRIPTION_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationelementtype.h>



struct PciExpressRootComplexLinkDeclarationElementSelfDescription
{
    union
    {
        struct
        {
            u32 elementType         : 4; // TODO: Use enum PciExpressRootComplexLinkDeclarationElementType
            u32 __reserved          : 4;
            u32 numberOfLinkEntries : 8;
            u32 componentId         : 8;
            u32 portNumber          : 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTSELFDESCRIPTION_H
