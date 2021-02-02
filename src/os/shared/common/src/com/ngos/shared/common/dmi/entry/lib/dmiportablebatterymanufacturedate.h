#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H



#include <com/ngos/shared/common/dmi/entry/lib/dmivoltageprobelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmivoltageprobestatus.h>



struct DmiPortableBatteryManufactureDate
{
    bad_uint16 yearReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return year + 1980;
    }



    union
    {
        struct
        {
            bad_uint16 date:  5;
            bad_uint16 month: 4;
            bad_uint16 year:  7;
        };

        bad_uint16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
