#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERRUPTFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERRUPTFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>
#endif



typedef u32 uefi_simple_network_interrupt_flags;

enum class UefiSimpleNetworkInterruptFlag: uefi_simple_network_interrupt_flags
{
    NONE     = 0,
    RECEIVE  = (1ULL << 0),
    TRANSMIT = (1ULL << 1),
    COMMAND  = (1ULL << 2),
    SOFTWARE = (1ULL << 3)
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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



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



#endif



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKINTERRUPTFLAGS_H
