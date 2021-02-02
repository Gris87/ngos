#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H



#include <com/ngos/shared/common/dmi/entry/lib/dmicachelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheoperationalmode.h>



struct DmiCacheConfiguration
{
    bad_uint16 levelReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return level + 1;
    }



    union
    {
        struct
        {
            bad_uint16 level:           3;
            bad_uint16 socketed:        1;
            bad_uint16 __reserved:      1;
            bad_uint16 location:        2; // TODO: Use enum DmiCacheLocation
            bad_uint16 enabled:         1;
            bad_uint16 operationalMode: 2; // TODO: Use enum DmiCacheOperationalMode
            bad_uint16 __reserved2:     6;
        };

        bad_uint16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
