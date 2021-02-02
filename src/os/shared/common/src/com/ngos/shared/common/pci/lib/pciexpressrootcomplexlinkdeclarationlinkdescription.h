#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKDESCRIPTION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKDESCRIPTION_H



#include <com/ngos/shared/common/pci/lib/pciexpressrootcomplexlinkdeclarationlinktype.h>



struct PciExpressRootComplexLinkDeclarationLinkDescription
{
    union
    {
        struct
        {
            bad_uint32 linkValid           : 1;
            bad_uint32 linkType            : 1; // TODO: Use enum PciExpressRootComplexLinkDeclarationLinkType
            bad_uint32 associateRcrbHeader : 1;
            bad_uint32 __reserved          : 13;
            bad_uint32 targetComponentId   : 8;
            bad_uint32 targetPortNumber    : 8;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKDESCRIPTION_H
