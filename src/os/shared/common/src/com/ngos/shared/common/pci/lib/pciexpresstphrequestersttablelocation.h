#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERSTTABLELOCATION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERSTTABLELOCATION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressTphRequesterStTableLocation: u8
{
    NOT_PRESENT              = 0,
    TPH_REQUESTER_CAPABILITY = 1,
    MSI_X_TABLE              = 2
};



inline const char8* enumToString(PciExpressTphRequesterStTableLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    switch (location)
    {
        case PciExpressTphRequesterStTableLocation::NOT_PRESENT:              return "NOT_PRESENT";
        case PciExpressTphRequesterStTableLocation::TPH_REQUESTER_CAPABILITY: return "TPH_REQUESTER_CAPABILITY";
        case PciExpressTphRequesterStTableLocation::MSI_X_TABLE:              return "MSI_X_TABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressTphRequesterStTableLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%02X (%s)", (u8)location, enumToString(location));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERSTTABLELOCATION_H
