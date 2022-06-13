#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHCOMPLETERFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHCOMPLETERFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 pci_express_tph_completer_flags;

enum class PciExpressTphCompleterFlag: pci_express_tph_completer_flags
{
    NONE         = 0,
    TPH          = BIT_0,
    EXTENDED_TPH = BIT_1
};

DEFINE_FLAGS(PciExpressTphCompleterFlags, pci_express_tph_completer_flags); // TEST: NO



inline const char8* flagToString(PciExpressTphCompleterFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressTphCompleterFlag::NONE:         return "NONE";
        case PciExpressTphCompleterFlag::TPH:          return "TPH";
        case PciExpressTphCompleterFlag::EXTENDED_TPH: return "EXTENDED_TPH";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressTphCompleterFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (pci_express_tph_completer_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressTphCompleterFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[34];

    FLAGS_TO_STRING(res, flags.flags, PciExpressTphCompleterFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressTphCompleterFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[41];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressTphCompleterFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHCOMPLETERFLAGS_H
