#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISTYPEANDLOCKED_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISTYPEANDLOCKED_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmichassistype.h>



struct DmiChassisTypeAndLocked
{
    union
    {
        struct
        {
            u8 type:   7; // TODO: Use enum DmiChassisType
            u8 locked: 1;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISTYPEANDLOCKED_H
