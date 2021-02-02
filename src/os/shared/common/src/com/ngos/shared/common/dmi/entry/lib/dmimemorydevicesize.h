#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H



#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicesizegranularity.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/constants.h>



struct DmiMemoryDeviceSize
{
    bad_uint64 size()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        switch ((DmiMemoryDeviceSizeGranularity)granularity)
        {
            case DmiMemoryDeviceSizeGranularity::_1_MEGABYTE: return (bad_uint64)value * MB;
            case DmiMemoryDeviceSizeGranularity::_1_KILOBYTE: return (bad_uint64)value * KB;

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
            bad_uint16 value:       15;
            bad_uint16 granularity: 1; // TODO: Use enum DmiMemoryDeviceSizeGranularity
        };

        bad_uint16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H
