#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H



#include <common/src/bits64/log/log.h>
#include <macro/constants.h>



struct DmiBiosRomSize
{
    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (value + 1) * 64 * KB;
    }



    u8 value;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
