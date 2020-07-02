#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H



#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmivoltageprobelocation.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmivoltageprobestatus.h>



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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
