#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIFUNCTIONNUMBERANDDEVICENUMBER_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIFUNCTIONNUMBERANDDEVICENUMBER_H



#include <com/ngos/shared/common/ngos/types.h>



struct DmiFunctionNumberAndDeviceNumber
{
    union
    {
        struct
        {
            u8 functionNumber: 3;
            u8 deviceNumber:   5;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIFUNCTIONNUMBERANDDEVICENUMBER_H
