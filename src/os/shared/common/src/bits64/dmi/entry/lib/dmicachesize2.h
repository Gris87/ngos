#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE2_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE2_H



#include <common/src/bits64/dmi/entry/lib/dmicachesizegranularity.h>



struct DmiCacheSize2
{
    union
    {
        struct
        {
            u32 value:       31;
            u32 granularity: 1; // TODO: Use enum DmiCacheSizeGranularity
        };

        u32 value32;
    };

    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch ((DmiCacheSizeGranularity)granularity)
        {
            case DmiCacheSizeGranularity::_1_KILOBYTE:   return (u64)value << 10;
            case DmiCacheSizeGranularity::_64_KILOBYTES: return (u64)value << 16;

            default:
            {
                COMMON_LF(("Unknown cache size granularity %s", enumToFullString((DmiCacheSizeGranularity)granularity)));

                return 0;
            }
            break;
        }



        return value;
    }
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE2_H
