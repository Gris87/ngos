#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H



#include <com/ngos/shared/common/dmi/entry/lib/dmivoltageprobelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmivoltageprobestatus.h>



struct DmiPortableBatteryManufactureDate
{
    u16 yearReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return year + 1980;
    }



    union
    {
        struct
        {
            u16 date:  5;
            u16 month: 4;
            u16 year:  7;
        };

        u16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
