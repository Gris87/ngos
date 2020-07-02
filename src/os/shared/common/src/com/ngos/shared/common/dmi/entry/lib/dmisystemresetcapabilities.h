#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H



#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmisystemresetbootoption.h>



struct DmiSystemResetCapabilities
{
    union
    {
        struct
        {
            u8 enabled:           1;
            u8 bootOption:        2; // TODO: Use enum DmiSystemResetBootOption
            u8 bootOptionOnLimit: 2; // TODO: Use enum DmiSystemResetBootOption
            u8 watchdogEnabled:   1;
            u8 __reserved:        2;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMRESETCAPABILITIES_H
