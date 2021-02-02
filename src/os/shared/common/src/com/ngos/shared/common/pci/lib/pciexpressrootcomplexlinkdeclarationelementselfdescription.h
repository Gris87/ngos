#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTSELFDESCRIPTION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTSELFDESCRIPTION_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationelementtype.h>



struct PciExpressRootComplexLinkDeclarationElementSelfDescription
{
    union
    {
        struct
        {
            bad_uint32 elementType         : 4; // TODO: Use enum PciExpressRootComplexLinkDeclarationElementType
            bad_uint32 __reserved          : 4;
            bad_uint32 numberOfLinkEntries : 8;
            bad_uint32 componentId         : 8;
            bad_uint32 portNumber          : 8;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTSELFDESCRIPTION_H
