#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H



#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmicachesizegranularity.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/macro/constants.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H
