#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISTYPEANDLOCKED_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISTYPEANDLOCKED_H



#include <com/ngos/shared/common/dmi/entry/lib/dmichassistype.h>



struct DmiChassisTypeAndLocked
{
    union
    {
        struct
        {
            bad_uint8 type:   7; // TODO: Use enum DmiChassisType
            bad_uint8 locked: 1;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISTYPEANDLOCKED_H
