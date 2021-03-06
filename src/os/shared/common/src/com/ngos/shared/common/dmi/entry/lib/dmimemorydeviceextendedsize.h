#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H



#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



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
            u32 value:      31;
            u32 __reserved: 1;
        };

        u32 value32;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H
