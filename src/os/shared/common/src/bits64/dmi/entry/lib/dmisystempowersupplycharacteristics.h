#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H



#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplyinputvoltagerangeswitch.h>
#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplystatus.h>
#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplytype.h>



struct DmiSystemPowerSupplyCharacteristics
{
    u16 hotReplaceable:          1;
    u16 present:                 1;
    u16 unplugged:               1;
    u16 inputVoltageRangeSwitch: 4; // TODO: Use enum DmiSystemPowerSupplyInputVoltageRangeSwitch
    u16 status:                  3; // TODO: Use enum DmiSystemPowerSupplyStatus
    u16 type:                    4; // TODO: Use enum DmiSystemPowerSupplyType
    u16 __reserved:              2;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H
