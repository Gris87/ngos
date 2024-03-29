#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKRECEIVEFILTERFLAGS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKRECEIVEFILTERFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 uefi_simple_network_receive_filter_flags;

enum class UefiSimpleNetworkReceiveFilterFlag: uefi_simple_network_receive_filter_flags
{
    NONE                  = 0,
    UNICAST               = BIT_0,
    MULTICAST             = BIT_1,
    BROADCAST             = BIT_2,
    PROMISCUOUS           = BIT_3,
    PROMISCUOUS_MULTICAST = BIT_4
};

DEFINE_FLAGS(UefiSimpleNetworkReceiveFilterFlags, uefi_simple_network_receive_filter_flags); // TEST: NO



inline const char8* flagToString(UefiSimpleNetworkReceiveFilterFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case UefiSimpleNetworkReceiveFilterFlag::NONE:                  return "NONE";
        case UefiSimpleNetworkReceiveFilterFlag::UNICAST:               return "UNICAST";
        case UefiSimpleNetworkReceiveFilterFlag::MULTICAST:             return "MULTICAST";
        case UefiSimpleNetworkReceiveFilterFlag::BROADCAST:             return "BROADCAST";
        case UefiSimpleNetworkReceiveFilterFlag::PROMISCUOUS:           return "PROMISCUOUS";
        case UefiSimpleNetworkReceiveFilterFlag::PROMISCUOUS_MULTICAST: return "PROMISCUOUS_MULTICAST";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(UefiSimpleNetworkReceiveFilterFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%08X (%s)", (uefi_simple_network_receive_filter_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const UefiSimpleNetworkReceiveFilterFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[85];

    FLAGS_TO_STRING(res, flags.flags, UefiSimpleNetworkReceiveFilterFlag);

    return res;
}



inline const char8* flagsToFullString(const UefiSimpleNetworkReceiveFilterFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[98];

    FLAGS_TO_FULL_STRING(res, flags.flags, UefiSimpleNetworkReceiveFilterFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLENETWORKRECEIVEFILTERFLAGS_H
