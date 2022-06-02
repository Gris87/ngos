#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H



#include <com/ngos/shared/common/dmi/entry/lib/dmicachelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheoperationalmode.h>



struct DmiCacheConfiguration
{
    u16 levelReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return level + 1;
    }



    union
    {
        struct
        {
            u16 level:           3;
            u16 socketed:        1;
            u16 __reserved:      1;
            u16 location:        2; // TODO: Use enum DmiCacheLocation
            u16 enabled:         1;
            u16 operationalMode: 2; // TODO: Use enum DmiCacheOperationalMode
            u16 __reserved2:     6;
        };

        u16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
