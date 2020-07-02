#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H



#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplyinputvoltagerangeswitch.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplystatus.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplytype.h>



struct DmiSystemPowerSupplyCharacteristics
{
    union
    {
        struct
        {
            u16 hotReplaceable:          1;
            u16 present:                 1;
            u16 unplugged:               1;
            u16 inputVoltageRangeSwitch: 4; // TODO: Use enum DmiSystemPowerSupplyInputVoltageRangeSwitch
            u16 status:                  3; // TODO: Use enum DmiSystemPowerSupplyStatus
            u16 type:                    4; // TODO: Use enum DmiSystemPowerSupplyType
            u16 __reserved:              2;
        };

        u16 value16;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H
