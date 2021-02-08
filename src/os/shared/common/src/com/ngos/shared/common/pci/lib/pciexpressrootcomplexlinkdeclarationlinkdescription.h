#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKDESCRIPTION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKDESCRIPTION_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinktype.h>



struct PciExpressRootComplexLinkDeclarationLinkDescription
{
    union
    {
        struct
        {
            u32 linkValid           : 1;
            u32 linkType            : 1; // TODO: Use enum PciExpressRootComplexLinkDeclarationLinkType
            u32 associateRcrbHeader : 1;
            u32 __reserved          : 13;
            u32 targetComponentId   : 8;
            u32 targetPortNumber    : 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKDESCRIPTION_H
