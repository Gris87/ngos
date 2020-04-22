#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H



#include <common/src/bits64/log/log.h>
#include <macro/constants.h>



struct DmiMemoryDeviceExtendedSize
{
    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return (u64)value * MB;
    }



    union
    {
        struct
        {
            u32 value:      15;
            u32 __reserved: 1;
        };

        u32 value32;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H
