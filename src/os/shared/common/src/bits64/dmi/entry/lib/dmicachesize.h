#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE_H



#include <ngos/types.h>



struct DmiCacheSize
{
    u16 granularity: 1; // TODO: Use enum
    u16 value:       15;

    u32 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return granularity ? (value << 16) : (value << 10);
    }
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESIZE_H
