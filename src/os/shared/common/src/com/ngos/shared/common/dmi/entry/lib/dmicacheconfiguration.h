#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H



#include <common/src/bits64/dmi/entry/lib/dmicachelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheoperationalmode.h>



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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
