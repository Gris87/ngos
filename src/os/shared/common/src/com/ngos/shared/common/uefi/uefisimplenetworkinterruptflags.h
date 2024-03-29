#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERRUPTFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERRUPTFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 uefi_simple_network_interrupt_flags;

enum class UefiSimpleNetworkInterruptFlag: uefi_simple_network_interrupt_flags
{
    NONE     = 0,
    RECEIVE  = BIT_0,
    TRANSMIT = BIT_1,
    COMMAND  = BIT_2,
    SOFTWARE = BIT_3
};

DEFINE_FLAGS(UefiSimpleNetworkInterruptFlags, uefi_simple_network_interrupt_flags); // TEST: NO



inline const char8* flagToString(UefiSimpleNetworkInterruptFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case UefiSimpleNetworkInterruptFlag::NONE:     return "NONE";
        case UefiSimpleNetworkInterruptFlag::RECEIVE:  return "RECEIVE";
        case UefiSimpleNetworkInterruptFlag::TRANSMIT: return "TRANSMIT";
        case UefiSimpleNetworkInterruptFlag::COMMAND:  return "COMMAND";
        case UefiSimpleNetworkInterruptFlag::SOFTWARE: return "SOFTWARE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(UefiSimpleNetworkInterruptFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[22];

    sprintf(res, "0x%08X (%s)", (uefi_simple_network_interrupt_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiSimpleNetworkInterruptFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[55];

    FLAGS_TO_STRING(res, flags.flags, UefiSimpleNetworkInterruptFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiSimpleNetworkInterruptFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[68];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiSimpleNetworkInterruptFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERRUPTFLAGS_H
