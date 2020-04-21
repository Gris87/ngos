#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H



#include <common/src/bits64/dmi/entry/lib/dmimemorydevicesizegranularity.h>
#include <common/src/bits64/log/log.h>
#include <macro/constants.h>



#define DMI_MEMORY_DEVICE_SIZE_NOT_INSTALLED  0x0000
#define DMI_MEMORY_DEVICE_SIZE_UNKNOWN        0xFFFF
#define DMI_MEMORY_DEVICE_SIZE_NEED_TO_EXTEND 0x7FFF



struct DmiMemoryDeviceSize
{
    u64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch ((DmiMemoryDeviceSizeGranularity)granularity)
        {
            case DmiMemoryDeviceSizeGranularity::_1_MEGABYTE: return (u64)value * MB;
            case DmiMemoryDeviceSizeGranularity::_1_KILOBYTE: return (u64)value * KB;

            default:
            {
                COMMON_LF(("Unknown memory device size granularity %s, %s:%u", enumToFullString((DmiMemoryDeviceSizeGranularity)granularity), __FILE__, __LINE__));

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
            u16 granularity: 1; // TODO: Use enum DmiMemoryDeviceSizeGranularity
        };

        u16 value16;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H
