#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIOUTOFBANDREMOTEACCESSCONNECTIONFLAGS_H                                                                                                                   // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIOUTOFBANDREMOTEACCESSCONNECTIONFLAGS_H                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/bits/flags.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/bits/macros.h>                                                                                                                                                          // Colorize: green
#include <com/ngos/shared/common/ngos/linkage.h>                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
#include <com/ngos/shared/common/string/string.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
typedef u8 dmi_out_of_band_remote_access_connection_flags;                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class DmiOutOfBandRemoteAccessConnectionFlag: dmi_out_of_band_remote_access_connection_flags                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE     = 0,                                                                                                                                                                                        // Colorize: green
    INBOUND  = BIT_0,                                                                                                                                                                              // Colorize: green
    OUTBOUND = BIT_1                                                                                                                                                                               // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DEFINE_FLAGS(DmiOutOfBandRemoteAccessConnectionFlags, dmi_out_of_band_remote_access_connection_flags); // TEST: NO                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToString(DmiOutOfBandRemoteAccessConnectionFlag flag) // TEST: NO                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (flag)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiOutOfBandRemoteAccessConnectionFlag::NONE:     return "NONE";                                                                                                                            // Colorize: green
        case DmiOutOfBandRemoteAccessConnectionFlag::INBOUND:  return "INBOUND";                                                                                                                         // Colorize: green
        case DmiOutOfBandRemoteAccessConnectionFlag::OUTBOUND: return "OUTBOUND";                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagToFullString(DmiOutOfBandRemoteAccessConnectionFlag flag) // TEST: NO                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[16];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (dmi_out_of_band_remote_access_connection_flags)flag, flagToString(flag));                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToString(const DmiOutOfBandRemoteAccessConnectionFlags &flags) // TEST: NO                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[34];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_STRING(res, flags.flags, DmiOutOfBandRemoteAccessConnectionFlag);                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* flagsToFullString(const DmiOutOfBandRemoteAccessConnectionFlags &flags) // TEST: NO                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[41];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    FLAGS_TO_FULL_STRING(res, flags.flags, DmiOutOfBandRemoteAccessConnectionFlag, "0x%02X");                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIOUTOFBANDREMOTEACCESSCONNECTIONFLAGS_H                                                                                                                 // Colorize: green
