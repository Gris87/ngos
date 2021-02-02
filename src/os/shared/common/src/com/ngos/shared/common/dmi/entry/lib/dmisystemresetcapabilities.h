#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H



#include <com/ngos/shared/common/dmi/entry/lib/dmisystemresetbootoption.h>



struct DmiSystemResetCapabilities
{
    union
    {
        struct
        {
            bad_uint8 enabled:           1;
            bad_uint8 bootOption:        2; // TODO: Use enum DmiSystemResetBootOption
            bad_uint8 bootOptionOnLimit: 2; // TODO: Use enum DmiSystemResetBootOption
            bad_uint8 watchdogEnabled:   1;
            bad_uint8 __reserved:        2;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H
