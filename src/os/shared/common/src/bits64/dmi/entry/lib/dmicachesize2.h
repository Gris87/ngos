#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE2_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE2_H



#include <ngos/types.h>



struct DmiCacheSize2
{
    u32 granularity: 1;
    u32 value:       31;

    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return granularity ? ((u64)value << 16) : ((u64)value << 10);
    }
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE2_H
