#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressRootComplexLinkDeclarationElementType: u8
{
    CONFIGURATION_SPACE_ELEMENT         = 0,
    SYSTEM_EGRESS_PORT_OR_INTERNAL_SINK = 1,
    INTERNAL_ROOT_COMPLEX_LINK          = 2
};



inline const char8* enumToString(PciExpressRootComplexLinkDeclarationElementType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciExpressRootComplexLinkDeclarationElementType::CONFIGURATION_SPACE_ELEMENT:         return "CONFIGURATION_SPACE_ELEMENT";
        case PciExpressRootComplexLinkDeclarationElementType::SYSTEM_EGRESS_PORT_OR_INTERNAL_SINK: return "SYSTEM_EGRESS_PORT_OR_INTERNAL_SINK";
        case PciExpressRootComplexLinkDeclarationElementType::INTERNAL_ROOT_COMPLEX_LINK:          return "INTERNAL_ROOT_COMPLEX_LINK";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressRootComplexLinkDeclarationElementType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[43];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONELEMENTTYPE_H
