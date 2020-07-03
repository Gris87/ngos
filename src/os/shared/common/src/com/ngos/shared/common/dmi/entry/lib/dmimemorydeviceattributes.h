#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEATTRIBUTES_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEATTRIBUTES_H



#include <com/ngos/shared/common/ngos/types.h>



struct DmiMemoryDeviceAttributes
{
    union
    {
        struct
        {
            u8 rank:       4;
            u8 __reserved: 4;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEATTRIBUTES_H
