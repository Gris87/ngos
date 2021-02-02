#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H



#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplyinputvoltagerangeswitch.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplystatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplytype.h>



struct DmiSystemPowerSupplyCharacteristics
{
    union
    {
        struct
        {
            bad_uint16 hotReplaceable:          1;
            bad_uint16 present:                 1;
            bad_uint16 unplugged:               1;
            bad_uint16 inputVoltageRangeSwitch: 4; // TODO: Use enum DmiSystemPowerSupplyInputVoltageRangeSwitch
            bad_uint16 status:                  3; // TODO: Use enum DmiSystemPowerSupplyStatus
            bad_uint16 type:                    4; // TODO: Use enum DmiSystemPowerSupplyType
            bad_uint16 __reserved:              2;
        };

        bad_uint16 value16;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYCHARACTERISTICS_H
