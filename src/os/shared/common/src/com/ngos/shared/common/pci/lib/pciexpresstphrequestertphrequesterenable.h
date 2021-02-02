#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERTPHREQUESTERENABLE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERTPHREQUESTERENABLE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressTphRequesterTphRequesterEnable: bad_uint8
{
    NO_TPH_OR_EXTENDED_TPH  = 0,
    TPH_AND_NO_EXTENDED_TPH = 1,
    TPH_AND_EXTENDED_TPH    = 3
};



inline const char8* enumToString(PciExpressTphRequesterTphRequesterEnable enable) // TEST: NO
{
    // COMMON_LT((" | enable = %u", enable)); // Commented to avoid bad looking logs



    switch (enable)
    {
        case PciExpressTphRequesterTphRequesterEnable::NO_TPH_OR_EXTENDED_TPH:  return "NO_TPH_OR_EXTENDED_TPH";
        case PciExpressTphRequesterTphRequesterEnable::TPH_AND_NO_EXTENDED_TPH: return "TPH_AND_NO_EXTENDED_TPH";
        case PciExpressTphRequesterTphRequesterEnable::TPH_AND_EXTENDED_TPH:    return "TPH_AND_EXTENDED_TPH";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressTphRequesterTphRequesterEnable enable) // TEST: NO
{
    // COMMON_LT((" | enable = %u", enable)); // Commented to avoid bad looking logs



    static char8 res[31];

    sprintf(res, "0x%02X (%s)", (bad_uint8)enable, enumToString(enable));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERTPHREQUESTERENABLE_H
