#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicachesizegranularity.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



struct DmiCacheSize
{
    u32 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch ((DmiCacheSizeGranularity)granularity)
        {
            case DmiCacheSizeGranularity::_1_KILOBYTE:   return (u32)value * KB;
            case DmiCacheSizeGranularity::_64_KILOBYTES: return (u32)value * 64 * KB;

            default:
            {
                COMMON_LF(("Unknown cache size granularity %s, %s:%u", enumToFullString((DmiCacheSizeGranularity)granularity), __FILE__, __LINE__));

                return 0;
            }
            break;
        }



        return value;
    }



    union
    {
        struct
        {
            u16 value:       15;
            u16 granularity: 1; // TODO: Use enum DmiCacheSizeGranularity
        };

        u16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H
