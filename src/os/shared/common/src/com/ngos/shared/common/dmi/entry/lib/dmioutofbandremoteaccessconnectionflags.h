#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIOUTOFBANDREMOTEACCESSCONNECTIONFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIOUTOFBANDREMOTEACCESSCONNECTIONFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 dmi_out_of_band_remote_access_connection_flags;

enum class DmiOutOfBandRemoteAccessConnectionFlag: dmi_out_of_band_remote_access_connection_flags
{
    NONE     = 0,
    INBOUND  = (1ULL << 0),
    OUTBOUND = (1ULL << 1)
};

DEFINE_FLAGS(DmiOutOfBandRemoteAccessConnectionFlags, dmi_out_of_band_remote_access_connection_flags); // TEST: NO



inline const char8* flagToString(DmiOutOfBandRemoteAccessConnectionFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiOutOfBandRemoteAccessConnectionFlag::NONE:     return "NONE";
        case DmiOutOfBandRemoteAccessConnectionFlag::INBOUND:  return "INBOUND";
        case DmiOutOfBandRemoteAccessConnectionFlag::OUTBOUND: return "OUTBOUND";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiOutOfBandRemoteAccessConnectionFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[16];

    sprintf(res, "0x%02X (%s)", (dmi_out_of_band_remote_access_connection_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiOutOfBandRemoteAccessConnectionFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[34];

    FLAGS_TO_STRING(res, flags.flags, DmiOutOfBandRemoteAccessConnectionFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiOutOfBandRemoteAccessConnectionFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[41];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiOutOfBandRemoteAccessConnectionFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIOUTOFBANDREMOTEACCESSCONNECTIONFLAGS_H
