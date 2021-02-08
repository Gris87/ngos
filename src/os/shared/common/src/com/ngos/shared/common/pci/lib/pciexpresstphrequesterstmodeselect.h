#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERSTMODESELECT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERSTMODESELECT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressTphRequesterStModeSelect: u8
{
    NO_ST_MODE            = 0,
    INTERRUPT_VECTOR_MODE = 1,
    DEVICE_SPECIFIC_MODE  = 2
};



inline const char8* enumToString(PciExpressTphRequesterStModeSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    switch (select)
    {
        case PciExpressTphRequesterStModeSelect::NO_ST_MODE:            return "NO_ST_MODE";
        case PciExpressTphRequesterStModeSelect::INTERRUPT_VECTOR_MODE: return "INTERRUPT_VECTOR_MODE";
        case PciExpressTphRequesterStModeSelect::DEVICE_SPECIFIC_MODE:  return "DEVICE_SPECIFIC_MODE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressTphRequesterStModeSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    static char8 res[29];

    sprintf(res, "0x%02X (%s)", (u8)select, enumToString(select));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERSTMODESELECT_H
