#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIFUNCTIONNUMBERANDDEVICENUMBER_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIFUNCTIONNUMBERANDDEVICENUMBER_H



#include <com/ngos/shared/common/ngos/types.h>



struct DmiFunctionNumberAndDeviceNumber
{
    union
    {
        struct
        {
            bad_uint8 functionNumber: 3;
            bad_uint8 deviceNumber:   5;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIFUNCTIONNUMBERANDDEVICENUMBER_H
