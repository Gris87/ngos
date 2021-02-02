#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEATTRIBUTES_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEATTRIBUTES_H



#include <com/ngos/shared/common/ngos/types.h>



struct DmiMemoryDeviceAttributes
{
    union
    {
        struct
        {
            bad_uint8 rank:       4;
            bad_uint8 __reserved: 4;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEATTRIBUTES_H
