#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressRootComplexLinkDeclarationLinkType: u8
{
    LINK_TO_MEMORY_MAPPED_SPACE = 0,
    LINK_TO_CONFIGURATION_SPACE = 1
};



inline const char8* enumToString(PciExpressRootComplexLinkDeclarationLinkType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciExpressRootComplexLinkDeclarationLinkType::LINK_TO_MEMORY_MAPPED_SPACE: return "LINK_TO_MEMORY_MAPPED_SPACE";
        case PciExpressRootComplexLinkDeclarationLinkType::LINK_TO_CONFIGURATION_SPACE: return "LINK_TO_CONFIGURATION_SPACE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressRootComplexLinkDeclarationLinkType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKTYPE_H
