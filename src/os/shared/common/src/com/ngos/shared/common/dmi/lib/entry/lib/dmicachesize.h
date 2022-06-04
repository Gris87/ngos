#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H                                                                                                                                              // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicachesizegranularity.h>                                                                                                                            // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/macro/constants.h>                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiCacheSize                                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    inline good_U32 size() const                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        // COMMON_LT(("")); // Commented to avoid too frequent logs                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        switch (granularity)                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            case DmiCacheSizeGranularity::_1_KILOBYTE:   return static_cast<good_U32>(value) * KB;                                                                                                       // Colorize: green
            case DmiCacheSizeGranularity::_64_KILOBYTES: return static_cast<good_U32>(value) * 64 * KB;                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            default:                                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                COMMON_LF(("Unknown cache size granularity %s, %s:%u", enumToFullString(granularity), __FILE__, __LINE__));                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return 0;                                                                                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return value;                                                                                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    union                                                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        struct                                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            u16                     value:       15;                                                                                                                                                     // Colorize: green
            DmiCacheSizeGranularity granularity: 1;                                                                                                                                                      // Colorize: green
        };                                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        u16 value16;                                                                                                                                                                                     // Colorize: green
    };                                                                                                                                                                                                   // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H                                                                                                                                            // Colorize: green
